#include "minirt.h"



typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
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

double intersect_plan(t_triade *ray, t_objs *ptr, t_map *map)
{
  t_triade alpha;

  alpha.x = (ptr->base->origins->x - map->cams->base->origins->x) * ptr->base->vdir->x;
  alpha.x += (ptr->base->origins->y - map->cams->base->origins->y) * ptr->base->vdir->y;
  alpha.x += (ptr->base->origins->z - map->cams->base->origins->z) * ptr->base->vdir->z;
  alpha.y = ray->x * ptr->base->vdir->x;
  alpha.y += ray->y * ptr->base->vdir->y;
  alpha.y += ray->z * ptr->base->vdir->z;
  alpha.x = alpha.x / alpha.y;
  if (alpha.x >= 0)
    return (alpha.x);
  return (-1);
}

double intersect_sphere(t_triade *ray, t_objs *ptr, t_map *map)
{
  t_triade alpha;
  t_triade polynome;

  alpha.x = 0;
  alpha.y = 0;
  polynome.x = (ray->x * ray->x) + (ray->y * ray->y) + (ray->z * ray->z);
  polynome.y = ray->x * (map->cams->base->origins->x - ptr->base->origins->x);
  polynome.y += ray->y * (map->cams->base->origins->y - ptr->base->origins->y);
  polynome.y += ray->z * (map->cams->base->origins->z - ptr->base->origins->z);
  polynome.z = pow((map->cams->base->origins->x - ptr->base->origins->x), 2);
  polynome.z += pow((map->cams->base->origins->y - ptr->base->origins->y), 2);
  polynome.z += pow((map->cams->base->origins->z - ptr->base->origins->z), 2);
  polynome.z -= (ptr->diam / 2) * (ptr->diam/ 2);
  alpha.z = ((2 * polynome.y) * (2 * polynome.y)) - 4 * polynome.x * polynome.z;
  if (alpha.z >= 0)
  {
    alpha.x = (-polynome.y - sqrt(alpha.z)) / (2 * polynome.x);
    alpha.y = (-polynome.y + sqrt(alpha.z)) / (2 * polynome.x);
    if (alpha.y < 0)
      return (-1);
    if (alpha.x > 0)
      return (alpha.x);
    return (alpha.y);
  }
  return (-1);
}

int intersect_cylinder(t_triade *ray, t_objs *ptr, t_map *map)
{
  t_triade alpha;
  t_triade polynome;

  alpha.x = (ptr->base->origins->x - map->cams->base->origins->x) * ptr->base->vdir->x;
  alpha.x += (ptr->base->origins->y - map->cams->base->origins->y) * ptr->base->vdir->y;
  alpha.x += (ptr->base->origins->z - map->cams->base->origins->z) * ptr->base->vdir->z;
  alpha.y = ray->x * ptr->base->vdir->x;
  alpha.y += ray->y * ptr->base->vdir->y;
  alpha.y += ray->z * ptr->base->vdir->z;
  alpha.z = alpha.x / alpha.y;
  polynome.x = (ray->x * ray->x) + (ray->y * ray->y) + (ray->z * ray->z);
  polynome.x = polynome.x * (alpha.z * alpha.z);
  polynome.y = (2 * alpha.z) * ((ray->x * (map->cams->base->origins->x - ptr->base->origins->x)));
  polynome.y += (2 * alpha.z) * ((ray->y * (map->cams->base->origins->y - ptr->base->origins->y)));
  polynome.y += (2 * alpha.z) * ((ray->z * (map->cams->base->origins->z - ptr->base->origins->z)));
  polynome.z = (map->cams->base->origins->x - ptr->base->origins->x) * (map->cams->base->origins->x - ptr->base->origins->x);
  polynome.z += (map->cams->base->origins->y - ptr->base->origins->y) * (map->cams->base->origins->y - ptr->base->origins->y);
  polynome.z += (map->cams->base->origins->z - ptr->base->origins->z) * (map->cams->base->origins->z - ptr->base->origins->z);
  polynome.z -= (ptr->diam / 2) * (ptr->diam/ 2);
  if ((polynome.x + polynome.y + polynome.z) <= 0)
    return (1);
  return (-1);
}


