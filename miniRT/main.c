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
  void *mlx;
  void *mlx_win;
  t_data img;
  t_map *map;
	double x;
	double y;
  t_triade ray;

  if (argc == 2)
	{
    if ((map_init(&map)) == -1)
      return (-1);
		if (ft_parse(&map, argv[1]) != -1)
		{
  		mlx = mlx_init();
  		mlx_win = mlx_new_window(mlx, map->resolution->win_width, map->resolution->win_height, "Hello world");
  		img.img = mlx_new_image(mlx, map->resolution->win_width, map->resolution->win_height);
  		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
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
          my_mlx_pixel_put(&img, x, y, ft_raytracing(map, get_norme(ray)));
  			}
  		}
  		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
      ft_clear(map);
      system("leaks a.out");
      printf("%s\n", "FIN");
      mlx_loop(mlx);
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
