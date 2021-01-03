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

int intersect_plan(t_triade *ray, t_objs *ptr, t_map *map)
{
  t_triade alpha;

  alpha.x = (ptr->base->origins->x - map->cams->base->origins->x) * ptr->base->vdir->x;
  alpha.x += (ptr->base->origins->y - map->cams->base->origins->y) * ptr->base->vdir->y;
  alpha.x += (ptr->base->origins->z - map->cams->base->origins->z) * ptr->base->vdir->z;
  alpha.y = ray->x * ptr->base->vdir->x;
  alpha.y += ray->y * ptr->base->vdir->y;
  alpha.y += ray->z * ptr->base->vdir->z;
  alpha.x = alpha.x / alpha.y;
  if (alpha.x > 0)
    return (alpha.x);
  return (-1);
}

int intersect_sphere(t_triade *ray, t_objs *ptr, t_map *map)
{
  t_triade alpha;
  t_triade polynome;

  alpha.x = 0;
  alpha.y = 0;
  polynome.x = (ray->x * ray->x) + (ray->y * ray->y) + (ray->z * ray->z);
  polynome.y = 2 * (ray->x * (map->cams->base->origins->x - ptr->base->origins->x));
  polynome.y += 2 * (ray->y * (map->cams->base->origins->y - ptr->base->origins->y));
  polynome.y += 2 * (ray->z * (map->cams->base->origins->z - ptr->base->origins->z));
  polynome.z = (map->cams->base->origins->x - ptr->base->origins->x) * (map->cams->base->origins->x - ptr->base->origins->x);
  polynome.z += (map->cams->base->origins->y - ptr->base->origins->y) * (map->cams->base->origins->y - ptr->base->origins->y);
  polynome.z += (map->cams->base->origins->z - ptr->base->origins->z) * (map->cams->base->origins->z - ptr->base->origins->z);
  polynome.z -= (ptr->diam / 2) * (ptr->diam/ 2);
  alpha.z = polynome.y * polynome.y - 4 * polynome.x * polynome.z;
  if (alpha.z >= 0)
  {
    alpha.x = (-polynome.y - sqrt(alpha.z)) / (2 * polynome.x);
    alpha.y = (-polynome.y + sqrt(alpha.z)) / (2 * polynome.x);
    return (alpha.y);
  }
  return (-1);
}


int intersect(t_map *map, t_triade *ray)
{
  double delta;
  double test;
  t_triade alpha;
  t_triade polynome;
  t_objs *ptr;
  t_triade essai;
  double t;

  ptr = map->objs;
  alpha.z = 0;
  while (ptr->next)
  {
    if (ptr->type == 1)
      if (intersect_sphere(ray, ptr, map) >= 0)
        return (1);
    if (ptr->type == 3)
      if (intersect_plan(ray, ptr, map) != -1)
        return (3);
    if (ptr->type == 2)
      if (ray->x >= (ptr->base->origins->x - ptr->height) && ray->x <= (ptr->base->origins->x + ptr->height))
        if (ray->y >= (ptr->base->origins->y - ptr->height) && ray->y <= (ptr->base->origins->y + ptr->height))
          if (intersect_plan(ray, ptr, map) != -1)
            return (2);
    if (ptr->type == 4)
    {
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
          return (4);
        else
        {
          essai = *ptr->base->origins;
          essai.x += ptr->base->vdir->x * ptr->height;
          essai.y += ptr->base->vdir->y * ptr->height;
          essai.z += ptr->base->vdir->z * ptr->height;
          alpha.x = (essai.x - map->cams->base->origins->x) * ptr->base->vdir->x;
          alpha.x += (essai.y - map->cams->base->origins->y) * ptr->base->vdir->y;
          alpha.x += (essai.z - map->cams->base->origins->z) * ptr->base->vdir->z;
          alpha.y = ray->x * ptr->base->vdir->x;
          alpha.y += ray->y * ptr->base->vdir->y;
          alpha.y += ray->z * ptr->base->vdir->z;
          alpha.z = alpha.x / alpha.y;
          polynome.x = (ray->x * ray->x) + (ray->y * ray->y) + (ray->z * ray->z);
          polynome.x = polynome.x * (alpha.z * alpha.z);
          polynome.y = (2 * alpha.z) * ((ray->x * (map->cams->base->origins->x - essai.x)));
          polynome.y += (2 * alpha.z) * ((ray->y * (map->cams->base->origins->y - essai.y)));
          polynome.y += (2 * alpha.z) * ((ray->z * (map->cams->base->origins->z - essai.z)));
          polynome.z = (map->cams->base->origins->x - essai.x) * (map->cams->base->origins->x - essai.x);
          polynome.z += (map->cams->base->origins->y - essai.y) * (map->cams->base->origins->y - essai.y);
          polynome.z += (map->cams->base->origins->z - essai.z) * (map->cams->base->origins->z - essai.z);
          polynome.z -= (ptr->diam / 2) * (ptr->diam/ 2);
          if ((polynome.x + polynome.y + polynome.z) <= 0)
            return (4);
          else
          {
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
            polynome.z += polynome.y + polynome.x;
            t = (ptr->base->vdir->x * ptr->base->vdir->x) + (ptr->base->vdir->y * ptr->base->vdir->y) + (ptr->base->vdir->z * ptr->base->vdir->z);
            t = polynome.z / t;
            t = -t;
            printf("%lf\n", t);
            if (t >= 0 && t <= ptr->height)
              return (4);
          }
        }
    }
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
      // ptr = map->cams;
      // ptr = ptr->next;
      // printf("%s : %lf, %lf, %lf\n", "c", ptr->base->origins->x, ptr->base->origins->y, ptr->base->origins->z);
      // while (ptr->next)
      // {
      //   printf("%s : %lf, %lf, %lf    %lf, %lf, %lf     %lf\n", "c", ptr->base->origins->x, ptr->base->origins->y, ptr->base->origins->z, ptr->base->vdir->x, ptr->base->vdir->y, ptr->base->vdir->z, ptr->fov);
      //   ptr = ptr->next;
      // }
      // ptrlights = map->lights;
      // while (ptrlights->next)
      // {
      //   printf("%s : %lf, %lf, %lf    %lf    %lf, %lf, %lf\n", "l", ptrlights->base->origins->x, ptrlights->base->origins->y, ptrlights->base->origins->z, ptrlights->lumens, ptrlights->base->color->x, ptrlights->base->color->y, ptrlights->base->color->z);
      //   ptrlights = ptrlights->next;
      // }
  		mlx = mlx_init();
  		mlx_win = mlx_new_window(mlx, map->resolution->win_width, map->resolution->win_height, "Hello world");
  		img.img = mlx_new_image(mlx, map->resolution->win_width, map->resolution->win_height);
  		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
      ray->z = map->resolution->win_width / (2 * (tan(map->cams->fov / 2)));
      y = -1;
  		while (y++ < map->resolution->win_height - 1)
  		{
        ray->y = y - map->resolution->win_height / 2;
  			x = -1;
  			while (x++ < map->resolution->win_width - 1)
  			{
          ray->x = x - map->resolution->win_width / 2;
  				if ((ret = intersect(map, ray)) == 1)
            my_mlx_pixel_put(&img, x, y, 0x0033FF39);
  				else if (ret == 2)
            my_mlx_pixel_put(&img, x, y, 0x00000000);
          else if (ret == 3)
            my_mlx_pixel_put(&img, x, y, 0x00355FF9);
          else if (ret == 4)
            my_mlx_pixel_put(&img, x, y, 0x00FF5FF9);
          else
            my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
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
