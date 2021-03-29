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
