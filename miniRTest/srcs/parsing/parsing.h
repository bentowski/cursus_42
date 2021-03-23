#include "../../minirt.h"

#ifndef PARSING_H
# define PARSING_H

int init_sphere(char *line, int i, t_objs **objs);
int init_plane(char *line, int i, t_objs **objs);
int init_square(char *line, int i, t_objs **objs);
int init_cylinder(char *line, int i, t_objs **objs);
int init_triangle(char *line, int i, t_objs **objs);
int resolution(char *line, int i, t_resolution **resolution);
int ambiance(char *line, int i, t_ambiant **ambiant);
int camera(char *line, int i, t_cams **cams);
int light(char *line, int i, t_lights **lights);
int ft_routine(double *x, char *line, int *i, int opt);
int ft_space(char *line, int i);
int ft_check_color_vdir(t_triade *check, int opt);
int ft_color(t_triade *color, char *line, int i);
int ft_coordonnees(t_triade *new, char *line, int i);
int ft_structuration(t_triade *new, char *line, int i);
int ft_vdir_tr(t_base *ptr, t_triade *p2, t_triade *p3);

#endif
