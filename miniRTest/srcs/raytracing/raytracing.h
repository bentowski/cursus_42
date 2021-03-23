#include "../../minirt.h"

#ifndef RAYTRACING_H
# define RAYTRACING_H

t_objs *intersect(t_objs *ptr, t_triade *origins, t_triade ray, double *alpha);
double intersect_sphere(t_triade ray, t_objs *ptr, t_triade *origins);
double intersect_plan(t_triade ray, t_objs *ptr, t_triade *origins);
double intersect_cylinder(t_triade ray, t_objs *ptr, t_triade *origins, double *alpha);
double calcul_polynome_cylinder(double x, double y, double z, int opt);
t_triade get_color(t_ambiant *ambiant, t_lights *lights, t_objs *ptr, double intensity);

#endif
