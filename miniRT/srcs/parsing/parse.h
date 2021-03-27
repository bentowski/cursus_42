#include "../../minirt.h"

#ifndef RAYTRACING_H
# define RAYTRACING_H

int init_sphere(char *line, int i, t_objs **objs);
int init_plane(char *line, int i, t_objs **objs);
int init_square(char *line, int i, t_objs **objs);
int init_cylinder(char *line, int i, t_objs **objs);
int init_triangle(char *line, int i, t_objs **objs);
int ft_coordonnees(t_triade *new, char *line, int i);
int ft_structuration(t_triade *new, char *line, int i);
int ft_space(char *line, int i);
int ft_color(t_triade *color, char *line, int i);
int ft_routine(double *x, char *line, int *i, int opt);
int res(char *line, int i, t_res **res);
int ambiance(char *line, int i, t_ambiant **ambiant);
int camera(char *line, int i, t_cams **cams);
int light(char *line, int i, t_lights **lights);
int foisdeux(char *line, int *ayet, int *ryet);
int ft_check_color_vdir(t_triade *check, int opt);
int ft_vdir_tr(t_base *ptr, t_triade *p2, t_triade *p3);

#endif
