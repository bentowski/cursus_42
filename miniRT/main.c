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
  while (y++ < map->res->height - 1)
  {
    x = -1;
    while (x++ < map->res->width - 1)
    {
      ray.z = 1 / (tan(M_PI / 180.0 * map->cams->fov / 2)) * map->res->width / 2;
      ray.y = (-y + map->res->height / 2.0) * map->res->width / map->res->height;
      ray.x = (-x + map->res->width / 2.0) * map->res->width / map->res->height;
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

void start(t_env *env, int opt)
{
  env->mlx = mlx_init();
  if ((map_init(&env->map)) == -1)
    return;
  mlx_get_screen_size(env->mlx, &env->map->res->w_max, &env->map->res->h_max);
  if (ft_parse(&env->map, env->rtfile) != -1)
  {
    if (env->map->res->width <= 0 || env->map->res->height <= 0 ||
      env->map->ambiant->lumens == 0)
    {
      printf("%s\n%s\n", "Error", "Missing resolution or ambiant light");
      return;
    }
    env->mlx_win = mlx_new_window(env->mlx, env->map->res->width,
      env->map->res->height, "Hello world");
    env->img.img = mlx_new_image(env->mlx, env->map->res->width,
      env->map->res->height);
    env->img.addr = mlx_get_data_addr(env->img.img, &env->img.bits_per_pixel,
      &env->img.line_length, &env->img.endian);
    drop_ray(env);
    if (opt == 3)
      create_bmp(env);
    mlx_gestion(env);
  }
}

int   main(int argc, char **argv)
{
  t_env env;
  char *tmp;

  if (argc == 2)
  {
    tmp = ft_substr(argv[1], (ft_strlen(argv[1]) - 3), 3);
    if (ft_strncmp(tmp, ".rt", 4) == 0)
      {
        free(tmp);
        env.rtfile = argv[1];
        start(&env, argc);
        ft_clear(env.map);
        return (-1);
      }
  }
  if (argc == 3)
    if (ft_strncmp(argv[2], "--save", 7) == 0)
    {
      env.rtfile = argv[1];
      start(&env, argc);
      ft_clear(env.map);
      return (-1);
     }
	printf("%s\n%s\n", "Error", "bad, missing or too much arguments");
	return (-1);
}
