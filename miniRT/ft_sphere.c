#include "mlx.h"
#include <fcntl.h>
#include "get_next_line.h"
#include "minirt.h"
#include <stdio.h>


double routine(double x, char *line, int *i)
{
  double tmp;

  tmp = .0;
  while (line[*i] >= '0' && line[*i] <= '9')
  {
    x = x * 10 + line[*i] - 48;
    *i = *i + 1;
  }
  if (line[*i] != '.')
    if (line[*i] != ',')
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

int coordonnees(t_coo *coo, char *line, int i)
{
  coo->x = routine(coo->x, line, &i);
  if (line[i] != ',')
    return (-1);
  i = i + 1;
  coo->y = routine(coo->y, line, &i);
  if (line[i] != ',')
        return (-1);
  i = i + 1;
  coo->z = routine(coo->z, line, &i);
  return (i);
}

int dimensions(t_coo *coo, char *line, int i)
{
  coo->diam = routine(coo->diam, line, &i);
  return (i);
}

int color(t_coo *coo, char *line, int i)
{
  while (line[i] >= '0' && line[i] <= '9')
  {
    coo->color1 = coo->color1 * 10 + line[i] - 48;
    i = i + 1;
  }
  if (line[i] != ',')
    return (-1);
  i = i + 1;
  while(line[i] >= '0' && line[i] <='9')
  {
    coo->color2 = coo->color2 * 10 + line[i] - 48;
    i = i + 1;
  }
  if (line[i] != ',')
    return (-1);
  i = i + 1;
  while(line[i] >= '0' && line[i] <='9')
  {
    coo->color3 = coo->color3 * 10 + line[i] - 48;
    i = i + 1;
  }
  return (i);
}

int init_sphere(t_coo *coo, char *line, int i)
{
  double tmp;
  int x;

  x = 0;
  tmp = .0;
  i = i + 2;
  while (line[i] < '0' || line[i] > '9')
  {
    if (line[i] != ' ')
      return (-1);
    i = i + 1;
  }
  if ((i = coordonnees(coo, line, i)) == -1)
    return (-1);
  while (line[i] < '0' || line[i] > '9')
  {
    if (line[i] != ' ')
      return (-1);
    i = i + 1;
  }
  if ((i = dimensions(coo, line, i)) == -1)
    return (-1);
  while (line[i] < '0' || line[i] > '9')
  {
    if (line[i] != ' ')
      return (-1);
    i = i + 1;
  }
  if ((i = color(coo, line, i)) == -1)
    return (-1);
  x = i;
  return (x);
}
