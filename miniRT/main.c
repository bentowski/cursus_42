#include "minirt.h"

void  my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = (char *)s;
	while (n > 0)
	{
		p[n - 1] = 0;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	int		lenght;

	lenght = count * size;
	if (!(ptr = malloc(lenght)))
		return (NULL);
	ft_bzero(ptr, lenght);
	return (ptr);
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
  return (-1);
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
      y = -1;
  		while (y++ < map->resolution->win_height - 1)
  		{
        ray.y = -(y - (map->resolution->win_height / 2));
  			x = -1;
  			while (x++ < map->resolution->win_width - 1)
  			{
          ray.x = (x - (map->resolution->win_width / 2));
          my_mlx_pixel_put(&env->img, x, y, ft_raytracing(map, get_norme(ray)));
  			}
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
      y = -1;
      ray.z = map->resolution->win_width;
      ray.z = ray.z / (2 * tan((map->cams->fov * M_PI / 180) / 2));
      ray.z = ray.z * map->cams->base->vdir->z;
      while (y++ < map->resolution->win_height - 1)
      {
        ray.y = -(y - (map->resolution->win_height / 2));
        x = -1;
        while (x++ < map->resolution->win_width - 1)
        {
          ray.x = (x - (map->resolution->win_width / 2));
          my_mlx_pixel_put(&env->img, x, y, ft_raytracing(map, get_norme(ray)));
        }
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
        y = -1;
        while (y++ < map->resolution->win_height - 1)
        {
          ray.y = -(y - (map->resolution->win_height / 2));
          x = -1;
          while (x++ < map->resolution->win_width - 1)
          {
            ray.x = (x - (map->resolution->win_width / 2));
            my_mlx_pixel_put(&env->img, x, y, ft_raytracing(map, get_norme(ray)));
          }
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

int   main(int argc, char **argv)
{
  t_env env;
  t_map *map;
	double x;
	double y;
  t_triade ray;

  if (argc >= 2)
	{
    if ((map_init(&map)) == -1)
      return (-1);
		if (ft_parse(&map, argv[1]) != -1)
    {
  		env.mlx = mlx_init();
  		env.mlx_win = mlx_new_window(env.mlx, map->resolution->win_width, map->resolution->win_height, "Hello world");
  		env.img.img = mlx_new_image(env.mlx, map->resolution->win_width, map->resolution->win_height);
  		env.img.addr = mlx_get_data_addr(env.img.img, &env.img.bits_per_pixel, &env.img.line_length, &env.img.endian);
      ray.z = 1 / (tan(M_PI / 180.0 * map->cams->fov / 2)) * map->resolution->win_width / 2;
      ray.z = ray.z * map->cams->base->vdir->z;
      y = -1;
  		while (y++ < map->resolution->win_height - 1)
      {
        ray.y = (-y + map->resolution->win_height / 2.0) * map->resolution->win_width / map->resolution->win_height;
  			x = -1;
  			while (x++ < map->resolution->win_width - 1)
  			{
          ray.x = (x - map->resolution->win_width / 2.0) * map->resolution->win_width / map->resolution->win_height;
          my_mlx_pixel_put(&env.img, x, y, ft_raytracing(map, get_norme(ray)));
  			}
  		}
  		mlx_put_image_to_window(env.mlx, env.mlx_win, env.img.img, 0, 0);
      env.rtfile = argv[1];
      env.map = map;
      mlx_key_hook(env.mlx_win, gestion_win, &env);
      mlx_loop(env.mlx);
      ft_clear(map);
      return (1);
    }
    ft_clear(map);
    system("leaks a.out");
    return (-1);
	}
	printf("%s\n%s", "Error", "missing or too much arguments");
  system("leaks a.out");
	return (-1);
}
