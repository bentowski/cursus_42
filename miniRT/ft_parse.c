#include "mlx.h"
#include <fcntl.h>
#include "minirt.h"
#include <stdio.h>

int resolution(int ***win_width, int ***win_height, char *line, int i)
{
  i++;
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR MAP CONFIG RESOLUTION", i);
    return (-1);
  }
  while (line[i] >= '0' && line[i] <= '9')
    ***win_width = ***win_width * 10 + (line[i++] - 48);
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR MAP CONFIG RESOLUTION", i);
    return (-1);
  }
  while (line[i] >= '0' && line[i] <= '9')
    ***win_height = (***win_height * 10) + (line[i++] - 48);
  return (i);
}

int ambiance(char *line, int i, t_list ***obj)
{
  t_list *new;

  if (!(new = ft_calloc(1, sizeof(t_list))))
    return (-1);
  i = i + 2;
  new->name = "A";
  if ((i = ft_space(line, i)) != -1)
    if ((new->puissance = ft_routine(new->puissance, line, &i, 1)) != -1)
      if ((i = ft_color(new, line, i)) != -1)
      {
        new->next = **obj;
        **obj = new;
        return (i);
      }
  free(new);
  return (i);
}

int camera(char *line, int i, t_list ***obj)
{
  t_list *new;

  if (!(new = ft_calloc(1, sizeof(t_list))))
    return (-1);
  i = i + 1;
  new->name = "c";
  if ((i = ft_coordonnees(new, line, i, 1)) != -1)
    if ((i = ft_structuration(new, line, i, 3)) != -1)
      if ((i = ft_space(line, i)) != -1)
        if ((new->fov = ft_routine(new->fov, line, &i, 2)) != -1)
        {
          new->next = **obj;
          **obj = new;
          return (i);
        }
  free(new);
  return (i);
}

int light(char *line, int i, t_list ***obj)
{
  t_list *new;

  if (!(new = ft_calloc(1, sizeof(t_list))))
    return (-1);
  i = i + 1;
  new->name = "l";
  if ((i = ft_coordonnees(new, line, i, 1)) != -1)
    if ((i = ft_space(line, i)) != -1)
      if ((new->puissance = ft_routine(new->puissance, line, &i, 1)) != -1)
        if ((i = ft_color(new, line, i)) != -1)
        {
          new->next = **obj;
          **obj = new;
          return (i);
        }
  free(new);
  return (i);
}

int init_basics(char *line, int i, int **win_width, int **win_height, t_list **obj)
{
  if (line[i] == 'R')
  {
    if ((i = resolution(&win_width, &win_height, line, i)) == -1)
    {
      printf("%s\n", "sortie ERREUR init_basics(resolution)");
      return (-1);
    }
  }
  else if (line[i] == 'A')
  {
    if ((i = ambiance(line, i, &obj)) == -1)
      return (-1);
  }
  else if (line[i] == 'c' && line[i + 1] != 'y')
  {
    if ((i = camera(line, i, &obj)) == -1)
      return (-1);
  }
  else if (line[i] == 'l')
  {
    if ((i = light(line, i, &obj)) == -1)
      return (-1);
  }
  return (i);
}

int init_forms(char *line, int i, t_list **obj)
{
  // printf("%s\n", "entree init_forms");
  // printf("%c%c\n", line[i], line[i + 1]);
  if (line[i] == 's' && line[i + 1] == 'p')
  {
    if ((i = init_sphere(line, i, &obj)) == -1)
    {
      printf("%s\n", "sortie ERREUR init_forms (sphere)");
      return (-1);
    }
  }
  if (line[i] == 'p' && line[i + 1] == 'l')
    if ((i = init_plane(line, i, &obj)) == -1)
      return (-1);
  if (line[i] == 's' && line[i + 1] == 'q')
    if ((i = init_square(line, i, &obj)) == -1)
      return (-1);
  if (line[i] == 'c' && line[i + 1] == 'y')
    if ((i = init_cylinder(line, i, &obj)) == -1)
      return (-1);
  if (line[i] == 't' && line[i + 1] == 'r')
    if ((i = init_triangle(line, i, &obj)) == -1)
      return (-1);
  // printf("%s\n", "sortie correcte init_forms");
  return (i);
}

void ft_clear(t_list **obj, char ***line)
{
  t_list *tmp;
  t_list *ptr;

  ptr = *obj;
  while (ptr)
  {
    tmp = ptr->next;
    free(ptr);
    ptr = tmp;
  }
  free(**line);
}

void ft_print(t_list *new)
{
  if (new->next)
  {
    if (new->name[0] == 'A')
      printf("%s : %lf, %d,%d,%d\n\n", "A", new->puissance, new->color1, new->color2, new->color3);
    if (new->name[0] == 'c' && new->name[1] == 'y')
      printf("%s : %lf, %lf, %lf     %lf,%lf,%lf     %lf     %lf      %d, %d, %d\n", new->name, new->x, new->y, new->z, new->vx, new->vy, new->vz, new->height, new->diameter, new->color1, new->color2, new->color3);
    else if (new->name[0] == 'c')
      printf("%s : %lf, %lf, %lf       %lf, %lf, %lf      %d\n", new->name, new->x, new->y, new->z, new->vx, new->vy, new->vz, new->fov);
    else if (new->name[0] == 's' && new->name[1] == 'p')
      printf("%s : %lf, %lf, %lf     %lf,       %d, %d, %d\n", new->name, new->x, new->y, new->z, new->diameter, new->color1, new->color2, new->color3);
    else if (new->name[0] == 'p' && new->name[1] == 'l')
      printf("%s : %lf, %lf, %lf     %lf, %lf, %lf     %d, %d, %d\n", new->name, new->x, new->y, new->z, new->vx, new->vy, new->vz, new->color1, new->color2, new->color3);
    else if (new->name[0] == 't' && new->name[1] == 'r')
      printf("%s : %lf, %lf, %lf     %lf, %lf, %lf       %lf, %lf, %lf,    %d, %d, %d\n", new->name, new->x, new->y, new->z, new->x2, new->y2, new->z2, new->x3, new->y3, new->z3, new->color1, new->color2, new->color3);
    else if (new->name[0] == 's' && new->name[1] == 'q')
      printf("%s : %lf, %lf, %lf    %lf, %lf, %lf       %lf,       %d, %d, %d\n", new->name, new->x, new->y, new->z, new->vx, new->vy, new->vz, new->diameter, new->color1, new->color2, new->color3);
    else if (new->name[0] == 'l')
      printf("%s : %lf, %lf, %lf     %lf      %d, %d, %d\n", new->name, new->x, new->y, new->z, new->puissance, new->color1, new->color2, new->color3);
  }
}

int ft_parse(char **line, int fd, int *win_width, int *win_height)
{
  t_list *obj;
  int i;

  if (!(obj = ft_calloc(1, sizeof(t_list))))
    return (-1);
  obj->next = NULL;
  while (get_next_line(fd, &line) > 0)
  {
    i = 0;
    if ((i = init_basics(*line, i, &win_width, &win_height, &obj)) == -1)
    {
      printf("%s\n", "sortie ERREUR ft_parse (basics)");
      ft_clear(&obj, &line);
      return (-1);
    }
    if ((i = init_forms(*line, i, &obj)) == -1)
    {
      printf("%s\n", "sortie ERREUR ft_parse (forms)");
      ft_clear(&obj, &line);
      return (-1);
    }
      free(*line);
  }
  ft_clear(&obj, &line);
  return (1);
}
