#include "mlx.h"
#include <fcntl.h>
#include "minirt.h"
#include <stdio.h>

int ft_coordonneesun(t_list *new, char *line, int i)
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
  return (i);
}

int ft_coordonneesdeux(t_list *new, char *line, int i)
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
  return (i);
}

int ft_coordonneestrois(t_list *new, char *line, int i)
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
  return (i);
}

int ft_coordonnees(t_list *new, char *line, int i, int opt)
{
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s\n", "ERROR MAP CONFIG OBJECT COORDONNEES");
    return (-1);
  }
  if (opt == 1)
    if ((i = ft_coordonneesun(new, line, i)) == -1)
      return (-1);
  if (opt == 2)
    if ((i = ft_coordonneesdeux(new, line, i)) == -1)
      return (-1);
  if (opt == 3)
    if ((i = ft_coordonneestrois(new, line, i)) == -1)
      return (-1);
  return (i);
}
