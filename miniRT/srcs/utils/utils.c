#include "../../minirt.h"

t_triade get_norme(t_triade target)
{
  double tmp;

  tmp = sqrt(pow(target.x, 2) + pow(target.y, 2) + pow(target.z, 2));
  target.x = target.x / tmp;
  target.y = target.y / tmp;
  target.z = target.z / tmp;
  return (target);
}

t_triade vector(t_triade *t1, t_triade *t2)
{
  t_triade t3;

  t3.x = t1->x - t2->x;
  t3.y = t1->y - t2->y;
  t3.z = t1->z - t2->z;
  return (t3);
}

t_triade get_position(t_triade *origins, t_triade ray, double t)
{
  t_triade position;

  position.x = origins->x + ray.x * t;
  position.y = origins->y + ray.y * t;
  position.z = origins->z + ray.z * t;
  return (position);
}

t_triade get_normale(t_objs *ptr, t_triade position, t_map *map)
{
  t_triade n;

  if (!ptr)
    return (n);
  if (ptr->type == 1)
    n = get_norme(vector(&position, ptr->base->origins));
  else if (ptr->type == 3 || ptr->type == 2)
    n = get_norme(vector(ptr->base->vdir, map->vnull));
  return (n);
}

double scale(t_triade *t1, t_triade *t2)
{
  double ret;

  ret = t1->x * t2->x + t1->y * t2->y + t1->z * t2->z;
  return (ret);
}
