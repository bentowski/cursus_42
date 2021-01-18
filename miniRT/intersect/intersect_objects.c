#include "../minirt.h"

double intersect_plan(t_triade *ray, t_objs *ptr, t_map *map)
{
  t_triade alpha;

  alpha.x = (ptr->base->origins->x - map->cams->base->origins->x);
  alpha.x = alpha.x * ptr->base->vdir->x;
  alpha.z = (ptr->base->origins->y - map->cams->base->origins->y);
  alpha.z = alpha.z * ptr->base->vdir->y;
  alpha.x += alpha.z;
  alpha.z = (ptr->base->origins->z - map->cams->base->origins->z);
  alpha.z = alpha.z * ptr->base->vdir->z;
  alpha.x += alpha.z;
  alpha.y = ray->x * ptr->base->vdir->x;
  alpha.y += ray->y * ptr->base->vdir->y;
  alpha.y += ray->z * ptr->base->vdir->z;
  alpha.x = alpha.x / alpha.y;
  if (alpha.x >= 0)
    return (alpha.x);
  return (-1);
}

double intersect_sphere(t_triade *ray, t_objs *ptr, t_map *map)
{
  t_triade alpha;
  t_triade polynome;

  polynome.x = (ray->x * ray->x) + (ray->y * ray->y) + (ray->z * ray->z);
  polynome.y = ray->x * (map->cams->base->origins->x - ptr->base->origins->x);
  polynome.y += ray->y * (map->cams->base->origins->y - ptr->base->origins->y);
  polynome.y += ray->z * (map->cams->base->origins->z - ptr->base->origins->z);
  polynome.z = pow((map->cams->base->origins->x - ptr->base->origins->x), 2);
  polynome.z += pow((map->cams->base->origins->y - ptr->base->origins->y), 2);
  polynome.z += pow((map->cams->base->origins->z - ptr->base->origins->z), 2);
  polynome.z -= (ptr->diam / 2) * (ptr->diam/ 2);
  alpha.z = ((2 * polynome.y) * (2 * polynome.y)) - 4 * polynome.x * polynome.z;
  if (alpha.z >= 0)
  {
    alpha.x = (-polynome.y - sqrt(alpha.z)) / (2 * polynome.x);
    alpha.y = (-polynome.y + sqrt(alpha.z)) / (2 * polynome.x);
    if (alpha.x > 0)
      return (alpha.x);
    if (alpha.y > 0)
      return (alpha.y);
  }
  return (-1);
}

int intersect_cylinder(t_triade *ray, t_objs *ptr, t_map *map)
{
  t_triade alpha;
  t_triade polynome;

  alpha.x = (ptr->base->origins->x - map->cams->base->origins->x) * ptr->base->vdir->x;
  alpha.x += (ptr->base->origins->y - map->cams->base->origins->y) * ptr->base->vdir->y;
  alpha.x += (ptr->base->origins->z - map->cams->base->origins->z) * ptr->base->vdir->z;
  alpha.y = ray->x * ptr->base->vdir->x;
  alpha.y += ray->y * ptr->base->vdir->y;
  alpha.y += ray->z * ptr->base->vdir->z;
  alpha.z = alpha.x / alpha.y;
  polynome.x = (ray->x * ray->x) + (ray->y * ray->y) + (ray->z * ray->z);
  polynome.x = polynome.x * (alpha.z * alpha.z);
  polynome.y = (2 * alpha.z) * ((ray->x * (map->cams->base->origins->x - ptr->base->origins->x)));
  polynome.y += (2 * alpha.z) * ((ray->y * (map->cams->base->origins->y - ptr->base->origins->y)));
  polynome.y += (2 * alpha.z) * ((ray->z * (map->cams->base->origins->z - ptr->base->origins->z)));
  polynome.z = (map->cams->base->origins->x - ptr->base->origins->x) * (map->cams->base->origins->x - ptr->base->origins->x);
  polynome.z += (map->cams->base->origins->y - ptr->base->origins->y) * (map->cams->base->origins->y - ptr->base->origins->y);
  polynome.z += (map->cams->base->origins->z - ptr->base->origins->z) * (map->cams->base->origins->z - ptr->base->origins->z);
  polynome.z -= (ptr->diam / 2) * (ptr->diam/ 2);
  if ((polynome.x + polynome.y + polynome.z) >= 0)
    return (1);
  return (-1);
}

double intersect_triangle(t_triade *ray, t_objs *ptr, t_map *map)
{

  return (-1);
}

unsigned long int intersect(t_map *map, t_triade *ray)
{
  t_objs *ptr;
  double alpha;

  ptr = map->objs;
  while (ptr->next)
  {
    if (ptr->type == 1)
     if ((alpha = intersect_sphere(ray, ptr, map)) >= 0)
       return (interlsphere(alpha, ray, ptr, map));
    if (ptr->type == 2)
      if ((alpha = intersect_plan(ray, ptr, map)) != -1)
        return (interlplan(alpha, ray, ptr, map));
    // if (ptr->type == 3)
    //   if ((alpha = intersect_plan(ray, ptr, map)) != -1)
    //     return (interlplan(alpha, ray, ptr, map));
    // if (ptr->type == 4)
    //   if ((alpha = intersect_plan(ray, ptr, map)) != -1)
    //     return (interlplan(alpha, ray, ptr, map));
    // if (ptr->type == 5)
    //   if ((alpha = intersect_plan(ray, ptr, map)) != -1)
    //     return (interlplan(alpha, ray, ptr, map));
    ptr = ptr->next;
  }
  return (-1);
}
