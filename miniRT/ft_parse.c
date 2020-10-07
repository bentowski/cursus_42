#include "mlx.h"
#include <fcntl.h>
#include "minirt.h"
#include <stdio.h>

// int resolution(int ***win_width, int ***win_height, char *line, int i)
// {
//   i++;
//   while (line[i] < '0' || line[i] > '9')
//     if (line[i++] != ' ')
//       return (-1);
//   while (line[i] >= '0' && line[i] <= '9')
//     ***win_width = ***win_width * 10 + (line[i++] - 48);
//   while (line[i] < '0' || line[i] > '9')
//     if (line[i++] != ' ')
//       return (-1);
//   while (line[i] >= '0' && line[i] <= '9')
//     ***win_height = (***win_height * 10) + (line[i++] - 48);
//   return (i);
// }

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

// int init_basics(char *line, int i, int **win_width, int **win_height)
// {
//   if (line[i] == 'R')
//     if ((i = resolution(&win_width, &win_height, line, i)) == -1)
//       return (-1);
//   // if (line[i] == 'A')
//   //   if (ambiance() == -1)
//   //     return (-1);
//   // if (line[i] == 'c' && line[i + 1] != 'y')
//   //   if (camera() == -1)
//   //     return (-1);
//   // if (line[i] == 'l')
//   //   if (light() == -1)
//   //     return (-1);
//   return (i);
// }

int init_forms(char *line, int i, t_list **obj)
{
  if (line[i] == 's' && line[i + 1] == 'p')
  {
    if ((i = init_sphere(line, i, &obj)) == -1)
      return (-1);
  }
  // free(obj);
  //
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
  return (i);
}

void ft_clear(t_list **obj)
{
  t_list *tmp;
  t_list *ptr;

  ptr = *obj;
  while (ptr)
  {
    printf("%s\n", "test clear");
    tmp = ptr->next;
    ptr = NULL;
    ptr = tmp;
  }
  *obj = NULL;
}

int ft_parse(char *map, int *win_width, int *win_height)
{
  int fd;
  char *line;
  t_list *obj;
  int i;
  int x;

  fd = open(map, O_RDONLY);
  x = 0;
  while (get_next_line(fd, &line) > 0)
  {
    i = 0;
    // printf("%s : %d\n", "ok", x);
    // if ((i = init_basics(line, i, &win_width, &win_height)) == -1)
    //   return (-1);
    // printf("%s : %d\n", "suite", i);
    if ((i = init_forms(line, i, &obj)) == -1)
      return (-1);
    // printf("%s : %d\n", "fin", x);
    free(line);
    x++;
  }
  free(line);
  printf("%s\n", "probleme clear");
  ft_clear(&obj);
  free(obj);
  printf("%s\n", "FIN");

  return (1);
}
