#include "../../minirt.h"

double calcul_polynome_cylinder(double x, double y, double z, int opt)
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
