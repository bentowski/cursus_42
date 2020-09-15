#include "mlx.h"
#include <fcntl.h>
#include "get_next_line.h"
#include "minirt.h"
#include <stdio.h>

int resolution(int ***win_width, int ***win_height, char *line, int **i)
{
  **i = **i + 1;
  while (line[**i] < '0' || line[**i] > '9')
  {
    if (line[**i] != ' ')
      return (-1);
    **i = **i + 1;
  }
  while (line[**i] >= '0' && line[**i] <= '9')
  {
    ***win_width = ***win_width * 10 + (line[**i] - 48);
    **i = **i + 1;
  }
  while (line[**i] < '0' || line[**i] > '9')
  {
    if (line[**i] != ' ')
      return (-1);
    **i = **i + 1;
  }
  while (line[**i] >= '0' && line[**i] <= '9')
  {
    ***win_height = (***win_height * 10) + (line[**i] - 48);
    **i = **i + 1;
  }
  return (1);
}

int ambiance()
{
  return (1);
}

int camera()
{
  return (1);
}

int light()
{
  return (1);
}



int init_square()
{
  return (1);
}

int init_cylinder()
{
  return (1);
}

int init_triangle()
{
  return (1);
}

int init_basics(char *line, int *i, int **win_width, int **win_height)
{
  if (line[*i] == 'R')
    if (resolution(&win_width, &win_height, line, &i) == -1)
      return (-1);
  if (line[*i] == 'A')
    if (ambiance() == -1)
      return (-1);
  if (line[*i] == 'c' && line[*i + 1] != 'y')
    if (camera() == -1)
      return (-1);
  if (line[*i] == 'l')
    if (light() == -1)
      return (-1);
  return (1);
}

int init_forms(t_coo *coo, char *line, int i)
{
  if (line[i] == 's' && line[i + 1] == 'p')
  {
    printf("%d\n", i);
    if ( (i = init_sphere(coo, line, i)) == -1)
      return (-1);
    printf("%d\n", i);
  }
  if (line[i] == 'p' && line[i + 1] == 'l')
    if ((i = init_plane(coo, line, i)) == -1)
      return (-1);
  if (line[i] == 's' && line[i + 1] == 'q')
    if (init_square() == -1)
      return (-1);
  if (line[i] == 'c' && line[i + 1] == 'y')
    if (init_cylinder() == -1)
      return (-1);
  if (line[i] == 't' && line[i + 1] == 'r')
    if (init_triangle() == -1)
      return (-1);
  return (i);
}
int ft_parse(t_coo *coo, char *map, int *win_width, int *win_height)
{
  int fd;
  char *line;
  int i;

  fd = open(map, O_RDONLY);
  while (get_next_line(fd, &line) > 0)
  {
    i = 0;
    if (init_basics(line, &i, &win_width, &win_height) == -1)
      return (-1);
    if ((i = init_forms(coo, line, i)) == -1)
      return (-1);
  }
  return (1);
}
