#include "../../minirt.h"

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

int ft_check_color_vdir(t_triade *check, int opt)
{
  int min;
  int max;

  if (opt == 1)
  {
    min = -1;
    max = 1;
  }
  if (opt == 2)
  {
    min = 0;
    max = 255;
  }
  if (check->x >= min && check->x <= max)
    if (check->y >= min && check->y <= max)
      if (check->z >= min && check->z <= max)
        return (1);
  return (-1);
}
