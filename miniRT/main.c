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

// void ft_print(t_list *new)
// {
//   if (new->next)
//   {
//     if (new->type == 0)
//       printf("%s : %lf, %d,%d,%d\n\n", "A", new->puissance, new->color1, new->color2, new->color3);
//     if (new->type == 4)
//       printf("%s : %lf, %lf, %lf     %lf,%lf,%lf     %lf     %lf      %d, %d, %d\n", "cylinder", new->x, new->y, new->z, new->vx, new->vy, new->vz, new->height, new->diameter, new->color1, new->color2, new->color3);
//     else if (new->type == 8)
//       printf("%s : %lf, %lf, %lf       %lf, %lf, %lf      %d\n", "camera", new->x, new->y, new->z, new->vx, new->vy, new->vz, new->fov);
//     else if (new->type == 1)
//       printf("%s : %lf, %lf, %lf     %lf,       %d, %d, %d\n", "sphere", new->x, new->y, new->z, new->diameter, new->color1, new->color2, new->color3);
//     else if (new->type == 3)
//       printf("%s : %lf, %lf, %lf     %lf, %lf, %lf     %d, %d, %d\n", "plane", new->x, new->y, new->z, new->vx, new->vy, new->vz, new->color1, new->color2, new->color3);
//     else if (new->type == 5)
//       printf("%s : %lf, %lf, %lf     %lf, %lf, %lf       %lf, %lf, %lf,    %d, %d, %d\n", "triangle", new->x, new->y, new->z, new->x2, new->y2, new->z2, new->x3, new->y3, new->z3, new->color1, new->color2, new->color3);
//     else if (new->type == 2)
//       printf("%s : %lf, %lf, %lf    %lf, %lf, %lf       %lf,       %d, %d, %d\n", "square", new->x, new->y, new->z, new->vx, new->vy, new->vz, new->diameter, new->color1, new->color2, new->color3);
//     else if (new->type == 9)
//       printf("%s : %lf, %lf, %lf     %lf      %d, %d, %d\n", "ligth", new->x, new->y, new->z, new->puissance, new->color1, new->color2, new->color3);
//   }
// }

// void ft_clear_objs(t_objs objs)
// {
//   t_objs *tmp;
//   t_objs *ptr;
//
//   ptr = obj;
//   while (ptr)
//   {
//     tmp = ptr->next;
//     ft_clear_triade(ptr->p2)
//     free(ptr);
//     ptr = tmp;
//   }
// }


// int sphere(t_list *obj, t_vecteur ray)
// {
//   // double delta;
//   // double t1;
//   // double t2;
//   // double a;
//   // double b;
//   // double c;
//   // t_list *tmp;
//   // t_vecteur camera;
//   // t_sphere sphere;
//   //
//   // tmp = obj;
//   // while (tmp && tmp->type != 8)
//   //   tmp = tmp->next;
//   // camera.x = tmp->x;
//   // camera.y = tmp->y;
//   // camera.z = tmp->z;
//   // tmp = obj;
//   // while (tmp && tmp->type != 1)
//   //   tmp = tmp->next;
//   // sphere.x = tmp->x;
//   // sphere.y = tmp->y;
//   // sphere.z = tmp->z;
//   // sphere.r = tmp->diameter / 2;
//   // delta = 0;
//   // t1 = 0;
//   // t2 = 0;
//   // a = (ray.x * ray.x) + (ray.y * ray.y) + (ray.z *ray.z);
//   // b = 2 * (ray.x * (camera.x - sphere.x));
//   // b += 2 * (ray.y * (camera.y - sphere.y));
//   // b += 2 * (ray.z * (camera.z - sphere.z));
//   // c = (camera.x - sphere.x) * (camera.x - sphere.x);
//   // c += (camera.y - sphere.y) * (camera.y - sphere.y);
//   // c += (camera.z - sphere.z) * (camera.z - sphere.z);
//   // c -= sphere.r * sphere.r;
//   // delta = b * b - 4 * a * c;
//   // if (delta >= 0)
//   // {
//   //   t1 = (-b - sqrt(delta)) / (2 * a);
//   //   t2 = (-b + sqrt(delta)) / (2 * a);
//   //   if (t2 > 0)
//   //     return (1);
//   // }
//   // return (0);
// }



int map_init(t_map **map)
{
  t_map *ptrmap;

  // ptrmap = *map;
  printf("%s\n", "truc");
  if ((ptrmap = ft_calloc(1, sizeof(t_map))))
  {
    printf("%s\n", "ouch");
    if ((ptrmap->ambiant = ft_calloc(1, sizeof(t_ambiant))))
    {
      printf("%s\n", "zoom");
      if ((ptrmap->resolution = ft_calloc(1, sizeof(t_resolution))))
      {
        printf("%s\n", "sblif");
        if ((ptrmap->objs = ft_calloc(1, sizeof(t_objs))))
        {
          ptrmap->objs->next = NULL;
          printf("%s\n", "olala");
          if ((ptrmap->cams = ft_calloc(1, sizeof(t_cams))))
          {
            ptrmap->cams->next = NULL;
            printf("%s\n", "zuc");
            if ((ptrmap->lights = ft_calloc(1, sizeof(t_lights))))
            {
              ptrmap->lights->next = NULL;
              printf("%s\n", "arg");
              *map = ptrmap;
              return (1);
            }
          }
        }
      }
    }
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
  t_triade ray;
  t_cams *ptr;
  t_lights *ptrlights;

  if (argc == 2)
	{
    if ((map_init(&map)) == -1)
      return (-1);
		if (ft_parse(&map, argv[1]) != -1)
		{
      ptr = map->cams;
      // ptr = ptr->next;
      // printf("%s : %lf, %lf, %lf\n", "c", ptr->base->origins->x, ptr->base->origins->y, ptr->base->origins->z);
      while (ptr->next)
      {
        printf("%s : %lf, %lf, %lf    %lf, %lf, %lf     %lf\n", "c", ptr->base->origins->x, ptr->base->origins->y, ptr->base->origins->z, ptr->base->vdir->x, ptr->base->vdir->y, ptr->base->vdir->z, ptr->fov);
        ptr = ptr->next;
      }
      ptrlights = map->lights;
      while (ptrlights->next)
      {
        printf("%s : %lf, %lf, %lf    %lf    %lf, %lf, %lf\n", "l", ptrlights->base->origins->x, ptrlights->base->origins->y, ptrlights->base->origins->z, ptrlights->lumens, ptrlights->base->color->x, ptrlights->base->color->y, ptrlights->base->color->z);
        ptrlights = ptrlights->next;
      }
      printf("%s\n", "OK");
  		mlx = mlx_init();
  		mlx_win = mlx_new_window(mlx, map->resolution->win_width, map->resolution->win_height, "Hello world");
  		img.img = mlx_new_image(mlx, map->resolution->win_width, map->resolution->win_height);
  		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
      // ray.z = res[0] / (2 * (tan(tmp->fov / 2)));
      y = -1;
  		// while (y++ < res[1] - 1)
  		// {
      //   ray.y = y - res[1] / 2;
  		// 	x = -1;
  		// 	while (x++ < res[0] - 1)
  		// 	{
      //     ray.x = x - res[0] / 2;
  		// 		if (sphere(obj, ray))
      //       my_mlx_pixel_put(&img, x, y, 0x0033FF39);
  		// 		else
      //       my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
  		// 	}
  		// }
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
