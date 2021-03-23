#include "includes/get_next_line/get_next_line.h"
#include "./mlx/mlx.h"
#include <fcntl.h>
#include <stdio.h>
#include <math.h>

#ifndef MINIRT_H
# define MINIRT_H

// # ifdef MACOS
#  define OS 1
#  define SPC_KEY 32
#  define ESC_KEY 65307
#  define R_KEY 114
#  define N_KEY 110
#  define P_KEY 112
#  define A_KEY 97
#  define W_KEY 119
#  define S_KEY 115
#  define D_KEY 100
#  define LARROW_KEY 65361
#  define UARROW_KEY 65362
#  define DARROW_KEY 65364
#  define RARROW_KEY 65363
#  define DESTROYNOTIFY 17
// # endif

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef struct s_triade
{
  double x;
  double y;
  double z;
}              t_triade;

typedef struct s_base
{
  t_triade *origins;
  t_triade *vdir;
  t_triade *color;

}               t_base;

typedef struct s_ambiant
{
  double  lumens;
  t_triade *color;
}               t_ambiant;

typedef struct s_resolution
{
  int win_width;
  int win_height;
}               t_resolution;

typedef struct s_objs
{
  int       type;
  t_base    *base;
  t_triade  *p2;
  t_triade  *p3;
  double    diam;
  double    height;
  struct s_objs *next;
}               t_objs;

typedef struct s_cams
{
  t_base *base;
  double fov;
  struct s_cams *next;
  struct s_cams *previous;
}               t_cams;

typedef struct s_lights
{
  t_base *base;
  double lumens;
  struct s_lights *next;
}               t_lights;

typedef struct s_map
{
  t_ambiant     *ambiant;
  t_resolution  *resolution;
  t_objs        *objs;
  t_cams        *cams;
  t_lights      *lights;
  t_triade      *vnull;
}             t_map;

typedef struct s_env
{
  void *mlx;
  void *mlx_win;
  t_data img;
  t_map *map;
  char *rtfile;
}               t_env;

void	*ft_calloc(size_t count, size_t size);
int ft_parse(t_map **map, char *givedmap);
void ft_clear(t_map *map);
void ft_clear_cams(t_cams *cams);
void ft_clear_lights(t_lights *lights);
void ft_clear_objs(t_objs *objs);
t_triade get_norme(t_triade target);
unsigned long int ft_raytracing(t_map *map, t_triade ray);
void  my_mlx_pixel_put(t_data *data, int x, int y, int color);
double scale(t_triade *t1, t_triade *t2);
t_triade crossprod(t_triade v1, t_triade v2);
t_triade subs(t_triade t1, t_triade t2);



#endif
