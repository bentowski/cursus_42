#include "minirt.h"

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
    {
      printf("%s\n", "ERREUR resolution");
      return (-1);
    }
    return (i);
}

void new_init(t_list *new)
{
  new->name = NULL;
  new->x = .0;
  new->y = .0;
  new->z = .0;
  new->vx = .0;
  new->vy = .0;
  new->vz = .0;
  new->diameter = .0;
  new->height = .0;
  new->color1 = 0;
  new->color2 = 0;
  new->color3 = 0;
  new->next = NULL;
}

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = (char *)s;
	while (n > 0)
	{
		p[n - 1] = 0;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	int		lenght;

	lenght = count * size;
	if (!(ptr = malloc(lenght)))
		return (NULL);
	ft_bzero(ptr, lenght);
	return (ptr);
}

int init_sphere(char *line, int i, t_list ***obj)
{
  t_list *new;

  if (!(new = ft_calloc(1, sizeof(t_list))))
    return (-1);
  free(new);
  return (i);
}

int init_forms(char *line, int i, t_list **obj)
{
  if (line[i] == 's' && line[i + 1] == 'p')
  {
    if ((i = init_sphere(line, i, &obj)) == -1)
    {
      printf("%s\n", "ERREUR sphere");
      return (-1);
    }
  }
  return (i);
}

int ft_parse(char *map, int *win_width, int *win_height)
{
  int fd;
  char *line;
  int i;
  t_list *obj;

  fd = open(map, O_RDONLY);
  while (get_next_line(fd, &line) > 0)
  {
    i = 0;
    if ((i = init_basics(line, i, &win_width, &win_height)) == -1)
    {
      printf("%s\n", "ERREUR basics");
      free(line);
      return (-1);
    }
    if ((i = init_forms(line, i, &obj)) == -1)
    {
      printf("%s\n", "ERREUR forms");
      free(line);
      return (-1);
    }
    printf("%s\n", line);
    free(line);
  }
  printf("%s\n", line);
  free(line);
  return (1);
}
