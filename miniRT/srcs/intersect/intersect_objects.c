#include "../../minirt.h"

double intersect_plan(t_triade ray, t_objs *ptr, t_triade *origins)
{
  t_triade alpha;
  t_triade vdir;

  vdir = get_norme(*ptr->base->vdir);
  alpha.x = (ptr->base->origins->x - origins->x) * vdir.x;
  alpha.x += (ptr->base->origins->y - origins->y) * vdir.y;
  alpha.x += (ptr->base->origins->z - origins->z) * vdir.z;
  alpha.y = ray.x * vdir.x;
  alpha.y += ray.y * vdir.y;
  alpha.y += ray.z * vdir.z;
  alpha.z = alpha.x / alpha.y;
  if (alpha.z >= 0)
    return (alpha.z);
  return (-1);
}

double intersect_sphere(t_triade ray, t_objs *ptr, t_triade *origins)
{
  t_triade alpha;
  t_triade polynome;

  polynome.x = 1;
  polynome.y = ray.x * (origins->x - ptr->base->origins->x);
  polynome.y += ray.y * (origins->y - ptr->base->origins->y);
  polynome.y += ray.z * (origins->z - ptr->base->origins->z);
  polynome.y = polynome.y * 2;
  polynome.z = pow((origins->x - ptr->base->origins->x), 2);
  polynome.z += pow((origins->y - ptr->base->origins->y), 2);
  polynome.z += pow((origins->z - ptr->base->origins->z), 2);
  polynome.z -= (ptr->diam / 2) * (ptr->diam/ 2);
  alpha.z = ((polynome.y) * (polynome.y)) - (4 * polynome.x * polynome.z);
  if (alpha.z >= 0)
  {
    alpha.x = (-polynome.y - sqrt(alpha.z)) / (2 * polynome.x);
    alpha.y = (-polynome.y + sqrt(alpha.z)) / (2 * polynome.x);
    if (alpha.y < 0)
      return (-1);
    if (alpha.x >= 0)
      return (alpha.x);
    return (alpha.y);
  }
  return (-1);
}

int intersect_cylinder(t_triade ray, t_objs *ptr, t_triade *origins)
{
  t_triade alpha;
  t_triade polynome;

  alpha.x = (ptr->base->origins->x - origins->x) * ptr->base->vdir->x;
  alpha.x += (ptr->base->origins->y - origins->y) * ptr->base->vdir->y;
  alpha.x += (ptr->base->origins->z - origins->z) * ptr->base->vdir->z;
  alpha.y = ray.x * ptr->base->vdir->x;
  alpha.y += ray.y * ptr->base->vdir->y;
  alpha.y += ray.z * ptr->base->vdir->z;
  alpha.z = alpha.x / alpha.y;
  polynome.x = (ray.x * ray.x) + (ray.y * ray.y) + (ray.z * ray.z);
  polynome.x = polynome.x * (alpha.z * alpha.z);
  polynome.y = (2 * alpha.z) * ((ray.x * (origins->x - ptr->base->origins->x)));
  polynome.y += (2 * alpha.z) * ((ray.y * (origins->y - ptr->base->origins->y)));
  polynome.y += (2 * alpha.z) * ((ray.z * (origins->z - ptr->base->origins->z)));
  polynome.z = (origins->x - ptr->base->origins->x) * (origins->x - ptr->base->origins->x);
  polynome.z += (origins->y - ptr->base->origins->y) * (origins->y - ptr->base->origins->y);
  polynome.z += (origins->z - ptr->base->origins->z) * (origins->z - ptr->base->origins->z);
  polynome.z -= (ptr->diam / 2) * (ptr->diam/ 2);
  if ((polynome.x + polynome.y + polynome.z) >= 0)
    return (1);
  return (-1);
}

double intersect_triangle(t_triade ray, t_objs *ptr, t_map *map)
{

  return (-1);
}

int inside_square(double test, t_objs *ptr, t_triade ray, t_triade *origins)
{
  t_triade p;
  t_triade dist;
  double inside;

  inside = ptr->height / 2;
  p.x = origins->x + test * ray.x;
  p.y = origins->y + test * ray.y;
  p.z = origins->z + test * ray.z;
  dist.x = fabs(p.x - ptr->base->origins->x);
  dist.y = fabs(p.y - ptr->base->origins->y);
  dist.z = fabs(p.z - ptr->base->origins->z);
  if (dist.x <= inside && dist.y <= inside && dist.z <= inside)
    return(1);
  return (0);
}

t_objs *intersect(t_objs *ptr, t_triade *origins, t_triade ray, double *alpha)
{
  t_objs *ret;
  double test;

  ret = NULL;
  while (ptr->next)
  {
    if (ptr->type == 3)
      if ((test = intersect_plan(ray, ptr, origins)) >= 0)
        if (test < *alpha || *alpha == -1)
        {
          *alpha = test;
          ret = ptr;
        }
    if (ptr->type == 1)
      if ((test = intersect_sphere(ray, ptr, origins)) >= 0)
        if (test < *alpha || *alpha == -1)
        {
          *alpha = test;
          ret = ptr;
        }
    if (ptr->type == 2)
      if ((test = intersect_plan(ray, ptr, origins)) >= 0)
        if (inside_square(test, ptr, ray, origins))
          if (test < *alpha || *alpha == -1)
          {
            *alpha = test;
            ret = ptr;
          }
    ptr = ptr->next;
  }
  return (ret);
}
