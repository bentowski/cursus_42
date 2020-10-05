#include "../miniRT/includes/get_next_line/get_next_line.h"

#ifndef MINIRT_H
# define MINIRT_H

typedef struct s_coo
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

  struct s_coo next;

}             t_coo;

int ft_parse(char *map, t_coo *coo);
int init_sphere(char *line, int i, t_coo *coo);
int init_plane(char *line, int i, t_coo *coo);
int init_square(char *line, int i, t_coo *coo);
int init_cylinder(char *line, int i, t_coo *coo);
int ft_coordonnees(t_coo *coo, char *line, int i);
int ft_dimensions(t_coo *coo, char *line, int i, int opt);
// t_coo *coo_init();
int ft_space(char *line, int i);
int ft_color(t_coo *coo, char *line, int i);




#endif
