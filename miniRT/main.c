#include "mlx.h"
#include <fcntl.h>
#include "get_next_line.h"
#include "minirt.h"
#include <stdio.h>
#include <math.h>



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

void coo_init(t_coo *coo)
{
  coo->x = 0.0;
  coo->y = 0.0;
  coo->z = 0.0;
  coo->vx = 0.0;
  coo->vy = 0.0;
  coo->vz = 0.0;
  coo->diam = 0.0;
  coo->color1 = 0;
  coo->color2 = 0;
  coo->color3 = 0;
}



int main(int argc, char **argv)
{
  void *mlx;
  void *mlx_win;
  t_data img;
  t_coo coo;
  double x;
  int y;
  int win_width;
  int win_height;

  if (argc != 2)
    return (-1);
  double test;
  test = 0.0;
  test += 2;
  test = test / 10;
  test = test * 3;
  printf("%lf\n", test);
  coo_init(&coo);
  x = 0.0;
  win_width = 0;
  win_height = 0;
  ft_parse(&coo, argv[1], &win_width, &win_height);
  printf("%lf,%lf,%lf %lf, %d, %d, %d\n", coo.x, coo.y, coo.z, coo.diam, coo.color1, coo.color2, coo.color3);
  if (win_width == 0 || win_height == 0)
    return (-1);
  mlx = mlx_init();
  mlx_win = mlx_new_window(mlx, win_width, win_height, "Hello world");
  img.img = mlx_new_image(mlx, win_width, win_height);
  img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
  x = win_width / 4;
  while (x < (win_width / 4) * 3)
  {
    y = win_height / 4;
    while (y < (win_height / 4) * 3)
    {
      my_mlx_pixel_put(&img, x, y, 0x00FF0000);
      y++;
    }
    x++;
  }
  mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
  mlx_loop(mlx);
}
