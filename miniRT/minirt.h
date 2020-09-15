#ifndef MINIRT_H
# define MINIRT_H

typedef struct s_coo
{
  double x;
  double y;
  double z;
  double vx;
  double vz;
  double vy;
  double diam;
  int color1;
  int color2;
  int color3;

}             t_coo;

int ft_parse(t_coo *coo, char *map, int *win_width, int *win_height);
int init_sphere(t_coo *coo, char *line, int i);
int init_plane(t_coo *coo, char *line, int i);

#endif
