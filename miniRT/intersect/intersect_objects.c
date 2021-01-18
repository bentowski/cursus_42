#include "../minirt.h"

double intersect_plan(t_triade *ray, t_objs *ptr, t_map *map)
{
  t_triade alpha;

  alpha.x = (ptr->base->origins->x - map->cams->base->origins->x) * ptr->base->vdir->x;
  alpha.x += (ptr->base->origins->y - map->cams->base->origins->y) * ptr->base->vdir->y;
  alpha.x += (ptr->base->origins->z - map->cams->base->origins->z) * ptr->base->vdir->z;
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

  alpha.x = 0;
  alpha.y = 0;
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
    if (alpha.y < 0)
      return (-1);
    if (alpha.x > 0)
      return (alpha.x);
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

int intersect(t_map *map, t_triade *ray)
{
  t_objs *ptr;
  double t;
  t_triade p;
  t_triade normale;
  double normalisation;
  t_triade ldir;
  double intensity;
  unsigned long int ret;
  int color1;
  int color2;
  int color3;
  double angle;
  double normalisation2;

  ptr = map->objs;
  while (ptr->next)
  {
    intensity = 0;
    if (ptr->type == 1)
     if ((t = intersect_sphere(ray, ptr, map)) >= 0)
     {
       p.x = map->cams->base->origins->x + (t * ray->x);
       p.y = map->cams->base->origins->y + (t * ray->y);
       p.z = map->cams->base->origins->z + (t * ray->z);
       normale.x = p.x - ptr->base->origins->x;
       normale.y = p.y - ptr->base->origins->y;
       normale.z = p.z - ptr->base->origins->z;
       normalisation = sqrt(pow(normale.x, 2) + pow(normale.y, 2) + pow(normale.z, 2));
       normale.x = normale.x / normalisation;
       normale.y = normale.y / normalisation;
       normale.z = normale.z / normalisation;
       ldir.x = map->lights->base->origins->x - p.x;
       ldir.y = map->lights->base->origins->y - p.y;
       ldir.z = map->lights->base->origins->z - p.z;
       normalisation = sqrt(pow(ldir.x, 2) + pow(ldir.y, 2) + pow(ldir.z, 2));
       ldir.x = ldir.x / normalisation;
       ldir.y = ldir.y / normalisation;
       ldir.z = ldir.z / normalisation;
       intensity = (ldir.x * normale.x) + (ldir.y * normale.y) + (ldir.z * normale.z);
       intensity = intensity * (map->lights->lumens);
       intensity = intensity / (pow(ldir.x, 2) + pow(ldir.y, 2) + pow(ldir.z, 2));
       if (intensity < 0)
         intensity = 0;
       color1 = ptr->base->color->x * intensity;
       color2 = ptr->base->color->y * intensity;
       color3 = ptr->base->color->z * intensity;
       ret = (color1 * 256 * 256) + (color2 * 256) + color3;
       printf("%lf, %p\n", intensity, ret);
       return (ret);
     }
    // if (ptr->type == 3)
    //   if ((t = intersect_plan(ray, ptr, map)) != -1)
    //   {
    //     p.x = map->cams->base->origins->x + (t * ray->x);
    //     p.y = map->cams->base->origins->y + (t * ray->y);
    //     p.z = map->cams->base->origins->z + (t * ray->z);
    //     normale.x = ptr->base->vdir->x;
    //     normale.y = ptr->base->vdir->y;
    //     normale.z = ptr->base->vdir->z;
    //     ldir.x = map->lights->base->origins->x - p.x;
    //     ldir.y = map->lights->base->origins->y - p.y;
    //     ldir.z = map->lights->base->origins->z - p.z;
    //     normalisation = sqrt(pow(ldir.x, 2) + pow(ldir.y, 2) + pow(ldir.z, 2));
    //     ldir.x = ldir.x / normalisation;
    //     ldir.y = ldir.y / normalisation;
    //     ldir.z = ldir.z / normalisation;
    //     angle = ((normale.x * ldir.x) + (normale.y * ldir.y) + (normale.z * ldir.z));
    //     intensity = (map->lights->lumens * angle);
    //     intensity = intensity / (pow(ldir.x, 2) + pow(ldir.y, 2) + pow(ldir.z, 2));
    //     if (intensity < 0)
    //       intensity = 0;
    //     printf("%lf\n", intensity);
    //     color1 = ptr->base->color->x * intensity;
    //     color2 = ptr->base->color->y * intensity;
    //     color3 = ptr->base->color->z * intensity;
    //     ret = (color1 * 256 * 256) + (color2 * 256) + color3;
    //     return (ret);
    //   }
    // if (ptr->type == 2)
    // {
      // if ((t = intersect_plan(ray, ptr, map)) != -1)
      // {
      //   p.x = map->cams->base->origins->x + (t * ray->x);
      //   p.y = map->cams->base->origins->y + (t * ray->y);
      //   p.z = map->cams->base->origins->z + (t * ray->z);
      //   normale.x = ptr->base->vdir->x;
      //   normale.y = ptr->base->vdir->y;
      //   normale.z = ptr->base->vdir->z;
      //   ldir.x = map->lights->base->origins->x - p.x;
      //   ldir.y = map->lights->base->origins->y - p.y;
      //   ldir.z = map->lights->base->origins->z - p.z;
      //   normalisation = sqrt(pow(ldir.x, 2) + pow(ldir.y, 2) + pow(ldir.z, 2));
      //   ldir.x = ldir.x / normalisation;
      //   ldir.y = ldir.y / normalisation;
      //   ldir.z = ldir.z / normalisation;
      //   angle = ((normale.x * ldir.x) + (normale.y * ldir.y) + (normale.z * ldir.z));
      //   intensity = (map->lights->lumens * angle);
      //   intensity = intensity / (pow(ldir.x, 2) + pow(ldir.y, 2) + pow(ldir.z, 2));
      //   if (intensity < 0)
      //     intensity = 0;
      //   printf("%lf\n", intensity);
      //   color1 = ptr->base->color->x * intensity;
      //   color2 = ptr->base->color->y * intensity;
      //   color3 = ptr->base->color->z * intensity;
      //   ret = (color1 * 256 * 256) + (color2 * 256) + color3;
      //   return (ret);
      // }
      // if ((t = intersect_plan(ray, ptr, map)) != -1)
      //   // if (ray->x >= (ptr->base->origins->x - ptr->height) && ray->x <= (ptr->base->origins->x + ptr->height))
      //   //   if (ray->y >= (ptr->base->origins->y - ptr->height) && ray->y <= (ptr->base->origins->y + ptr->height))
      //   //   {
      //       p.x = map->cams->base->origins->x + (t * ray->x);
      //       p.y = map->cams->base->origins->y + (t * ray->y);
      //       p.z = map->cams->base->origins->z + (t * ray->z);
      //       normale.x = ptr->base->vdir->x;
      //       normale.y = ptr->base->vdir->y;
      //       normale.z = ptr->base->vdir->z;
      //       ldir.x = map->lights->base->origins->x - p.x;
      //       ldir.y = map->lights->base->origins->y - p.y;
      //       ldir.z = map->lights->base->origins->z - p.z;
      //       normalisation = sqrt(pow(ldir.x, 2) + pow(ldir.y, 2) + pow(ldir.z, 2));
      //       ldir.x = ldir.x / normalisation;
      //       ldir.y = ldir.y / normalisation;
      //       ldir.z = ldir.z / normalisation;
      //       angle = ((normale.x * ldir.x) + (normale.y * ldir.y) + (normale.z * ldir.z));
      //       intensity = (map->lights->lumens * angle);
      //       intensity = intensity / (pow(ldir.x, 2) + pow(ldir.y, 2) + pow(ldir.z, 2));
      //       if (intensity < 0)
      //         intensity = 0;
      //       printf("%lf\n", intensity);
      //       color1 = ptr->base->color->x * intensity;
      //       color2 = ptr->base->color->y * intensity;
      //       color3 = ptr->base->color->z * intensity;
      //       ret = (color1 * 256 * 256) + (color2 * 256) + color3;
      //       return (ret);
      //     // }
    // }
    ptr = ptr->next;
  }
  return (0);
}
