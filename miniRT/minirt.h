#include "includes/get_next_line/get_next_line.h"

#ifndef MINIRT_H
# define MINIRT_H

typedef struct s_list
{
  char *name;
  double x;
  double y;
  double z;
  double vx;
  double vz;
  double vy;
  double diameter;
  double height;
  int color1;
  int color2;
  int color3;

  struct s_list *next;

}             t_list;

int ft_parse(char *map, int *win_width, int *win_height);
int init_sphere(char *line, int i, t_list ***obj);
int init_plane(char *line, int i, t_list ***obj);
int init_square(char *line, int i, t_list ***obj);
int init_cylinder(char *line, int i, t_list ***obj);
int ft_coordonnees(t_list *obj, char *line, int i);
int ft_dimensions(t_list *obj, char *line, int i, int opt);
void new_init(t_list *new);
int ft_space(char *line, int i);
int ft_color(t_list *obj, char *line, int i);
void	*ft_calloc(size_t count, size_t size);





#endif
