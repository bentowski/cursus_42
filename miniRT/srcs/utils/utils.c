#include "../../minirt.h"

void  my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

double calcul_polynome(double x, double y, double z, int opt)
{
  t_triade alpha;

  alpha.z = pow(y, 2) - (4 * x * z);
  if (alpha.z >= 0)
  {
    alpha.x = (-y - sqrt(alpha.z)) / (2 * x);
    alpha.y = (-y + sqrt(alpha.z)) / (2 * x);
    if (alpha.y < 0)
      return (-1);
    if (opt == 1)
    {
      if (alpha.x >= 0)
        return (alpha.x);
    }
    else if (opt == 2)
    {
      if (alpha.x < alpha.y)
        return (alpha.y);
    }
    return (alpha.y);
  }
  return (-1);
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
  t_triade tmp;
  double x;

  n.x = 0;
  n.y = 0;
  n.z = 0;
  if (!ptr)
    return (n);
  if (ptr->type == 1)
    n = get_norme(subs(position, *ptr->base->origins));
  else if (ptr->type == 4)
  {
    // printf("%s\n", "OK");
    tmp = subs(position, *ptr->base->origins);
    x = scale(&tmp, ptr->base->vdir);
    tmp = increase(*ptr->base->vdir, x);
    n = add_vectors(*ptr->base->origins, tmp);
    n = get_norme(subs(position, n));
  }
  else if (ptr->type == 2 || ptr->type == 3 || ptr->type == 5)
    n = get_norme(subs(*ptr->base->vdir, *map->vnull));
  return (n);
}
