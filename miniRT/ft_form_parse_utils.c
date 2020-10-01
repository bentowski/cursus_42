#include "mlx.h"
#include <fcntl.h>
#include "minirt.h"
#include <stdio.h>


double ft_routine(double x, char *line, int *i, int opt)
{
  double tmp;

  tmp = .0;
  while (line[*i] >= '0' && line[*i] <= '9')
  {
    x = x * 10 + line[*i] - 48;
    *i = *i + 1;
  }
  if (line[*i] != '.')
    if (line[*i] != ',' && opt == 1)
      return (-1);
  if (line[*i] == '.')
  {
    *i = *i + 1;
    while (line[*i] >= '0' && line[*i] <= '9')
    {
      tmp = line[*i] - 48;
      x = x + tmp / 10;
      *i = *i + 1;
    }
  }
  return (x);
}

int ft_coordonnees(t_coo *coo, char *line, int i)
{
  coo->x = ft_routine(coo->x, line, &i, 1);
  if (line[i++] != ',')
    return (-1);
  coo->y = ft_routine(coo->y, line, &i, 1);
  if (line[i++] != ',')
        return (-1);
  coo->z = ft_routine(coo->z, line, &i, 2);
  return (i);
}

int ft_dimensions(t_coo *coo, char *line, int i, int opt)
{
  if (opt == 1)
    coo->diameter = ft_routine(coo->diameter, line, &i, 2);
  if (opt == 2)
    coo->height = ft_routine(coo->height, line, &i, 2);
  if (opt != 1 && opt != 2)
  {
    coo->vx = ft_routine(coo->vx, line, &i, 1);
    if (line[i++] != ',')
      return (-1);
    coo->vy = ft_routine(coo->vy, line, &i, 1);
    if (line[i++] != ',')
          return (-1);
    coo->vz = ft_routine(coo->vz, line, &i, 2);
  }
  return (i);
}

int ft_color(t_coo *coo, char *line, int i)
{
  while (line[i] >= '0' && line[i] <= '9')
    coo->color1 = coo->color1 * 10 + line[i++] - 48;
  if (line[i++] != ',')
    return (-1);
  while(line[i] >= '0' && line[i] <='9')
    coo->color2 = coo->color2 * 10 + line[i++] - 48;
  if (line[i++] != ',')
    return (-1);
  while(line[i] >= '0' && line[i] <='9')
    coo->color3 = coo->color3 * 10 + line[i++] - 48;
  return (i);
}

int ft_space(char *line, int i)
{
  while (line[i] < '0' || line[i] > '9')
    if (line[i++] != ' ')
      return (-1);
  return (i);
}
