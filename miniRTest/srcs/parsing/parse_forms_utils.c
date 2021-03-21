#include "parsing.h"

int ft_vecteur(t_triade *new, char *line, int i)
{
  if (ft_routine(&new->x, line, &i, 1) == -1)
  {
    printf("%s\n", "ERROR MAP CONFIG OBJECT structuration");
    return (-1);
  }
  if (line[i++] != ',')
    return (-1);
  if (ft_routine(&new->y, line, &i, 1) == -1)
  {
    printf("%s\n", "ERROR MAP CONFIG OBJECT structuration");
    return (-1);
  }
  if (line[i++] != ',')
    return (-1);
  if (ft_routine(&new->z, line, &i, 2) == -1)
  {
    printf("%s\n", "ERROR MAP CONFIG OBJECT structuration");
    return (-1);
  }
  return (i);
}

int ft_structuration(t_triade *new, char *line, int i)
{
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s\n", "ERROR MAP CONFIG OBJECT COORDONNEES");
    return (-1);
  }
  if ((i = ft_vecteur(new, line, i)) == -1)
  {
    printf("%s\n", "ERROR MAP CONFIG OBJECT COORDONNEES");
    return (-1);
  }
  return (i);
}

int ft_color(t_triade *color, char *line, int i)
{
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s\n", "ERROR MAP CONFIG OBJECT COORDONNEES");
    return (-1);
  }
  while (line[i] >= '0' && line[i] <= '9')
    color->x = color->x * 10 + line[i++] - 48;
  if (line[i++] != ',')
  {
    printf("%s\n", "ERROR MAP CONFIG RGB");
    return (-1);
  }
  while(line[i] >= '0' && line[i] <='9')
    color->y = color->y * 10 + line[i++] - 48;
  if (line[i++] != ',')
  {
    printf("%s\n", "ERROR MAP CONFIG RGB");
    return (-1);
  }
  while(line[i] >= '0' && line[i] <='9')
    color->z = color->z * 10 + line[i++] - 48;
  return (i);
}

int ft_coordonnees(t_triade *new, char *line, int i)
{

  if ((i = ft_space(line, i)) != -1)
    if (ft_routine(&new->x, line, &i, 1) != -1)
      if (line[i++] == ',')
        if (ft_routine(&new->y, line, &i, 1) != -1)
          if (line[i++] == ',')
            if (ft_routine(&new->z, line, &i, 2) != -1)
              return (i);
  return (-1);
}

int ft_vdir_tr(t_base *ptr, t_triade *p2, t_triade *p3)
{
  t_triade n;
  t_triade n2;

  n.x = p2->x - ptr->origins->x;
  n.y = p2->y - ptr->origins->y;
  n.z = p2->z - ptr->origins->z;
  n2.x = p3->x - ptr->origins->x;
  n2.y = p3->y - ptr->origins->y;
  n2.z = p3->z - ptr->origins->z;
  ptr->vdir->x = n.y * n2.z - n.z * n2.y;
  ptr->vdir->y = n.z * n2.x - n.x * n2.z;
  ptr->vdir->z = n.x * n2.y - n.y * n2.x;
  return (1);
}
