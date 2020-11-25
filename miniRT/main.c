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
    if (new->name[0] == 'A')
      printf("%s : %lf, %d,%d,%d\n\n", "A", new->puissance, new->color1, new->color2, new->color3);
    if (new->name[0] == 'c' && new->name[1] == 'y')
      printf("%s : %lf, %lf, %lf     %lf,%lf,%lf     %lf     %lf      %d, %d, %d\n", new->name, new->x, new->y, new->z, new->vx, new->vy, new->vz, new->height, new->diameter, new->color1, new->color2, new->color3);
    else if (new->name[0] == 'c')
      printf("%s : %lf, %lf, %lf       %lf, %lf, %lf      %d\n", new->name, new->x, new->y, new->z, new->vx, new->vy, new->vz, new->fov);
    else if (new->name[0] == 's' && new->name[1] == 'p')
      printf("%s : %lf, %lf, %lf     %lf,       %d, %d, %d\n", new->name, new->x, new->y, new->z, new->diameter, new->color1, new->color2, new->color3);
    else if (new->name[0] == 'p' && new->name[1] == 'l')
      printf("%s : %lf, %lf, %lf     %lf, %lf, %lf     %d, %d, %d\n", new->name, new->x, new->y, new->z, new->vx, new->vy, new->vz, new->color1, new->color2, new->color3);
    else if (new->name[0] == 't' && new->name[1] == 'r')
      printf("%s : %lf, %lf, %lf     %lf, %lf, %lf       %lf, %lf, %lf,    %d, %d, %d\n", new->name, new->x, new->y, new->z, new->x2, new->y2, new->z2, new->x3, new->y3, new->z3, new->color1, new->color2, new->color3);
    else if (new->name[0] == 's' && new->name[1] == 'q')
      printf("%s : %lf, %lf, %lf    %lf, %lf, %lf       %lf,       %d, %d, %d\n", new->name, new->x, new->y, new->z, new->vx, new->vy, new->vz, new->diameter, new->color1, new->color2, new->color3);
    else if (new->name[0] == 'l')
      printf("%s : %lf, %lf, %lf     %lf      %d, %d, %d\n", new->name, new->x, new->y, new->z, new->puissance, new->color1, new->color2, new->color3);
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

// void test()
// {
// 	whi
// }

// int intersect(t_list *obj)
// {
// 	t_list *tmp;
// 	double rayonx;
// 	double rayony;
// 	double rayonz;
//
// 	tmp = obj;
// 	rayonx = .0;
// 	rayony = .0;
// 	rayonz = .0;
// 	while (tmp->next)
// 	{
// 		s = tmp->name;
// 		if (s[0] == 's')
// 		{
// 			if (s[1] == 'p')
// 			{
// 				printf("%s\n%lf", "OK", tmp->x);
// 				if ()
// 			}
// 		}
// 		tmp = tmp->next;
// 	}
// }
double ft_bite(double x, double y, double vx, double vy)
{
	double vz;
	double xr;
	double yr;
	double zr;
	double xo;
	double yo;
	double zo;
	double r;
	double a;
	double b;
	double c;
	double delta;
	double ret;

	// vx = 400;
	// vy = 300;
	vz = 70.0;
	xr = -50.0;
	yr = 0.0;
	zr = 20.0;
	xo = 0.0;
	yo = 0.0;
	zo = 20.6;
	r = 12.6;
	a = pow(vx, 2) + pow(vy, 2) + pow(vz, 2);
	b = 2 * (vx * (xr - xo) + vy * (yr - yo) + vz * (zr - zo));
	c = pow(xr - xo, 2) + pow(yr - yo, 2) + pow(zr - zo, 2) - pow(r, 2);
	delta = pow(b, 2) - 4 * (a * c);
	printf("%s  :  %lf\n", "delta", delta);
	if (delta >= 0)
	{
		if (delta == 0)
			delta = -b + (sqrt(delta) / (2 * a));
		else if ((-b + (sqrt(delta) / (2 * a))) > (-b - (sqrt(delta) / (2 * a))))
			delta = -b - (sqrt(delta) / (2 * a));
		else
			delta = -b + (sqrt(delta) / (2 * a));
		printf("%s  :  %lf\n", "calcul", (delta * vx) + xr);
		printf("%s  :  %lf\n", "x", x);
	}
	if ((x == (delta * vx) + xr) &&	(y == (delta * vy) + yr))
		return (1);
	else
		return (-1);
}


int main(int argc, char **argv)
{
  void *mlx;
  void *mlx_win;
  t_data img;
	t_list *obj;
  char *line;
  int fd;
  int win_width;
  int win_height;
	double x;
	double y;
	double vx;
	double vy;

  if (argc == 2)
	{
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
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, win_width, win_height, "Hello world");
		img.img = mlx_new_image(mlx, win_width, win_height);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		x = 0;
		y = 0;
		while (x++ < win_width)
		{
			while (y++ < win_height)
			{
				if (ft_bite(x, y, x, y) < 0)
					my_mlx_pixel_put(&img, x, y, 0x00FF5733);
				else
					my_mlx_pixel_put(&img, x, y, 0x00FF5733);
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
