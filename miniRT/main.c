#include "mlx.h"
#include <fcntl.h>
#include "minirt.h"
#include <stdio.h>
#include <math.h>
#include <unistd.h>


//
// typedef struct  s_data {
//     void        *img;
//     char        *addr;
//     int         bits_per_pixel;
//     int         line_length;
//     int         endian;
// }               t_data;
//
// void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
//     char    *dst;
//
//     dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//     *(unsigned int*)dst = color;
// }

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

int main(int argc, char **argv)
{
  // void *mlx;
  // void *mlx_win;
  // t_data img;
  // double x;
  char *line;
  int fd;
  int win_width;
  int win_height;

  if (argc != 2)
    return (-1);
  // x = 0.0;
  fd = open(argv[1], O_RDONLY);
  win_width = 0;
  win_height = 0;
  if (ft_parse(&line, fd, &win_width, &win_height) == -1)
		return (-1);
  printf("%s\n", "FIN");
  // if (win_width == 0 || win_height == 0)
  //   return (-1);
  // mlx = mlx_init();
  // mlx_win = mlx_new_window(mlx, win_width, win_height, "Hello world");
  // img.img = mlx_new_image(mlx, win_width, win_height);
  // img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
  // x = win_width / 4;
  // while (x < (win_width / 4) * 3)
  // {
  //   y = win_height / 4;
  //   while (y < (win_height / 4) * 3)
  //   {
  //     my_mlx_pixel_put(&img, x, y, 0x00FF0000);
  //     y++;
  //   }
  //   x++;
  // }
  system("leaks a.out");
  // mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
  // mlx_loop(mlx);
  // ft_clear(&obj);
}
