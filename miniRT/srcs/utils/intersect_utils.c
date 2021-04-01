#include "../../minirt.h"

double cylinder_return(double *ret, t_objs *ptr)
{
  if (ret[1] < ret[0])
  {
    if (ret[3] < ptr->height && ret[3] > 0 && ret[1] >= 0)
      return (ret[1]);
    if (ret[2] < ptr->height && ret[2] > 0 && ret[0] >= 0)
      return (ret[0]);
  }
  if (ret[1] >= ret[0])
  {
    if (ret[2] < ptr->height && ret[2] > 0 && ret[0] >= 0)
      return (ret[0]);
    if (ret[3] < ptr->height && ret[3] > 0 && ret[1] >= 0)
      return (ret[1]);
  }
  return (-1);
}

double ft_angle(t_triade *t1, t_triade *t2)
{
  double angle;

  angle = scale(t1, t2) / sqrt(scale(t1, t1) * scale(t2, t2));
  return (angle);
}
