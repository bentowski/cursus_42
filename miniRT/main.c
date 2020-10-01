#include "mlx.h"
#include <fcntl.h>
#include "minirt.h"
#include <stdio.h>
#include <math.h>
#include <unistd.h>



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

t_coo *coo_init(t_coo *coo)
{
  t_coo new;

  // if (!(new = (t_coo *)malloc(1)))
  //   return (NULL);

  new.name = NULL;
  new.x = .0;
  new.y = .0;
  new.z = .0;
  new.vx = .0;
  new.vy = .0;
  new.vz = .0;
  new.diameter = .0;
  new.height = .0;
  new.color1 = 0;
  new.color2 = 0;
  new.color3 = 0;
  new.next = NULL;
  while (coo->next)
    coo = coo->next;
  coo->next = &new;

  return (coo);
}

void ft_clear(t_coo **coo)
{
  t_coo *ptr;
  t_coo *tmp;

  ptr = *coo;
  if (!coo)
    return ;
  while (ptr)
  {
    tmp = ptr->next;
    free(*coo);
    ptr = tmp;
  }
  *coo = NULL;
}


int main(int argc, char **argv)
{
  void *mlx;
  void *mlx_win;
  t_data img;
  double x;
  int y;
  int win_width;
  int win_height;
  t_coo *coo;

  if (argc != 2)
    return (-1);
  x = 0.0;
  win_width = 0;
  win_height = 0;
  if (!(coo = (t_coo *)malloc(1)))
    return (-1);
  ft_parse(argv[1], &win_width, &win_height, coo);
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
  ft_clear(&coo);
}
