#include "../../minirt.h"

#ifndef RAYTRACING_H
# define RAYTRACING_H

double intersect_cy(t_triade ray, t_objs *ptr, t_triade *origins);
double intersect_sphere(t_triade ray, t_objs *ptr, t_triade *origins);
double intersect_plan(t_triade ray, t_objs *ptr, t_triade *origins);
t_triade get_color(t_ambiant *ambiant, t_lights *lights, t_objs *ptr, double intensity);
unsigned long int interlsphere(double t, t_triade ray, t_objs *ptr, t_map *map);
unsigned long int interlplan(double t, t_triade ray, t_objs *ptr, t_map *map);
t_triade get_position(t_triade *origins, t_triade ray, double t);
double calcul_polynome(double x, double y, double z, int opt);
t_triade get_normale(t_objs *ptr, t_triade position, t_map *map);
t_triade *vector_v(t_triade *t1, t_triade *t2);

#endif
