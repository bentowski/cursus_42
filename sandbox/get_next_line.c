#include "get_next_line.h"

static void print_list(t_list *list)
{
  int x;

  x = 0;
  while (list)
  {
    printf("%d : %d\n", x, list->fd);
    list = list->next;
    x++;
  }
}


static t_list *add_fd(t_list *list, int fd, t_list *begun)
{
  t_list *tmp;

  if(!(tmp = malloc(sizeof(t_list))))
    return (NULL);
  tmp->fd = fd;
  list = begun->next;
  begun->next = tmp;
  if (!list)
    tmp->next = NULL;
  else
    tmp->next = list;
  return (begun->next);
}

static char *ft_realloc(char *s, char courant)
{
  int x;
	int i;
  char *new;
	char *tmp;

  x = 0;
	i = -1;
	tmp = s;
  while (s[x] != '\0')
		x++;
  if (!((new = (char*)malloc(x + 2))))
    return (NULL);
  while (x > ++i)
    new[i] = s[i];
	new[i] = courant;
	new[i + 1] = '\0';
	free(tmp);
  return (new);
}

static int ft_carry(int BUFFER_SIZE, int fd, t_list list, char ***line)
{
  char *courant;
  char *save;
  int ret;
  int i;

  if (!(save = (char *)malloc(1)))
    return (-1);
  while (1)
  {
    i = 0;
    if ((ret = read(fd, courant, BUFFER_SIZE)) < 0)
      return (-1);
    if (courant[i] == '\0')
      break;
    while ( i < ret && courant[i] != '\n' && courant[i] != '\0')
      save = ft_realloc(save, courant[i++]);
    if (courant[i] == '\n')
      break;
  }
  **line = ft_strdup(save);
  free(save);
  if (!(save = (char *)malloc(ret)))
    return (-1);
  while (i++ < ret)
}


int get_next_line(int fd, char **line)
{
  static t_list *list;
  t_list *begun;
  int y;
  int BUFFER_SIZE

  BUFFER_SIZE = 3;
  y = 0;
  if (!(begun = malloc(sizeof(t_list))))
    return (-1);
  if (list)
    begun->next = list;
  while (list)
  {
    if (list->fd == fd)
    {
      y = 1;
      break;
    }
    list = list->next;
  }
  printf("\nfd : %d\n", fd);
  if (y == 0)
    list = add_fd(list, fd, begun);
  ft_carry(BUFFER_SIZE, fd, list, &line);
  print_list(list);
  return (0);
}
