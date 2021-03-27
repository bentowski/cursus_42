#include "minirt.h"

static t_triade cams_orientation(t_triade ray, t_triade dir)
{
  t_triade ret;
  t_triade x;
  t_triade y;
  t_triade z;

  y = (t_triade){0, 1, 0};
  z = get_norme(dir);
  if (dir.x == 0 && (dir.y == 1 || dir.y == -1) && dir.z == 0)
    x = (t_triade){1, 0, 0};
  else
    x = crossprod(y, z);
  y = crossprod(z, x);
  ret.x = scale(&ray, &x);
  ret.y = scale(&ray, &y);
  ret.z = scale(&ray, &z);
  return (ret);
}

void drop_ray(t_env *env)
{
  double x;
  double y;
  t_triade ray;
  t_map *map;

  map = env->map;
  y = -1;
  while (y++ < map->res->win_height - 1)
  {
    x = -1;
    while (x++ < map->res->win_width - 1)
    {
      ray.z = 1 / (tan(M_PI / 180.0 * map->cams->fov / 2)) * map->res->win_width / 2;
      ray.y = (-y + map->res->win_height / 2.0) * map->res->win_width / map->res->win_height;
      ray.x = (-x + map->res->win_width / 2.0) * map->res->win_width / map->res->win_height;
      ray = cams_orientation(ray, *map->cams->base->vdir);
      my_mlx_pixel_put(&env->img, x, y, ft_raytracing(map, get_norme(ray)));
    }
  }
}

int   map_init(t_map **map)
{
  t_map *ptrmap;

  if ((ptrmap = ft_calloc(1, sizeof(t_map))))
    if ((ptrmap->ambiant = ft_calloc(1, sizeof(t_ambiant))))
      if ((ptrmap->res = ft_calloc(1, sizeof(t_res))))
        if ((ptrmap->objs = ft_calloc(1, sizeof(t_objs))))
          if ((ptrmap->cams = ft_calloc(1, sizeof(t_cams))))
            if ((ptrmap->lights = ft_calloc(1, sizeof(t_lights))))
              if ((ptrmap->vnull = ft_calloc(1, sizeof(t_triade))))
              {
                ptrmap->vnull->x = 0;
                ptrmap->vnull->y = 0;
                ptrmap->vnull->z = 0;
                ptrmap->cams->previous = NULL;
                ptrmap->cams->next = NULL;
                ptrmap->objs->next = NULL;
                ptrmap->lights->next = NULL;
                *map = ptrmap;
                return (1);
              }
  ft_clear(ptrmap);
  return (-1);
}

int   main(int argc, char **argv)
{
  t_env env;

  if (argc >= 2 && argc <= 3)
	{
    env.rtfile = argv[1];
    env.mlx = mlx_init();
    if ((map_init(&env.map)) == -1)
      return (-1);
    mlx_get_screen_size(env.mlx, &env.map->res->width_max, &env.map->res->height_max);
		if (ft_parse(&env.map, env.rtfile) != -1)
    {
  		env.mlx_win = mlx_new_window(env.mlx, env.map->res->win_width, env.map->res->win_height, "Hello world");
  		env.img.img = mlx_new_image(env.mlx, env.map->res->win_width, env.map->res->win_height);
  		env.img.addr = mlx_get_data_addr(env.img.img, &env.img.bits_per_pixel, &env.img.line_length, &env.img.endian);
      drop_ray(&env);
      if (argc == 2)
        mlx_gestion(&env);
      else if (argc == 3)
        create_bmp(&env);
    }
    ft_clear(env.map);
    return (-1);
	}
	printf("%s\n%s", "Error", "missing or too much arguments");
	return (-1);
}
