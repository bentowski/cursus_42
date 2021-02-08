#include "../minirt.h"

int get_shadows(t_map *map, t_triade ray, t_triade *p)
{
  t_objs *ptr;
  double alpha;

  ptr = map->objs;
  while (ptr->next)
  {
    if (ptr->type == 3)
      if ((alpha = intersect_plan(ray, ptr, p)) >= 0)
        return (0);
    if (ptr->type == 1)
      if ((alpha = intersect_sphere(ray, ptr, p)) >= 0)
        return (0);
    ptr = ptr->next;
  }
  return (1);
}

double get_intensity(t_map *map, t_triade ldir, t_triade n, t_triade position)
{
  double ldist;
  double ret;

  ret = 0;
  ldist = ldir.x * ldir.x + ldir.y * ldir.y + ldir.z * ldir.z;
  if (scale(&ldir, &n) >= 0)
    ret = ((map->lights->lumens) * scale(&ldir, &n)) / ldist;
  if (ret < 0)
    ret = 0;
  position.x += n.x * 0.001;
  position.y += n.y * 0.001;
  position.z += n.z * 0.001;
  return (ret * get_shadows(map, ldir, &position));
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
  intensity = get_intensity(map,
    get_norme(vector(map->lights->base->origins, &position)),
    get_normale(target, position, map), position);
  ret = get_color(map->ambiant, target, intensity);
  return (ret);
}
