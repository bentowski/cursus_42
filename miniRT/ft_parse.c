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

int init_triangle()
{
  return (1);
}

int init_basics(char *line, int i, int **win_width, int **win_height)
{
  if (line[i] == 'R')
    if ((i = resolution(&win_width, &win_height, line, i)) == -1)
      return (-1);
  if (line[i] == 'A')
    if (ambiance() == -1)
      return (-1);
  if (line[i] == 'c' && line[i + 1] != 'y')
    if (camera() == -1)
      return (-1);
  if (line[i] == 'l')
    if (light() == -1)
      return (-1);
  return (i);
}

int init_forms(char *line, int i, t_coo *coo)
{
  if (line[i] == 's' && line[i + 1] == 'p')
  {
    printf("%s\n", "ok");
    if ((i = init_sphere(line, i, coo_init(coo))) == -1)
      return (-1);
  }
  if (line[i] == 'p' && line[i + 1] == 'l')
    if ((i = init_plane(line, i, coo_init(coo))) == -1)
      return (-1);
  if (line[i] == 's' && line[i + 1] == 'q')
    if ((i = init_square(line, i, coo_init(coo))) == -1)
      return (-1);
  if (line[i] == 'c' && line[i + 1] == 'y')
    if ((i = init_cylinder(line, i, coo_init(coo))) == -1)
      return (-1);
  if (line[i] == 't' && line[i + 1] == 'r')
    if ((i = init_triangle()) == -1)
      return (-1);
  return (i);
}
int ft_parse(char *map, int *win_width, int *win_height, t_coo *coo)
{
  int fd;
  char *line;
  int i;

  fd = open(map, O_RDONLY);
  while (get_next_line(fd, &line) > 0)
  {
    i = 0;
    if ((i = init_basics(line, i, &win_width, &win_height)) == -1)
      return (-1);
    if ((i = init_forms(line, i, coo)) == -1)
      return (-1);
  }
  return (1);
}
