#include "raytracing.h"

int get_shadows(t_map *map, t_triade ray, t_triade *p, double ldist)
{
  t_objs *ptr;
  double alpha;

  ptr = map->objs;
  while (ptr->next)
  {
    if (ptr->type == 2)
      if ((alpha = intersect_plan(ray, ptr, p, &alpha)) >= 0)
        if (alpha <= ldist)
          return (0);
    if (ptr->type == 5)
      if ((alpha = intersect_plan(ray, ptr, p, &alpha)) >= 0)
        if (alpha <= ldist)
          return (0);
    if (ptr->type == 3)
      if ((alpha = intersect_plan(ray, ptr, p, &alpha)) >= 0)
        if (alpha <= ldist)
          return (0);
    if (ptr->type == 1)
      if ((alpha = intersect_sphere(ray, ptr, p, &alpha)) >= 0)
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
  ldir = subs(light->base->origins, &position);
  lightdist = scale(&ldir, &ldir);
  ldir = normalize(ldir);
  if (scale(&ldir, &n) >= 0)
    ret = ((light->lumens) * scale(&ldir, &n)) / scale(&ldir, &ldir);
  if (ret < 0)
    ret = 0;
  position.x += n.x * 0.001;
  position.y += n.y * 0.001;
  position.z += n.z * 0.001;
  return (ret * get_shadows(map, ldir, &position, lightdist));
}

unsigned long int color_ret(t_map *map, t_objs *target, t_triade p)
{
  t_triade ret;
  t_lights *light;
  t_triade n;
  t_triade add;

  light = map->lights;
  n = get_normale(target, p, map);
  ret.x = 0;
  ret.y = 0;
  ret.z = 0;
  while (light->next)
  {
    add = get_color(map->ambiant, light, target, get_light(map, n, p, light));
    ret = add_vectors(&ret, &add);
    if (ret.x > 255)
      ret.x = 255;
    if (ret.y > 255)
      ret.y = 255;
    if (ret.z > 255)
      ret.z = 255;
    light = light->next;
  }
  return ((ret.x * 256 * 256 + ret.y * 256 + ret.z));
}

t_objs *intersect(t_objs *ptr, t_triade *origins, t_triade ray, double *alpha)
{
  double	(*functions[5])(t_triade, t_objs *, t_triade *, double *);
  t_objs *ret;
  double test;

  ret = NULL;
  functions[0] = intersect_sphere;
  functions[1] = intersect_plan;
  functions[2] = intersect_plan;
  functions[3] = intersect_cylinder;
  functions[4] = intersect_plan;
  while (ptr->next)
  {
    if ((test = (*functions[ptr->type])(ray, ptr, origins, alpha)) >= 0)
      if (test < *alpha || *alpha == -1)
      {
        *alpha = test;
        ret = ptr;
      }
    ptr = ptr->next;
  }
  return (ret);
}

unsigned long int ft_raytracing(t_map *map, t_triade ray)
{
  t_objs *target;
  t_triade position;
  double t;

  t = -1;
  target = intersect(map->objs, map->cams->base->origins, ray, &t);
  position = get_position(map->cams->base->origins, ray, t);
  return (color_ret(map, target, position));
}
