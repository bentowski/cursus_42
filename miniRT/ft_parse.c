#include "mlx.h"
#include <fcntl.h>
#include "minirt.h"
#include <stdio.h>

int resolution(int ***win_width, int ***win_height, char *line, int i)
{
  i++;
  while (line[i] < '0' || line[i] > '9')
    if (line[i++] != ' ')
      return (-1);
  while (line[i] >= '0' && line[i] <= '9')
    ***win_width = ***win_width * 10 + (line[i++] - 48);
  while (line[i] < '0' || line[i] > '9')
    if (line[i++] != ' ')
      return (-1);
  while (line[i] >= '0' && line[i] <= '9')
    ***win_height = (***win_height * 10) + (line[i++] - 48);
  return (i);
}

// int ambiance()
// {
//   return (1);
// }
//
// int camera()
// {
//   return (1);
// }
//
// int light()
// {
//   return (1);
// }
//
// int init_triangle()
// {
//   return (1);
// }

int init_basics(char *line, int i, int **win_width, int **win_height)
{
  // printf("%s\n", "entree init_basics");
  if (line[i] == 'R')
    if ((i = resolution(&win_width, &win_height, line, i)) == -1)
    {
      printf("%s\n", "sortie ERREUR init_basics(resolution)");
      return (-1);
    }
  // if (line[i] == 'A')
  //   if (ambiance() == -1)
  //     return (-1);
  // if (line[i] == 'c' && line[i + 1] != 'y')
  //   if (camera() == -1)
  //     return (-1);
  // if (line[i] == 'l')
  //   if (light() == -1)
  //     return (-1);
  // printf("%s\n", "sorte correcte init_basics");
  return (i);
}

int init_forms(char *line, int i, t_list **obj)
{
  // printf("%s\n", "entree init_forms");
  // printf("%c%c\n", line[i], line[i + 1]);
  // t_list *ptr;
  // if (!(ptr = ft_calloc(1, sizeof(t_list))))
  //   return (-1);
  if (line[i] == 's' && line[i + 1] == 'p')
  {
    if ((i = init_sphere(line, i, &obj)) == -1)
    {
      printf("%s\n", "sortie ERREUR init_forms (sphere)");
      return (-1);
    }
    // printf("ptr : %lf,%lf,%lf %lf, %d, %d, %d\n", ptr->x, ptr->y, ptr->z, ptr->diameter, ptr->color1, ptr->color2, ptr->color3);
    // *obj = ptr;
  }
  // free(ptr);
  // if (line[i] == 'p' && line[i + 1] == 'l')
  //   if ((i = init_plane(line, i, &obj)) == -1)
  //     return (-1);
  // if (line[i] == 's' && line[i + 1] == 'q')
  //   if ((i = init_square(line, i, &obj)) == -1)
  //     return (-1);
  // if (line[i] == 'c' && line[i + 1] == 'y')
  //   if ((i = init_cylinder(line, i, &obj)) == -1)
  //     return (-1);
  // if (line[i] == 't' && line[i + 1] == 'r')
  //   if ((i = init_triangle()) == -1)
  //     return (-1);
  // printf("%s\n", "sortie correcte init_forms");
  return (i);
}

// void ft_clear(t_list **obj)
// {
//   t_list *tmp;
//   t_list *ptr;
//
//   ptr = *obj;
//   while (ptr)
//   {
//     printf("%s\n", "test clear");
//     tmp = ptr->next;
//     ptr = NULL;
//     ptr = tmp;
//   }
//   *obj = NULL;
// }

int ft_parse(char *map, int *win_width, int *win_height)
{
  int fd;
  char *line;
  t_list *obj;
  int i;
  int x;

  // printf("%s\n", "ft_parse");
  fd = open(map, O_RDONLY);
  x = 1;
  obj = NULL;
  if (!(obj = ft_calloc(1, sizeof(t_list))))
    return (-1);
  while (get_next_line(fd, &line) > 0)
  {
    // printf("%s%d\n", "ligne N", x);
    i = 0;
    if ((i = init_basics(line, i, &win_width, &win_height)) == -1)
    {
      printf("%s\n", "sortie ERREUR ft_parse (basics)");
      free(line);
      return (-1);
    }
    if ((i = init_forms(line, i, &obj)) == -1)
    {
      printf("%s\n", "sortie ERREUR ft_parse (forms)");
      free(line);
      return (-1);
    }
    // printf("%s\n", "avant free");
      free(line);
    // printf("%s\n", "apres free");
    x++;
    // printf("%s\n", "next line");
    printf("obj : %lf,%lf,%lf %lf, %d, %d, %d\n", obj->x, obj->y, obj->z, obj->diameter, obj->color1, obj->color2, obj->color3);
  }
  free(line);
  // if (obj)
  free(obj);
  // obj = obj->next;
  // printf("%s\n", "fin boucle GNL");
  // printf("%s\n", "sortie correcte ft_parse");
  return (1);
}
