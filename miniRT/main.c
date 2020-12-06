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

void ft_print(t_list *new)
{
  if (new->next)
  {
    // if (new->name[0] == 'A')
    //   printf("%s : %lf, %d,%d,%d\n\n", "A", new->puissance, new->color1, new->color2, new->color3);
    // if (new->name[0] == 'c' && new->name[1] == 'y')
    //   printf("%s : %lf, %lf, %lf     %lf,%lf,%lf     %lf     %lf      %d, %d, %d\n", new->name, new->x, new->y, new->z, new->vx, new->vy, new->vz, new->height, new->diameter, new->color1, new->color2, new->color3);
    // else if (new->name[0] == 'c')
    //   printf("%s : %lf, %lf, %lf       %lf, %lf, %lf      %d\n", new->name, new->x, new->y, new->z, new->vx, new->vy, new->vz, new->fov);
    // else if (new->name[0] == 's' && new->name[1] == 'p')
    //   printf("%s : %lf, %lf, %lf     %lf,       %d, %d, %d\n", new->name, new->x, new->y, new->z, new->diameter, new->color1, new->color2, new->color3);
    // else if (new->name[0] == 'p' && new->name[1] == 'l')
    //   printf("%s : %lf, %lf, %lf     %lf, %lf, %lf     %d, %d, %d\n", new->name, new->x, new->y, new->z, new->vx, new->vy, new->vz, new->color1, new->color2, new->color3);
    // else if (new->name[0] == 't' && new->name[1] == 'r')
    //   printf("%s : %lf, %lf, %lf     %lf, %lf, %lf       %lf, %lf, %lf,    %d, %d, %d\n", new->name, new->x, new->y, new->z, new->x2, new->y2, new->z2, new->x3, new->y3, new->z3, new->color1, new->color2, new->color3);
    // else if (new->name[0] == 's' && new->name[1] == 'q')
    //   printf("%s : %lf, %lf, %lf    %lf, %lf, %lf       %lf,       %d, %d, %d\n", new->name, new->x, new->y, new->z, new->vx, new->vy, new->vz, new->diameter, new->color1, new->color2, new->color3);
    // else if (new->name[0] == 'l')
    //   printf("%s : %lf, %lf, %lf     %lf      %d, %d, %d\n", new->name, new->x, new->y, new->z, new->puissance, new->color1, new->color2, new->color3);
  }
}

void ft_clear(t_list *obj, char **line)
{
  t_list *tmp;
  t_list *ptr;

  ptr = obj;
  while (ptr)
  {
    ft_print(ptr);
    tmp = ptr->next;
    free(ptr);
    ptr = tmp;
  }
  free(*line);
}

int sphere(t_list *obj, t_vecteur ray)
{
  double delta;
  double t1;
  double t2;
  double a;
  double b;
  double c;
  t_list *tmp;
  t_vecteur camera;
  t_sphere sphere;

  tmp = obj;
  while (tmp && tmp->type != 8)
    tmp = tmp->next;
  camera.x = tmp->x;
  camera.y = tmp->y;
  camera.z = tmp->z;
  printf("%s\n", "camera ok");
  tmp = obj;
  while (tmp && tmp->type != 1)
    tmp = tmp->next;
  sphere.x = tmp->x;
  sphere.y = tmp->y;
  sphere.z = tmp->z;
  sphere.r = tmp->diameter / 2;
  printf("%s\n", "sphere ok");
  delta = 0;
  t1 = 0;
  t2 = 0;
  a = (ray.x * ray.x) + (ray.y * ray.y) + (ray.z *ray.z);
  b = 2 * (ray.x * (camera.x - sphere.x));
  b += 2 * (ray.y * (camera.y - sphere.y));
  b += 2 * (ray.z * (camera.z - sphere.z));
  c = (camera.x - sphere.x) * (camera.x - sphere.x);
  c += (camera.y - sphere.y) * (camera.y - sphere.y);
  c += (camera.z - sphere.z) * (camera.z - sphere.z);
  c -= sphere.r * sphere.r;
  delta = b * b - 4 * a * c;
  if (delta >= 0)
  {
    t1 = (-b - sqrt(delta)) / (2 * a);
    t2 = (-b + sqrt(delta)) / (2 * a);
    if (t2 > 0)
      return (1);
  }
  return (0);
}


int main(int argc, char **argv)
{
  void *mlx;
  void *mlx_win;
  t_data img;
	t_list *obj;
  t_list *tmp;
  char *line;
  int fd;
	double x;
	double y;
  t_vecteur ray;
  int win_width;
  int win_height;
  // int *res;

  if (argc == 2)
	{
    // if (!(res = ft_calloc(1, sizeof(int))))
    //   return (-1);
		if (!(obj = ft_calloc(1, sizeof(t_list))))
			return (-1);
		obj->next = NULL;
		fd = open(argv[1], O_RDONLY);
		win_width = 0;
		win_height = 0;
		if (ft_parse(&obj, &line, fd, &win_width, &win_height) == -1)
		{
			ft_clear(obj, &line);
			return (-1);
		}
    printf("%s\n", "ok");
    tmp = obj;
    while (tmp && tmp->type != 8)
      tmp = tmp->next;
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, win_width, win_height, "Hello world");
		img.img = mlx_new_image(mlx, win_width, win_height);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    ray.z = win_width / (2 * (tan(tmp->fov / 2)));
    y = -1;
		while (y++ < win_height - 1)
		{
      ray.y = y - win_height / 2;
			x = -1;
			while (x++ < win_width - 1)
			{
        ray.x = x - win_width / 2;
				if (sphere(obj, ray))
          my_mlx_pixel_put(&img, x, y, 0x0033FF39);
				else
          my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
				// printf("%s\n", "ok");
			}
		}
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		mlx_loop(mlx);
		printf("%s\n", "FIN");
		ft_clear(obj, &line);
		system("leaks a.out");
		return (1);
	}
	printf("%s\n%s", "Error", "missing or too much arguments");
	return (-1);
}
