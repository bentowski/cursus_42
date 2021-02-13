#include "../minirt.h"

int get_shadows(t_map *map, t_triade ray, t_triade *p, double ldist)
{
  t_objs *ptr;
  double alpha;
  double tmp;

  ptr = map->objs;
  while (ptr->next)
  {
    // if (ptr->type == 2)
    //   if ((alpha = intersect_plan(ray, ptr, p)) >= 0)
    //     if (alpha <= ldist)
    //       return (0);
    // if (ptr->type == 5)
    //   if ((alpha = intersect_plan(ray, ptr, p)) >= 0)
    //     if (alpha <= ldist)
    //       return (0);
    // if (ptr->type == 3)
    //   if ((alpha = intersect_plan(ray, ptr, p)) >= 0)
    //     if (alpha <= ldist)
    //       return (0);
    if (ptr->type == 1)
      if ((alpha = intersect_sphere(ray, ptr, p)) >= 0)
        if (alpha <= ldist)
          return (0);
    ptr = ptr->next;
  }
  return (1);
}

double get_light(t_map *map, t_triade ldir, t_triade n, t_triade position)
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
  return (ret * get_shadows(map, ldir, &position, ldist));
}

unsigned long int ft_raytracing(t_map *map, t_triade ray)
{
  t_objs *target;
  t_triade position;
  t_triade ldir;
  t_triade n;
  t_triade reflexion;
  double t;
  double test;

  t = -1;
  target = intersect(map->objs, map->cams->base->origins, ray, &t);
  position = get_position(map->cams->base->origins, ray, t);
  ldir = get_norme(vector(map->lights->base->origins, &position));
  n = get_normale(target, position, map);
  test = (ldir.x - (2 * (ldir.x * n.x) * n.x)) * ray.x;
  test += (ldir.y - (2 * (ldir.y * n.y) * n.y)) * ray.y;
  test += (ldir.z - (2 * (ldir.z * n.z) * n.z)) * ray.z;
  // reflexion.x = ldir.x - (2 * (ldir.x * n.x) * n.x);
  // reflexion.y = ldir.y - (2 * (ldir.y * n.y) * n.y);
  // reflexion.z = ldir.z - (2 * (ldir.z * n.z) * n.z);
  // test = reflexion.x * ray.x;
  // test += reflexion.y * ray.y;
  // test += reflexion.z * ray.z;
  // if (test < 0)
  //   test = 0;
  return (get_color(map->ambiant, target, get_light(map, ldir, n, position)));
}
