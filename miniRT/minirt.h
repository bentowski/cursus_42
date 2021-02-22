#include "includes/get_next_line/get_next_line.h"
#include "includes/mlx.h"
#include <fcntl.h>
#include <stdio.h>
#include <math.h>

#ifndef MINIRT_H
# define MINIRT_H

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

int init_sphere(char *line, int i, t_objs **objs);
int init_plane(char *line, int i, t_objs **objs);
int init_square(char *line, int i, t_objs **objs);
int init_cylinder(char *line, int i, t_objs **objs);
int init_triangle(char *line, int i, t_objs **objs);
int ft_coordonnees(t_triade *new, char *line, int i);
int ft_structuration(t_triade *new, char *line, int i);
int ft_space(char *line, int i);
int ft_color(t_triade *color, char *line, int i);
void	*ft_calloc(size_t count, size_t size);
int ft_routine(double *x, char *line, int *i, int opt);
int resolution(t_map ****map, char *line, int i);
int ambiance(char *line, int i, t_ambiant **ambiant);
int camera(char *line, int i, t_cams **cams);
int light(char *line, int i, t_lights **lights);
int ft_parse(t_map **map, char *givedmap);
int foisdeux(char *line, int *ayet, int *ryet);
void ft_clear(t_map *map);
void ft_clear_cams(t_cams *cams);
void ft_clear_lights(t_lights *lights);
void ft_clear_objs(t_objs *objs);
int ft_check_color_vdir(t_triade *check, int opt);
t_objs *intersect(t_objs *ptr, t_triade *origins, t_triade ray, double *alpha);
unsigned long int interlsphere(double t, t_triade ray, t_objs *ptr, t_map *map);
unsigned long int interlplan(double t, t_triade ray, t_objs *ptr, t_map *map);
t_triade get_norme(t_triade target);
t_triade vector(t_triade *t1, t_triade *t2);
double intersect_sphere(t_triade ray, t_objs *ptr, t_triade *origins);
double intersect_plan(t_triade ray, t_objs *ptr, t_triade *origins);
unsigned long int ft_raytracing(t_map *map, t_triade ray);
double scale(t_triade *t1, t_triade *t2);
t_triade get_position(t_triade *origins, t_triade ray, double t);
t_triade get_normale(t_objs *ptr, t_triade position, t_map *map);
t_triade get_color(t_ambiant *ambiant, t_objs *ptr, double intensity);
t_triade crossprod(t_triade v1, t_triade v2);
t_triade *vector_v(t_triade *t1, t_triade *t2);
int ft_vdir_tr(t_base *ptr, t_triade *p2, t_triade *p3);
t_triade add_vectors(t_triade u, t_triade v);

#endif
