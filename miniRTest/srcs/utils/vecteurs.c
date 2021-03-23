#include "../../minirt.h"

<<<<<<< HEAD
// t_triade increase(t_triade t1, double n)
// {
//   t_triade t2;
//
//   t2.x = t1.x * n;
//   t2.y = t1.y * n;
//   t2.z = t1.z * n;
//   return (t2);
// }

//===========================

t_triade vector(t_triade *t1, t_triade *t2)
=======
t_triade increase(t_triade t1, double n)
{
  t_triade t2;

  t2.x = t1.x * n;
  t2.y = t1.y * n;
  t2.z = t1.z * n;
  return (t2);
}

t_triade subs(t_triade *t1, t_triade *t2)
>>>>>>> refs/remotes/origin/master
{
  t_triade t3;

  t3.x = t1->x - t2->x;
  t3.y = t1->y - t2->y;
  t3.z = t1->z - t2->z;
  return (t3);
}

<<<<<<< HEAD
t_triade subs(t_triade t1, t_triade t2)
{
  t_triade t3;

  t3.x = t1.x - t2.x;
  t3.y = t1.y - t2.y;
  t3.z = t1.z - t2.z;
  return (t3);
}

t_triade *vector_v(t_triade *t1, t_triade *t2)
{
  t_triade *t3;

  t3 = NULL;
  t3->x = t1->x - t2->x;
  t3->y = t1->y - t2->y;
  t3->z = t1->z - t2->z;
  return (t3);
}

t_triade vector_n(t_triade t1, double n)
{
  t_triade ret;

  ret.x = t1.x * n;
  ret.y = t1.y * n;
  ret.z = t1.z * n;
  return (ret);
}

t_triade add_vectors(t_triade u, t_triade v)
{
  t_triade ret;

  ret.x = u.x + v.x;
  ret.y = u.y + v.y;
  ret.z = u.z + v.z;
  return (ret);
}

t_triade get_position(t_triade *origins, t_triade ray, double t)
{
  t_triade position;

  position.x = origins->x + ray.x * t;
  position.y = origins->y + ray.y * t;
  position.z = origins->z + ray.z * t;
  return (position);
}

t_triade get_norme(t_triade target)
=======
t_triade add_vectors(t_triade *t1, t_triade *t2)
{
  t_triade t3;

  t3.x = t1->x + t2->x;
  t3.y = t1->y + t2->y;
  t3.z = t1->z + t2->z;
  return (t3);
}

t_triade crossprod(t_triade *t1, t_triade *t2)
{
  t_triade t3;

  t3.x = t1->y * t2->z - t1->z * t2->y;
  t3.y = t1->z * t2->x - t1->x * t2->z;
  t3.z = t1->x * t2->y - t1->y * t2->x;
  return (t3);
}

double scale(t_triade *t1, t_triade *t2)
{
  double ret;

  ret = t1->x * t2->x + t1->y * t2->y + t1->z * t2->z;
  return (ret);
}

t_triade normalize(t_triade target)
>>>>>>> refs/remotes/origin/master
{
  double tmp;

  tmp = sqrt(pow(target.x, 2) + pow(target.y, 2) + pow(target.z, 2));
  target.x = target.x / tmp;
  target.y = target.y / tmp;
  target.z = target.z / tmp;
  return (target);
}

t_triade get_normale(t_objs *ptr, t_triade position, t_map *map)
{
  t_triade n;

  n.x = 0;
  n.y = 0;
  n.z = 0;
  if (!ptr)
    return (n);
  if (ptr->type == 1)
<<<<<<< HEAD
    n = get_norme(vector(&position, ptr->base->origins));
  else if (ptr->type == 3 || ptr->type == 2 || ptr->type == 5)
    n = get_norme(vector(ptr->base->vdir, map->vnull));
  return (n);
}

double scale(t_triade *t1, t_triade *t2)
{
  double ret;

  ret = t1->x * t2->x + t1->y * t2->y + t1->z * t2->z;
  return (ret);
}

t_triade	crossprod(t_triade u, t_triade v)
{
	t_triade	res;

	res.x = u.y * v.z - u.z * v.y;
	res.y = u.z * v.x - u.x * v.z;
	res.z = u.x * v.y - u.y * v.x;
	return (res);
}


//===========================

// t_triade subs(t_triade *t1, t_triade *t2)
// {
//   t_triade t3;
//
//   t3.x = t1->x - t2->x;
//   t3.y = t1->y - t2->y;
//   t3.z = t1->z - t2->z;
//   return (t3);
// }

// t_triade add_vectors(t_triade *t1, t_triade *t2)
// {
//   t_triade t3;
//
//   t3.x = t1->x + t2->x;
//   t3.y = t1->y + t2->y;
//   t3.z = t1->z + t2->z;
//   return (t3);
// }
//
// t_triade crossprod(t_triade *t1, t_triade *t2)
// {
//   t_triade t3;
//
//   t3.x = t1->y * t2->z - t1->z * t2->y;
//   t3.y = t1->z * t2->x - t1->x * t2->z;
//   t3.z = t1->x * t2->y - t1->y * t2->x;
//   return (t3);
// }
//
// double scale(t_triade *t1, t_triade *t2)
// {
//   double ret;
//
//   ret = t1->x * t2->x + t1->y * t2->y + t1->z * t2->z;
//   return (ret);
// }
//
t_triade normalize(t_triade target)
{
  double tmp;

  tmp = sqrt(pow(target.x, 2) + pow(target.y, 2) + pow(target.z, 2));
  target.x = target.x / tmp;
  target.y = target.y / tmp;
  target.z = target.z / tmp;
  return (target);
}
//
// t_triade get_normale(t_objs *ptr, t_triade position, t_map *map)
// {
//   t_triade n;
//
//   n.x = 0;
//   n.y = 0;
//   n.z = 0;
//   if (!ptr)
//     return (n);
//   if (ptr->type == 1)
//     n = normalize(subs(position, *ptr->base->origins));
//   else if (ptr->type == 3 || ptr->type == 2 || ptr->type == 5)
//     n = normalize(subs(*ptr->base->vdir, *map->vnull));
//   return (n);
// }
//
// t_triade get_position(t_triade *origins, t_triade ray, double t)
// {
//   t_triade position;
//
//   position.x = origins->x + ray.x * t;
//   position.y = origins->y + ray.y * t;
//   position.z = origins->z + ray.z * t;
//   return (position);
// }
=======
    n = normalize(subs(&position, ptr->base->origins));
  else if (ptr->type == 3 || ptr->type == 2 || ptr->type == 5)
    n = normalize(subs(ptr->base->vdir, map->vnull));
  return (n);
}

t_triade get_position(t_triade *origins, t_triade ray, double t)
{
  t_triade position;

  position.x = origins->x + ray.x * t;
  position.y = origins->y + ray.y * t;
  position.z = origins->z + ray.z * t;
  return (position);
}
>>>>>>> refs/remotes/origin/master
