#include "mlx.h"
#include <fcntl.h>
#include "minirt.h"
#include <stdio.h>


double ft_routine(double x, char *line, int *i, int opt)
{
  // printf("%s\n", "entree routine");
  double tmp;
  int div;
  int neg;

  tmp = .0;
  div = 0;
  neg = 1;
  // printf("premer char routine : %c\n", line[*i]);
  if (line[*i] == '-')
  {
    neg = -1;
    *i = *i + 1;
  }
  while (line[*i] >= '0' && line[*i] <= '9')
  {
    x = x * 10 + line[*i] - 48;
    *i = *i + 1;
  }
  // printf("%s%lf\n", "fin premier nombre x = ", x);
  // printf("char en cours : %c\n", line[*i]);
  if (line[*i] == '.')
  {
    // printf("%s\n", "debut second nombre");
    *i = *i + 1;
    while (line[*i] >= '0' && line[*i] <= '9')
    {
      tmp = tmp * 10 + line[*i] - 48;
      div++;
      *i = *i + 1;
    }
    while (div-- > 0)
      tmp = tmp / 10;
    x = x + tmp;
    // printf("%s%lf\n", "fin boucle second nombre x = ", x);
  }
  else if (line[*i] != ',' && opt == 1)
  {
    printf("%s\n", "sortie ERREUR routine");
    return (-1);
  }
  // printf("%s %lf   %lf   %d\n", "sortie correct routine", x, x*neg, neg);
  return (x * neg);
}

int ft_coordonnees(t_list *new, char *line, int i, int opt)
{
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s\n", "ERROR MAP CONFIG OBJECT COORDONNEES");
    return (-1);
  }
  if (opt == 1)
  {
    if ((new->x = ft_routine(new->x, line, &i, 1)) == -1)
    {
      printf("%s\n", "ERROR MAP CONFIG OBJECT COORDONNEES");
      return (-1);
    }
    if (line[i++] != ',')
    {
      printf("%s\n", "ERROR MAP CONFIG OBJECT COORDONNEES");
      return (-1);
    }
    if ((new->y = ft_routine(new->y, line, &i, 1)) == -1)
    {
      printf("%s\n", "ERROR MAP CONFIG OBJECT COORDONNEES");
      return (-1);
    }
    if (line[i++] != ',')
    {
      printf("%s\n", "ERROR MAP CONFIG OBJECT COORDONNEES");
      return (-1);
    }
    if ((new->z = ft_routine(new->z, line, &i, 2)) == -1)
    {
      printf("%s\n", "ERROR MAP CONFIG OBJECT COORDONNEES");
      return (-1);
    }
  }
  if (opt == 2)
  {
    if ((new->x2 = ft_routine(new->x2, line, &i, 1)) == -1)
    {
      printf("%s\n", "ERROR MAP CONFIG OBJECT COORDONNEES");
      return (-1);
    }
    if (line[i++] != ',')
    {
      printf("%s\n", "ERROR MAP CONFIG OBJECT COORDONNEES");
      return (-1);
    }
    if ((new->y2 = ft_routine(new->y2, line, &i, 1)) == -1)
    {
      printf("%s\n", "ERROR MAP CONFIG OBJECT COORDONNEES");
      return (-1);
    }
    if (line[i++] != ',')
    {
      printf("%s\n", "ERROR MAP CONFIG OBJECT COORDONNEES");
      return (-1);
    }
    if ((new->z2 = ft_routine(new->z2, line, &i, 2)) == -1)
    {
      printf("%s\n", "ERROR MAP CONFIG OBJECT COORDONNEES");
      return (-1);
    }
  }
  if (opt == 3)
  {
    if ((new->x3 = ft_routine(new->x3, line, &i, 1)) == -1)
    {
      printf("%s\n", "ERROR MAP CONFIG OBJECT COORDONNEES");
      return (-1);
    }
    if (line[i++] != ',')
    {
      printf("%s\n", "ERROR MAP CONFIG OBJECT COORDONNEES");
      return (-1);
    }
    if ((new->y3 = ft_routine(new->y3, line, &i, 1)) == -1)
    {
      printf("%s\n", "ERROR MAP CONFIG OBJECT COORDONNEES");
      return (-1);
    }
    if (line[i++] != ',')
    {
      printf("%s\n", "ERROR MAP CONFIG OBJECT COORDONNEES");
      return (-1);
    }
    if ((new->z3 = ft_routine(new->z3, line, &i, 2)) == -1)
    {
      printf("%s\n", "ERROR MAP CONFIG OBJECT COORDONNEES");
      return (-1);
    }
  }
  return (i);
}

int ft_structuration(t_list *new, char *line, int i, int opt)
{
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s\n", "ERROR MAP CONFIG OBJECT COORDONNEES");
    return (-1);
  }
  if (opt == 1)
    if ((new->diameter = ft_routine(new->diameter, line, &i, 2)) == -1)
    {
      printf("%s\n", "ERROR MAP CONFIG OBJECT DIAMETER");
      return (-1);
    }
  if (opt == 2)
    if ((new->height = ft_routine(new->height, line, &i, 2)) == -1)
    {
      printf("%s\n", "ERROR MAP CONFIG OBJECT HEIGHT");
      return (-1);
    }
  if (opt != 1 && opt != 2)
  {
    if ((new->vx = ft_routine(new->vx, line, &i, 1)) == -1)
    {
      printf("%s\n", "ERROR MAP CONFIG OBJECT structuration");
      return (-1);
    }
    if (line[i++] != ',')
      return (-1);
    if ((new->vy = ft_routine(new->vy, line, &i, 1)) == -1)
    {
      printf("%s\n", "ERROR MAP CONFIG OBJECT structuration");
      return (-1);
    }
    if (line[i++] != ',')
      return (-1);
    if ((new->vz = ft_routine(new->vz, line, &i, 2)) == -1)
    {
      printf("%s\n", "ERROR MAP CONFIG OBJECT structuration");
      return (-1);
    }
  }
  return (i);
}

int ft_color(t_list *new, char *line, int i)
{
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s\n", "ERROR MAP CONFIG OBJECT COORDONNEES");
    return (-1);
  }
  while (line[i] >= '0' && line[i] <= '9')
    new->color1 = new->color1 * 10 + line[i++] - 48;
  if (line[i++] != ',')
  {
    printf("%s\n", "ERROR MAP CONFIG RGB");
    return (-1);
  }
  while(line[i] >= '0' && line[i] <='9')
    new->color2 = new->color2 * 10 + line[i++] - 48;
  if (line[i++] != ',')
  {
    printf("%s\n", "ERROR MAP CONFIG RGB");
    return (-1);
  }
  while(line[i] >= '0' && line[i] <='9')
    new->color3 = new->color3 * 10 + line[i++] - 48;
  return (i);
}

int ft_space(char *line, int i)
{
  while (line[i] && (line[i] < '0' || line[i] > '9') && line[i] != '-')
  {
    if (line[i++] != ' ')
    {
      printf("%s\n", "ERROR MAP CONFIG, CHARACTER UNEXPECTED");
      return (-1);
    }
  }
  return (i);
}
