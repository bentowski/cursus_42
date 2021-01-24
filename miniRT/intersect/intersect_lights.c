#include "../minirt.h"

unsigned long int interlsphere(double t, t_triade *ray, t_objs *ptr, t_map *map)
{
  int color1;
  int color2;
  int color3;
  double angle;
  double intensity;
  double normalisation;
  double normalisation2;
  t_triade normale;
  t_triade ldir;
  t_triade p;
  unsigned long int ret;

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
  ldir.x = p.x - map->lights->base->origins->x;
  ldir.y = p.y - map->lights->base->origins->y;
  ldir.z = p.z - map->lights->base->origins->z;
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
  return (ret);
}

unsigned long int interlplan(double t, t_triade *ray, t_objs *ptr, t_map *map)
{
  int color1;
  int color2;
  int color3;
  double angle;
  double intensity;
  double normalisation;
  double normalisation2;
  t_triade normale;
  t_triade ldir;
  t_triade p;
  unsigned long int ret;

  p.x = map->cams->base->origins->x + (t * ray->x);
  p.y = map->cams->base->origins->y + (t * ray->y);
  p.z = map->cams->base->origins->z + (t * ray->z);
  normale.x = ptr->base->vdir->x;
  normale.y = ptr->base->vdir->y;
  normale.z = ptr->base->vdir->z;
  ldir.x = map->lights->base->origins->x - p.x;
  ldir.y = map->lights->base->origins->y - p.y;
  ldir.z = map->lights->base->origins->z - p.z;
  normalisation = sqrt(pow(ldir.x, 2) + pow(ldir.y, 2) + pow(ldir.z, 2));
  ldir.x = ldir.x / normalisation;
  ldir.y = ldir.y / normalisation;
  ldir.z = ldir.z / normalisation;
  angle = ((normale.x * ldir.x) + (normale.y * ldir.y) + (normale.z * ldir.z));
  intensity = (map->lights->lumens * angle);
  intensity = intensity / (pow(ldir.x, 2) + pow(ldir.y, 2) + pow(ldir.z, 2));
  if (intensity < 0)
    intensity = 0;
  printf("%lf\n", intensity);
  color1 = ptr->base->color->x * intensity;
  color2 = ptr->base->color->y * intensity;
  color3 = ptr->base->color->z * intensity;
  ret = (color1 * 256 * 256) + (color2 * 256) + color3;
  return (ret);
}