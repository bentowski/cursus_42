#include "../minirt.h"

double get_intensity(t_map *map, t_triade ldir, t_triade n)
{
  double ldist;
  double ret;

  ret = 0;
  ldist = ldir.x * ldir.x + ldir.y * ldir.y + ldir.z * ldir.z;
  if (scale(&ldir, &n) >= 0)
    ret = ((map->lights->lumens) * scale(&ldir, &n)) / ldist;
  if (ret < 0)
    ret = 0;
  return (ret);
}

unsigned long int ft_raytracing(t_map *map, t_triade ray)
{
  t_objs *target;
  t_triade position;
  double intensity;
  double t;
  unsigned long int ret;

  ret = 255;
  t = -1;
  target = intersect(map->objs, map->cams->base->origins, ray, &t);
  position = get_position(map->cams->base->origins, ray, t);
  intensity = get_intensity(map, get_norme(vector(map->lights->base->origins, &position)), get_normale(target, position, map));
  ret = get_color(map->ambiant, target, intensity);
  return (ret);
}
