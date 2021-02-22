#include "../minirt.h"

int get_shadows(t_map *map, t_triade ray, t_triade *p, double ldist)
{
  t_objs *ptr;
  double alpha;
  double tmp;

  ptr = map->objs;
  while (ptr->next)
  {
    if (ptr->type == 2)
      if ((alpha = intersect_plan(ray, ptr, p)) >= 0)
        if (alpha <= ldist)
          return (0);
    if (ptr->type == 5)
      if ((alpha = intersect_plan(ray, ptr, p)) >= 0)
        if (alpha <= ldist)
          return (0);
    if (ptr->type == 3)
      if ((alpha = intersect_plan(ray, ptr, p)) >= 0)
        if (alpha <= ldist)
          return (0);
    if (ptr->type == 1)
      if ((alpha = intersect_sphere(ray, ptr, p)) >= 0)
        if (alpha <= ldist)
          return (0);
    ptr = ptr->next;
  }
  return (1);
}

double get_light(t_map *map, t_triade n, t_triade position, t_lights *light)
{
  double ret;
  double lightdist;
  t_triade ldir;

  ret = 0;
  ldir = vector(light->base->origins, &position);
  lightdist = scale(&ldir, &ldir);
  ldir = get_norme(ldir);
  if (scale(&ldir, &n) >= 0)
    ret = ((light->lumens) * scale(&ldir, &n)) / scale(&ldir, &ldir);
  if (ret < 0)
    ret = 0;
  position.x += n.x * 0.001;
  position.y += n.y * 0.001;
  position.z += n.z * 0.001;
  return (ret * get_shadows(map, ldir, &position, lightdist));
}

unsigned long int ft_raytracing(t_map *map, t_triade ray)
{
  t_objs *target;
  t_triade position;
  t_triade n;
  t_triade reflexion;
  double t;
  double test;
  t_triade ret;
  t_lights *light;
  t_triade add;

  t = -1;
  target = intersect(map->objs, map->cams->base->origins, ray, &t);
  position = get_position(map->cams->base->origins, ray, t);
  n = get_normale(target, position, map);
  // test = (ldir.x - (2 * (ldir.x * n.x) * n.x)) * ray.x;
  // test += (ldir.y - (2 * (ldir.y * n.y) * n.y)) * ray.y;
  // test += (ldir.z - (2 * (ldir.z * n.z) * n.z)) * ray.z;
  light = map->lights;
  ret.x = 0;
  ret.y = 0;
  ret.z = 0;
  while (light->next)
  {
    add = get_color(map->ambiant, target, get_light(map, n, position, light));
    ret = add_vectors(ret, add);
    light = light->next;
  }
  return ((ret.x * 256 * 256 + ret.y * 256 + ret.z));
}
