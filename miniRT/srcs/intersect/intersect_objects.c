#include "../../minirt.h"

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
  return (-1);
}

double inside_triangle(double test, t_objs *ptr, t_triade *origins, t_triade ray)
{
  t_triade p;
  t_triade side[3];
  t_triade i[3];
  t_triade j[3];


  p.x = origins->x + test * ray.x;
  p.y = origins->y + test * ray.y;
  p.z = origins->z + test * ray.z;
  side[0] = vector(ptr->p2, ptr->base->origins);
  side[1] = vector(ptr->p3, ptr->p2);
  side[2] = vector(ptr->base->origins, ptr->p3);
  i[0] = vector(&p, ptr->base->origins);
  i[1] = vector(&p, ptr->p2);
  i[2] = vector(&p, ptr->p3);
  j[0] = crossprod(side[0], i[0]);
  j[1] = crossprod(side[1], i[1]);
  j[2] = crossprod(side[2], i[2]);
  if ((scale(ptr->base->vdir, &j[0]) > 0)
    && (scale(ptr->base->vdir, &j[1]) > 0)
    && (scale(ptr->base->vdir, &j[2]) > 0))
      return (1);
  return (-1);
}

double intersect_plan(t_triade ray, t_objs *ptr, t_triade *origins)
{
  t_triade alpha;
  t_triade vdir;
  t_map *useless;

  vdir = get_norme(*ptr->base->vdir);
  alpha.x = (ptr->base->origins->x - origins->x) * vdir.x;
  alpha.x += (ptr->base->origins->y - origins->y) * vdir.y;
  alpha.x += (ptr->base->origins->z - origins->z) * vdir.z;
  alpha.y = ray.x * vdir.x;
  alpha.y += ray.y * vdir.y;
  alpha.y += ray.z * vdir.z;
  alpha.z = alpha.x / alpha.y;
  if (alpha.z >= 0)
  {
    if (ptr->type == 3)
      return (alpha.z);
    if (ptr->type == 2)
      if (inside_square(alpha.z, ptr, ray, origins) == 1)
        return (alpha.z);
    if (ptr->type == 5)
      if (inside_triangle(alpha.z, ptr, origins, ray) == 1)
        return (alpha.z);
  }
  return (-1);
}

double intersect_sphere(t_triade ray, t_objs *ptr, t_triade *origins)
{
  t_triade alpha;
  t_triade polynome;

  polynome.x = ray.x * ray.x + ray.y * ray.y + ray.z * ray.z;
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

double calcul_polynome(double x, double y, double z, int opt)
{
  t_triade alpha;

  alpha.z = pow(y, 2) - (4 * x * z);
  if (alpha.z >= 0)
  {
    alpha.x = (-y - sqrt(alpha.z)) / (2 * x);
    alpha.y = (-y + sqrt(alpha.z)) / (2 * x);
    if (alpha.y < 0)
      return (-1);
    if (opt == 1)
    {
      if (alpha.x >= 0)
        return (alpha.x);
    }
    else if (opt == 2)
    {
      if (alpha.x < alpha.y)
        return (alpha.y);
    }
    return (alpha.y);
  }
  return (-1);
}

double intersect_cy(t_triade ray, t_objs *ptr, t_triade *origins, double *alpha)
{
  t_triade x;
  t_triade y;
  t_triade p;
  t_triade v;
  double ret[4];

  v = subs(*origins, *ptr->base->origins);
  x = subs(ray, vector_n(*ptr->base->vdir, scale(&ray, ptr->base->vdir)));
  y = subs(subs(*origins, *ptr->base->origins), vector_n(*ptr->base->vdir, scale(&v, ptr->base->vdir)));
  ret[0] = calcul_polynome(scale(&x, &x), 2 * scale(&x, &y), (scale(&y, &y) - pow((ptr->diam / 2), 2)), 1);
  ret[1] = calcul_polynome(scale(&x, &x), 2 * scale(&x, &y), (scale(&y, &y) - pow((ptr->diam / 2), 2)), 2);
  p = subs(vector_n(ray, ret[0]), subs(*ptr->base->origins, *origins));
  ret[2] = scale(ptr->base->vdir, &p);
  p = subs(vector_n(ray, ret[1]), subs(*ptr->base->origins, *origins));
  ret[3] = scale(ptr->base->vdir, &p);
  if (ret[3] < ptr->diam && ret[3] > 0 && ret[1] >= 0 && ret[1] < *alpha)
    return (ret[1]);
  if (ret[2] < ptr->diam && ret[2] > 0 && ret[0] >= 0 && ret[1] < *alpha)
    return (ret[0]);
  return (-1);
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
          if (test < *alpha || *alpha == -1)
          {
            *alpha = test;
            ret = ptr;
          }
    if (ptr->type == 5)
      if ((test = intersect_plan(ray, ptr, origins)) >= 0)
          if (test < *alpha || *alpha == -1)
          {
            *alpha = test;
            ret = ptr;
          }
    if (ptr->type == 4)
      if ((test = intersect_cy(ray, ptr, origins, alpha)) >= 0)
        if (test < *alpha || *alpha == -1)
        {
          *alpha = test;
          ret = ptr;
        }
    ptr = ptr->next;
  }
  return (ret);
}
