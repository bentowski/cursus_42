
#include "minirt.h"

void  my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

t_triade cams_orientation(t_triade ray, t_triade dir)
{
  t_triade ret;
  double test;
  t_triade x;
  t_triade y;
  t_triade z;

  y = (t_triade){0, 1, 0};
  z = get_norme(dir);
  if (dir.x == 0 && dir.z == 0 && (dir.y == 1 || dir.y == -1))
    x = (t_triade){1, 0, 0};
  else
    x = crossprod(y, z);
  y = crossprod(z, x);
  ret.x = scale(&ray, &x);
  ret.y = scale(&ray, &y);
  ret.z = scale(&ray, &z);
  test = sqrt(pow(ret.x, 2) + pow(ret.y, 2) + pow(ret.z, 2));
  ret.x = ret.x / test;
  ret.y = ret.y / test;
  ret.z = ret.z / test;
  return (ret);
}

void drop_ray(t_env *env)
{
  double x;
  double y;
  t_triade ray;
  t_map *map;

  map = env->map
  y = 0;
	while (y < map->resolution->win_height - 1)
  {
		x = 0;
		while (x < map->resolution->win_width - 1)
		{
      ray.x = (x - map->resolution->win_width / 2.0) * map->resolution->win_width / map->resolution->win_height;
      ray.y = (-y + map->resolution->win_height / 2.0) * map->resolution->win_width / map->resolution->win_height;
      ray.z = 1 / (tan(M_PI / 180.0 * map->cams->fov / 2)) * map->resolution->win_width / 2;
      ray.z = ray.z * map->cams->base->vdir->z;
      ray = cams_orientation(ray, *map->cams->base->vdir);
      my_mlx_pixel_put(&env->img, x, y, ft_raytracing(map, ray));
      x += 0.5;
    }
    y += 1;
	}
}

int   map_init(t_map **map)
{
  t_map *ptrmap;

  if ((ptrmap = ft_calloc(1, sizeof(t_map))))
    if ((ptrmap->ambiant = ft_calloc(1, sizeof(t_ambiant))))
      if ((ptrmap->resolution = ft_calloc(1, sizeof(t_resolution))))
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
  printf("%s\n%s", "Error", "");
  return (-1);
}

int main(int argc, char **argv)
{
  t_env env;

  if (argc >= 2)
  {
    env.rtfile = argv[1]
    if (map_init(&env.map) != -1)
      if (ft_parse(&map, env.rtfile) != 1)
      {
        env.mlx = mlx_init();
    		env.mlx_win = mlx_new_window(env.mlx, env.map->resolution->win_width, env.map->resolution->win_height, "Hello world");
    		env.img.img = mlx_new_image(env.mlx, env.map->resolution->win_width, env.map->resolution->win_height);
    		env.img.addr = mlx_get_data_addr(env.img.img, &env.img.bits_per_pixel, &env.img.line_length, &env.img.endian);
        drop_ray(&env);
    		mlx_put_image_to_window(env.mlx, env.mlx_win, env.img.img, 0, 0);
        // mlx_key_hook(env.mlx_win, gestion_win, &env);
        mlx_loop(env.mlx);
        // ft_clear(map);
        // return (1);
      }
      ft_clear(env.map);
      return (-1);
  }
  printf("%s\n%s", "Error", "missing or too much arguments");
  return (-1);
}