int intersect(t_map *map, t_triade *ray)
{
  t_objs *ptr;
  double t;
  t_triade p;
  t_triade normale;
  double normalisation;
  t_triade ldir;
  double intensity;
  unsigned long int ret;
  int color1;
  int color2;
  int color3;
  double angle;
  double normalisation2;

  ptr = map->objs;
  while (ptr->next)
  {
    intensity = 0;
    if (ptr->type == 1)
      if ((t = intersect_sphere(ray, ptr, map)) >= 0)
      {
        p.x = map->cams->base->origins->x + (t * ray->x);
        p.y = map->cams->base->origins->y + (t * ray->y);
        p.z = map->cams->base->origins->z + (t * ray->z);
        normale.x = p.x - ptr->base->origins->x;
        normale.y = p.y - ptr->base->origins->y;
        normale.z = p.z - ptr->base->origins->z;
        normalisation = sqrt(pow(normale.x, 2) + pow(normale.y, 2) + pow(normale.z, 2));
        normale.x = normale.x / normalisation;
        normale.y = normale.y / normalisation;
        normale.z = normale.z / normalisation;
        ldir.x = map->lights->base->origins->x - p.x;
        ldir.y = map->lights->base->origins->y - p.y;
        ldir.z = map->lights->base->origins->z - p.z;
        normalisation = sqrt(pow(ldir.x, 2) + pow(ldir.y, 2) + pow(ldir.z, 2));
        ldir.x = ldir.x / normalisation;
        ldir.y = ldir.y / normalisation;
        ldir.z = ldir.z / normalisation;
        intensity = (ldir.x * normale.x) + (ldir.y * normale.y) + (ldir.z * normale.z);
        intensity = intensity * (map->lights->lumens);
        intensity = intensity / (pow(ldir.x, 2) + pow(ldir.y, 2) + pow(ldir.z, 2));
        if (intensity < 0)
          intensity = 0;
        color1 = ptr->base->color->x * intensity;
        if (color1 > 255)
          color1 = 255;
        color2 = ptr->base->color->y * intensity;
        if (color2 > 255)
          color2 = 255;
        color3 = ptr->base->color->z * intensity;
        if (color3 > 255)
          color3 = 255;
        ret = (color1 * 256 * 256) + (color2 * 256) + color3;
        printf("%lf, %p\n", intensity, ret);
        return (ret);
      }
    if (ptr->type == 3)
      if ((t = intersect_plan(ray, ptr, map)) != -1)
      {
        p.x = map->cams->base->origins->x + (t * ray->x);
        p.y = map->cams->base->origins->y + (t * ray->y);
        p.z = map->cams->base->origins->z + (t * ray->z);
        normalisation2 = sqrt(pow(ray->x, 2) + pow(ray->y, 2) + pow(ray->z, 2));
        ldir.x = map->lights->base->origins->x - p.x;
        ldir.y = map->lights->base->origins->y - p.y;
        ldir.z = map->lights->base->origins->z - p.z;
        normalisation = sqrt(pow(ldir.x, 2) + pow(ldir.y, 2) + pow(ldir.z, 2));
        ldir.x = ldir.x / normalisation;
        ldir.y = ldir.y / normalisation;
        ldir.z = ldir.z / normalisation;
        angle = (((ray->x / normalisation2) * ldir.x) + ((ray->y / normalisation2) * ldir.y) + ((ray->z / normalisation2) * ldir.z));
        if (angle < 0)
          angle = -angle;
        // printf("%lf\n", angle);
        ret = 0;
        if (angle > 0)
        {
          intensity = map->lights->lumens * angle;
          color1 = ptr->base->color->x * intensity;
          color2 = ptr->base->color->y * intensity;
          color3 = ptr->base->color->z * intensity;
          ret = (color1 * 256 * 256) + (color2 * 256) + color3;
        }
        return (ret);
      }
    if (ptr->type == 2)
    {
      if ((t = intersect_plan(ray, ptr, map)) != -1)
        if (ray->x >= (ptr->base->origins->x - ptr->height) && ray->x <= (ptr->base->origins->x + ptr->height))
          if (ray->y >= (ptr->base->origins->y - ptr->height) && ray->y <= (ptr->base->origins->y + ptr->height))
          {
            p.x = map->cams->base->origins->x + (t * ray->x);
            p.y = map->cams->base->origins->y + (t * ray->y);
            p.z = map->cams->base->origins->z + (t * ray->z);
            normalisation = sqrt(pow(ray->x, 2) + pow(ray->y, 2) + pow(ray->z, 2));
            ldir.x = map->lights->base->origins->x - p.x;
            ldir.y = map->lights->base->origins->y - p.y;
            ldir.z = map->lights->base->origins->z - p.z;
            normalisation = sqrt(pow(ldir.x, 2) + pow(ldir.y, 2) + pow(ldir.z, 2));
            ldir.x = ldir.x / normalisation;
            ldir.y = ldir.y / normalisation;
            ldir.z = ldir.z / normalisation;
            angle = (((ray->x / normalisation2) * ldir.x) + ((ray->y / normalisation2) * ldir.y) + ((ray->z / normalisation2) * ldir.z));
            if (angle < 0)
              angle = -angle;
            printf("%lf\n", angle);
            if (angle > 0)
            {
              intensity = map->lights->lumens * angle;
              color1 = ptr->base->color->x * intensity;
              color2 = ptr->base->color->y * intensity;
              color3 = ptr->base->color->z * intensity;
              ret = (color1 * 256 * 256) + (color2 * 256) + color3;
              return (ret);
            }
          }
    }
    // if (ptr->type == 4)
    // {
    //
    //   polynome.x = ptr->base->vdir->x * ptr->base->vdir->x;
    //   polynome.x += ptr->base->vdir->y * ptr->base->vdir->y;
    //   polynome.x += ptr->base->vdir->z * ptr->base->vdir->z;
    //   polynome.y = polynome.x;
    //   polynome.z = polynome.x;
    //   polynome.x = polynome.x * (ray->x + ray->y + ray->z);
    //   polynome.x -= (ptr->base->vdir->x * ray->x) * (ptr->base->vdir->x * ray->x);
    //   polynome.x -= (ptr->base->vdir->y * ray->y) * (ptr->base->vdir->y * ray->y);
    //   polynome.x -= (ptr->base->vdir->z * ray->z) * (ptr->base->vdir->z * ray->z);
    //   alpha.x = ptr->base->vdir->x * ptr->base->vdir->y * ray->x;
    //   alpha.x += ptr->base->vdir->y * ptr->base->vdir->z * ray->z;
    //   alpha.x = alpha.x * ray->y;
    //   alpha.x += ptr->base->vdir->x * ptr->base->vdir->z * ray->z * ray->x;
    //   polynome.x -= alpha.x * 2;
    //   alpha.x = ray->x * map->cams->base->origins->x;
    //   alpha.x += ray->y * map->cams->base->origins->y;
    //   alpha.x += ray->z * map->cams->base->origins->z;
    //   polynome.y =  polynome.y * alpha.x;
    //   polynome.y -= ptr->base->vdir->x * ray->x * map->cams->base->origins->x;
    //   polynome.y -= ptr->base->vdir->y * ray->y * map->cams->base->origins->y;
    //   polynome.y -= ptr->base->vdir->z * ray->z * map->cams->base->origins->z;
    //   alpha.x = ray->y * map->cams->base->origins->x;
    //   alpha.x += ray->x * map->cams->base->origins->y;
    //   alpha.x = alpha.x * ptr->base->vdir->x * ptr->base->vdir->y;
    //   alpha.y = ray->z * map->cams->base->origins->x;
    //   alpha.y += ray->x * map->cams->base->origins->z;
    //   alpha.y = alpha.y * ptr->base->vdir->z * ptr->base->vdir->x;
    //   alpha.z = ray->y * map->cams->base->origins->z;
    //   alpha.z += ray->z * map->cams->base->origins->y;
    //   alpha.z = alpha.z * ptr->base->vdir->y * ptr->base->vdir->z;
    //   polynome.y = (2 * polynome.y) - alpha.x - alpha.y - alpha.z;
    //   alpha.x = map->cams->base->origins->x + map->cams->base->origins->y;
    //   alpha.x += map->cams->base->origins->z;
    //   polynome.z = polynome.z * alpha.x;
    //   alpha.x = (ptr->base->vdir->x * map->cams->base->origins->x);
    //   alpha.y = ptr->base->vdir->y * map->cams->base->origins->y;
    //   alpha.z = ptr->base->vdir->z * map->cams->base->origins->z;
    //   polynome.z -= (alpha.x * alpha.x) - (alpha.y * alpha.y) - (alpha.z * alpha.z);
    //   alpha.x = ptr->base->vdir->x * ptr->base->vdir->y * map->cams->base->origins->x;
    //   alpha.x += ptr->base->vdir->y * ptr->base->vdir->z * map->cams->base->origins->z;
    //   alpha.x = alpha.x * map->cams->base->origins->y;
    //   alpha.z = ptr->base->vdir->x * ptr->base->vdir->z * map->cams->base->origins->x;
    //   alpha.z = alpha.z * map->cams->base->origins->z;
    //   polynome.z -= alpha.x - alpha.z;
    //
    //   alpha.z = (polynome.y * polynome.y) - (4 * polynome.x * polynome.z);
    //   if (alpha.z >= 0)
    //   {
    //     alpha.x = (-polynome.y - sqrt(alpha.z)) / (2 * polynome.x);
    //     alpha.y = (-polynome.y + sqrt(alpha.z)) / (2 * polynome.x);
    //     if (alpha.y > 0)
    //       return (4);
    //   }
    // }
    ptr = ptr->next;
  }
  return (0);
}



