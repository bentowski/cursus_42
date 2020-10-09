#include "mlx.h"
#include <fcntl.h>
#include "minirt.h"
#include <stdio.h>
#include <math.h>
#include <unistd.h>

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

int init_basics(char *line, int i, int **win_width, int **win_height)
{
  if (line[i] == 'R')
    if ((i = resolution(&win_width, &win_height, line, i)) == -1)
      return (-1);
  return (i);
}

int init_sphere(char *line, int i, t_list ***obj)
{
  t_list *new;
  double tmp;

  if (!(new = (t_list *)malloc(1)))
    return (-1);
  tmp = .0;
  i= i + 2;

  new->next = **obj;
  **obj = new;
  free(new);
  return (i);
}

int init_forms(char *line, int i, t_list **obj)
{
  if (line[i] == 's' && line[i + 1] == 'p')
    if ((i = init_sphere(line, i, &obj)) == -1)
      return (-1);
  return (i);
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
    if ((i = init_basics(line, i, &win_width, &win_height)) == -1)
    {
      free(line);
      return (-1);
    }
    if ((i = init_forms(line, i, &obj)) == -1)
    {
      free(line);
      return (-1);
    }
    free(line);
    x++;
  }
  free(line);
  return (1);
}

int main(int argc, char **argv)
{
  int win_width;
  int win_height;

  if (argc != 2)
    return (-1);
  win_width = 0;
  win_height = 0;
  ft_parse(argv[1], &win_width, &win_height);
  system("leaks a.out");
}
