#include "mlx.h"
#include <fcntl.h>
#include "minirt.h"
#include <stdio.h>


double ft_routine(double x, char *line, int *i, int opt)
{
  double tmp;

  tmp = .0;
  printf("premer char routine : %c\n", line[*i]);
  // printf("x : %lf\n", x);
  while (line[*i] >= '0' && line[*i] <= '9')
  {
    x = x * 10 + line[*i] - 48;
    *i = *i + 1;
  }
  printf("x : %lf\n", x);
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
  else if (line[*i] != ',' && opt == 1)
      return (-1);
  printf("%lf\n", x);
  return (x);
}

int ft_coordonnees(t_list *new, char *line, int i)
{
  printf("i : %d\n", i);
  new->x = 0;
  new->x = ft_routine(new->x, line, &i, 1);
  printf("i : %d\n", i);
  if (line[i++] != ',')
    return (-1);
  printf("i : %d\n", i);
  new->y = ft_routine(new->y, line, &i, 1);
  printf("i : %d\n", i);
  if (line[i++] != ',')
    return (-1);
  printf("i : %d\n", i);
  new->z = ft_routine(new->z, line, &i, 2);
  printf("i : %d\n", i);
  return (i);
}

int ft_dimensions(t_list *new, char *line, int i, int opt)
{
  if (opt == 1)
    new->diameter = ft_routine(new->diameter, line, &i, 2);
  if (opt == 2)
    new->height = ft_routine(new->height, line, &i, 2);
  if (opt != 1 && opt != 2)
  {
    new->vx = ft_routine(new->vx, line, &i, 1);
    if (line[i++] != ',')
      return (-1);
    new->vy = ft_routine(new->vy, line, &i, 1);
    if (line[i++] != ',')
          return (-1);
    new->vz = ft_routine(new->vz, line, &i, 2);
  }
  return (i);
}

int ft_color(t_list *new, char *line, int i)
{
  while (line[i] >= '0' && line[i] <= '9')
    new->color1 = new->color1 * 10 + line[i++] - 48;
  if (line[i++] != ',')
    return (-1);
  while(line[i] >= '0' && line[i] <='9')
    new->color2 = new->color2 * 10 + line[i++] - 48;
  if (line[i++] != ',')
    return (-1);
  while(line[i] >= '0' && line[i] <='9')
    new->color3 = new->color3 * 10 + line[i++] - 48;
  return (i);
}

int ft_space(char *line, int i)
{
  while (line[i] < '0' || line[i] > '9')
  {
    printf("%c\n", line[i]);
    if (line[i++] != ' ')
      return (-1);
  }
  return (i);
}