int map_init(t_map **map)
{
  t_map *ptrmap;

  if ((ptrmap = ft_calloc(1, sizeof(t_map))))
    if ((ptrmap->ambiant = ft_calloc(1, sizeof(t_ambiant))))
      if ((ptrmap->resolution = ft_calloc(1, sizeof(t_resolution))))
        if ((ptrmap->objs = ft_calloc(1, sizeof(t_objs))))
          if ((ptrmap->cams = ft_calloc(1, sizeof(t_cams))))
            if ((ptrmap->lights = ft_calloc(1, sizeof(t_lights))))
            {
              ptrmap->cams->next = NULL;
              ptrmap->objs->next = NULL;
              ptrmap->lights->next = NULL;
              *map = ptrmap;
              return (1);
            }
  ft_clear(ptrmap);
  return (-1);
}

int main(int argc, char **argv)
{
  void *mlx;
  void *mlx_win;
  t_data img;
  t_map *map;
	double x;
	double y;
  t_triade *ray;
  int ret;

  if (argc == 2)
	{
    ret = 0;
    if (!(ray = ft_calloc(1, sizeof(t_triade))))
      return (-1);
    if ((map_init(&map)) == -1)
      return (-1);
		if (ft_parse(&map, argv[1]) != -1)
		{
  		mlx = mlx_init();
  		mlx_win = mlx_new_window(mlx, map->resolution->win_width, map->resolution->win_height, "Hello world");
  		img.img = mlx_new_image(mlx, map->resolution->win_width, map->resolution->win_height);
  		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
      ray->z = -(map->resolution->win_width / (2 * (tan((180 - map->cams->fov) / 2))));
      y = -1;
  		while (y++ < map->resolution->win_height - 1)
  		{
        ray->y = -(y - map->resolution->win_height / 2);
  			x = -1;
  			while (x++ < map->resolution->win_width - 1)
  			{
          ray->x = (x - map->resolution->win_width / 2);
  				ret = intersect(map, ray);
            my_mlx_pixel_put(&img, x, y, ret);
  				// else if (ret == 2)
          //   my_mlx_pixel_put(&img, x, y, 0x00AA00);
          // else if (ret == 3)
          //   my_mlx_pixel_put(&img, x, y, 0x00355FF9);
          // else if (ret == 4)
          //   my_mlx_pixel_put(&img, x, y, 0x00FF5FF9);
          // else
            // my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
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
