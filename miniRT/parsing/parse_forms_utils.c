#include "../minirt.h"
//
int ft_vecteur(t_triade *new, char *line, int i)
{

  if ((new->x = ft_routine(new->x, line, &i, 1)) == -1)
  {
    printf("%s\n", "ERROR MAP CONFIG OBJECT structuration");
    return (-1);
  }
  if (line[i++] != ',')
    return (-1);
  if ((new->y = ft_routine(new->y, line, &i, 1)) == -1)
  {
    printf("%s\n", "ERROR MAP CONFIG OBJECT structuration");
    return (-1);
  }
  if (line[i++] != ',')
    return (-1);
  if ((new->z = ft_routine(new->z, line, &i, 2)) == -1)
  {
    printf("%s\n", "ERROR MAP CONFIG OBJECT structuration");
    return (-1);
  }
  return (i);
}
//
int ft_structuration(t_triade *new, char *line, int i)
{

  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s\n", "ERROR MAP CONFIG OBJECT COORDONNEES");
    return (-1);
  }
  // if (opt == 1)
  //   if ((new->diameter = ft_routine(new->diameter, line, &i, 2)) == -1)
  //   {
  //     printf("%s\n", "ERROR MAP CONFIG OBJECT DIAMETER");
  //     return (-1);
  //   }
  // if (opt == 2)
  //   if ((new->height = ft_routine(new->height, line, &i, 2)) == -1)
  //   {
  //     printf("%s\n", "ERROR MAP CONFIG OBJECT HEIGHT");
  //     return (-1);
  //   }
  // if (opt != 1 && opt != 2)

    if ((i = ft_vecteur(new, line, i)) == -1)
    {

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
//
int ft_coordonnees(t_triade *new, char *line, int i)
{

  if ((i = ft_space(line, i)) != -1)
  {
    if ((new->x = ft_routine(new->x, line, &i, 1)) != -1)
      if (line[i++] == ',')
        if ((new->y = ft_routine(new->y, line, &i, 1)) != -1)
          if (line[i++] == ',')
            if ((new->z = ft_routine(new->z, line, &i, 2)) != -1)
              return (i);
    // if (opt == 2)
    //   if ((new->x2 = ft_routine(new->x2, line, &i, 1)) != -1)
    //     if (line[i++] == ',')
    //       if ((new->y2 = ft_routine(new->y2, line, &i, 1)) != -1)
    //         if (line[i++] == ',')
    //           if ((new->z2 = ft_routine(new->z2, line, &i, 2)) != -1)
    //             return (i);
    // if (opt == 3)
    //   if ((new->x3 = ft_routine(new->x3, line, &i, 1)) != -1)
    //     if (line[i++] == ',')
    //       if ((new->y3 = ft_routine(new->y3, line, &i, 1)) != -1)
    //         if (line[i++] == ',')
    //           if ((new->z3 = ft_routine(new->z3, line, &i, 2)) != -1)
    //             return (i);
  }
  return (-1);
}
