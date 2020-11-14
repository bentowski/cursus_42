#include "mlx.h"
#include <fcntl.h>
#include "minirt.h"
#include <stdio.h>


int verif(char *line, int i, int **win_width, int **win_height, t_list **obj)
{
  // if (line[i] != 'R' && line[i] != 'A' && line[i] != 'l' && line[i] != '\n')
  // {
  //   if (line[i] != 's' && line[i] != 't' && line[i] != 'c' && line[i] != 'p')
  //   {
  //     printf("%s\n", "ICI");
  //     return (-1);
  //   }
  //   else if (line[i + 1] != 'p' && line[i + 1] != 'q' && line[i + 1] != 'y')
  //     if (line[i + 1] != 'l' && line[i + 1] != 'r')
  //     {
  //       printf("%s\n", "OUPS");
  //       return (-1);
  //     }
  // }
  if (line[i] == 'R')
    if ((i = resolution(&win_width, &win_height, line, i)) == -1)
      printf("%s\n%s\n", "Error", "Invalid resolution data");
  return (i);
}

int init_map(char *line, int i, t_list **obj)
{
  if (line[i] == 'A')
    if ((i = ambiance(line, i, &obj)) == -1)
      printf("%s\n%s\n", "Error", "Invalid ambiant data");
  if (line[i] == 'c' && line[i + 1] != 'y')
    if ((i = camera(line, i, &obj)) == -1)
      printf("%s\n%s\n", "Error", "Invalid camera data");
  if (line[i] == 'l')
    if ((i = light(line, i, &obj)) == -1)
      printf("%s\n%s\n", "Error", "Invalid light data");
  if (line[i] == 's' && line[i + 1] == 'p')
    if ((i = init_sphere(line, i, &obj)) == -1)
      printf("%s\n%s\n", "Error", "Invalid object data");
  if (line[i] == 'p' && line[i + 1] == 'l')
    if ((i = init_plane(line, i, &obj)) == -1)
      printf("%s\n%s\n", "Error", "Invalid object data");
  if (line[i] == 's' && line[i + 1] == 'q')
    if ((i = init_square(line, i, &obj)) == -1)
      printf("%s\n%s\n", "Error", "Invalid object data");
  if (line[i] == 'c' && line[i + 1] == 'y')
    if ((i = init_cylinder(line, i, &obj)) == -1)
      printf("%s\n%s\n", "Error", "Invalid object data");
  if (line[i] == 't' && line[i + 1] == 'r')
    if ((i = init_triangle(line, i, &obj)) == -1)
      printf("%s\n%s\n", "Error", "Invalid object data");
  return (i);
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

void ft_clear(t_list **obj, char ***line)
{
  t_list *tmp;
  t_list *ptr;

  ptr = *obj;
  while (ptr)
  {
    ft_print(ptr);
    tmp = ptr->next;
    free(ptr);
    ptr = tmp;
  }
  free(**line);
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
    if ((i = verif(*line, i, &win_width, &win_height, &obj)) == -1)
    {
      ft_clear(&obj, &line);
      return (-1);
    }
    if ((i = init_map(*line, i, &obj)) == -1)
    {
      ft_clear(&obj, &line);
      return (-1);
    }
      free(*line);
  }
  ft_clear(&obj, &line);
  return (1);
}
