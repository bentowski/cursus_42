#include "mlx.h"
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#ifndef MINIRT_H
# define MINIRT_H

# ifdef MACOS
#  define OS 1
#  define SPC_KEY 49
#  define ESC_KEY 53
#  define DESTROYNOTIFY 17
# endif

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef struct s_env
{
  void *mlx;
  void *mlx_win;
  t_data img;
}               t_env;

#endif
