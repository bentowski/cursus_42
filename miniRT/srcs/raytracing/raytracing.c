#include "raytracing.h"

static int get_shadows(t_map *map, t_triade ray, t_triade *p, double ldist)
{
  t_objs *ptr;
  double	(*functions[5])(t_triade, t_objs *, t_triade *);
  double alpha;

  ptr = map->objs;
  functions[0] = intersect_sphere;
  functions[1] = intersect_plan;
  functions[2] = intersect_plan;
  functions[3] = intersect_cy;
  functions[4] = intersect_plan;
  while (ptr->next)
  {
    if ((alpha = (*functions[ptr->type - 1])(ray, ptr, p)) >= 0)
      if (alpha <= ldist)
        return (1);
    ptr = ptr->next;
  }
  return (1);
}

static double get_light(t_map *map, t_triade n, t_triade p, t_lights *light)
{
  double ret;
  double lightdist;
  t_triade ldir;

  ret = 0;
  ldir = subs(*light->base->origins, p);
  lightdist = scale(&ldir, &ldir);
  ldir = get_norme(ldir);
  if (scale(&ldir, &n) >= 0)
    ret = ((light->lumens) * scale(&ldir, &n)) / scale(&ldir, &ldir);
  if (ret < 0)
    ret = 0;
  p = add_vectors(p, increase(p, 0.001));
  return (ret * get_shadows(map, ldir, &p, lightdist));
}

static unsigned long int color_ret(t_map *map, t_objs *target, t_triade p)
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
    ret = add_vectors(ret, add);
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

static t_objs *intersect(t_objs *ptr, t_triade *o, t_triade ray, double *alpha)
{
  double	(*functions[5])(t_triade, t_objs *, t_triade *);
  t_objs *ret;
  double test;

  ret = NULL;
  functions[0] = intersect_sphere;
  functions[1] = intersect_plan;
  functions[2] = intersect_plan;
  functions[3] = intersect_cy;
  functions[4] = intersect_plan;
  while (ptr->next)
  {
    if ((test = (*functions[ptr->type - 1])(ray, ptr, o)) >= 0)
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
