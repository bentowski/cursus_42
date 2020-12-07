#include "includes/get_next_line/get_next_line.h"
#include "mlx.h"
#include <fcntl.h>
#include <stdio.h>
#include <math.h>

#ifndef MINIRT_H
# define MINIRT_H

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
  double  ambiant;
  t_triade *color;
}               t_ambiant;

typedef struct s_resolution
{
  int win_width;
  int win_height;
}               t_resolution;

typedef struct s_objs
{
  t_base *base;
  t_triade *p2;
  t_triade *p3;
  double diameter;
  double height;
  struct s_objs *next;
}               t_objs;

typedef struct s_cams
{
  t_base *base;
  double fov;
  struct s_cams *next;
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
}             t_map;

// int ft_parse(char **line, int fd, int *win_width, int *win_height);
// int init_sphere(char *line, int i, t_list ****obj);
// int init_plane(char *line, int i, t_list ****obj);
// int init_square(char *line, int i, t_list ****obj);
// int init_cylinder(char *line, int i, t_list ****obj);
// int init_triangle(char *line, int i, t_list ****obj);
// int ft_triade(t_list *new, char *line, int i, int opt);
// int ft_structuration(t_list *new, char *line, int i, int opt);
// void new_init(t_list *new);
int ft_space(char *line, int i);
// int ft_color(t_list *new, char *line, int i);
void	*ft_calloc(size_t count, size_t size);
// double ft_routine(double x, char *line, int *i, int opt);
int resolution(t_map *map, char *line, int i);
// int ambiance(char *line, int i, t_list ****obj);
// int camera(char *line, int i, t_list ****obj);
// int light(char *line, int i, t_list ****obj);
int ft_parse(t_map *map, char *givedmap);
int foisdeux(char *line, int *ayet, int *ryet);
void ft_clear(t_map *map);




#endif
