#include "minirt.h"

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
  return (-1);
}

t_triade cams_orientation(t_triade ray, t_triade dir)
{
  t_triade ret;
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
  return (ret);
}

int gestion_win(int keycode, t_env *env)
{
  t_map *map;
  double x;
	double y;
  t_triade ray;

  if (keycode == R_KEY)
  {
    ft_clear(env->map);
    if ((map_init(&map)) == -1)
      return (-1);
    if (ft_parse(&map, env->rtfile) != -1)
    {
      ray.z = (map->resolution->win_width / (2 * tan((map->cams->fov * M_PI / 180) / 2)));
      ray.z = ray.z * map->cams->base->vdir->z;
      y = 0;
      while (y < map->resolution->win_height - 1)
      {
        ray.y = (-y + map->resolution->win_height / 2.0) * map->resolution->win_width / map->resolution->win_height;
        x = 0;
        while (x < map->resolution->win_width - 1)
        {
          ray.x = (-x + map->resolution->win_width / 2.0) * map->resolution->win_width / map->resolution->win_height;
          ray = cams_orientation(ray, *map->cams->base->vdir);
          my_mlx_pixel_put(&env->img, x, y, ft_raytracing(map, get_norme(ray)));
          x += 0.5;
        }
        y += 1;
      }
      mlx_clear_window(env->mlx, env->mlx_win);
      mlx_put_image_to_window(env->mlx, env->mlx_win, env->img.img, 0, 0);
      env->map = map;
    }
  }
  if (keycode == N_KEY)
  {
    map = env->map;
    if (env->map->cams->next->next != NULL)
    {
      map->cams = map->cams->next;
      ray.z = map->resolution->win_width;
      ray.z = ray.z / (2 * tan((map->cams->fov * M_PI / 180) / 2));
      ray.z = ray.z * map->cams->base->vdir->z;
      y = 0;
  		while (y < map->resolution->win_height - 1)
      {
        ray.y = (-y + map->resolution->win_height / 2.0) * map->resolution->win_width / map->resolution->win_height;
  			x = 0;
  			while (x < map->resolution->win_width - 1)
  			{
          ray.x = (-x + map->resolution->win_width / 2.0) * map->resolution->win_width / map->resolution->win_height;
          ray = cams_orientation(ray, *map->cams->base->vdir);
          my_mlx_pixel_put(&env->img, x, y, ft_raytracing(map, get_norme(ray)));
          x += 0.5;
        }
        y += 1;
  		}
      mlx_clear_window(env->mlx, env->mlx_win);
      mlx_put_image_to_window(env->mlx, env->mlx_win, env->img.img, 0, 0);
    }
  }
  if (keycode == P_KEY)
  {
    map = env->map;
    if (map->cams)
      if (map->cams->previous != NULL)
      {
        map->cams = map->cams->previous;
        ray.z = (map->resolution->win_width / (2 * tan((map->cams->fov * M_PI / 180) / 2)));
        ray.z = ray.z * map->cams->base->vdir->z;
        y = 0;
    		while (y < map->resolution->win_height - 1)
        {
          ray.y = (-y + map->resolution->win_height / 2.0) * map->resolution->win_width / map->resolution->win_height;
    			x = 0;
    			while (x < map->resolution->win_width - 1)
    			{
            ray.x = (-x + map->resolution->win_width / 2.0) * map->resolution->win_width / map->resolution->win_height;
            ray = cams_orientation(ray, *map->cams->base->vdir);
            my_mlx_pixel_put(&env->img, x, y, ft_raytracing(map, get_norme(ray)));
            x += 0.5;
          }
          y += 1;
    		}
        mlx_clear_window(env->mlx, env->mlx_win);
        mlx_put_image_to_window(env->mlx, env->mlx_win, env->img.img, 0, 0);
      }
  }
  if (keycode == ESC_KEY)
  {
    mlx_destroy_window(env->mlx, env->mlx_win);
    free(env->mlx);
    free(env->img.img);
    ft_clear(env->map);
    system("leaks a.out");
    exit(EXIT_SUCCESS);
  }
  return (1);
}

void drop_ray(t_env *env)
{
  double x;
  double y;
  t_triade ray;
  t_map *map;

  map = env->map;
  ray.z = 1 / (tan(M_PI / 180.0 * map->cams->fov / 2)) * map->resolution->win_width / 2;
  ray.z = ray.z * map->cams->base->vdir->z;
  y = 0;
  while (y < map->resolution->win_height - 1)
  {
    ray.y = (-y + map->resolution->win_height / 2.0) * map->resolution->win_width / map->resolution->win_height;
    x = 0;
    while (x < map->resolution->win_width - 1)
    {
      ray.x = (-x + map->resolution->win_width / 2.0) * map->resolution->win_width / map->resolution->win_height;
      ray = cams_orientation(ray, *map->cams->base->vdir);
      my_mlx_pixel_put(&env->img, x, y, ft_raytracing(map, get_norme(ray)));
      x += 1;
    }
    y += 1;
  }
}

int		close_wdw(t_env *env)
{
	mlx_destroy_window(env->mlx, env->mlx_win);
	mlx_destroy_display(env->mlx);
	free(env->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int   main(int argc, char **argv)
{
  t_env env;

  if (argc >= 2)
	{
    env.rtfile = argv[1];
    env.mlx = mlx_init();
    if ((map_init(&env.map)) == -1)
      return (-1);
    mlx_get_screen_size(env.mlx, &env.map->resolution->width_max, &env.map->resolution->height_max);
		if (ft_parse(&env.map, argv[1]) != -1)
    {
  		env.mlx_win = mlx_new_window(env.mlx, env.map->resolution->win_width, env.map->resolution->win_height, "Hello world");
  		env.img.img = mlx_new_image(env.mlx, env.map->resolution->win_width, env.map->resolution->win_height);
  		env.img.addr = mlx_get_data_addr(env.img.img, &env.img.bits_per_pixel, &env.img.line_length, &env.img.endian);
      drop_ray(&env);
  		mlx_put_image_to_window(env.mlx, env.mlx_win, env.img.img, 0, 0);
      saving(&env);
      mlx_key_hook(env.mlx_win, gestion_win, &env);
      mlx_hook(env.mlx_win, DESTROY, STRUCTMASK, close_wdw, &env);
      mlx_loop(env.mlx);
    }
    ft_clear(env.map);
    return (-1);
	}
	printf("%s\n%s", "Error", "missing or too much arguments");
	return (-1);
}
