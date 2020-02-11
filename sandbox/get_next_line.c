#include "get_next_line.h"

static char *ft_realloc(char *s, char courant)
{
  int x;
  int i;
  char *new;

  x = 0;
  i = -1;
  while (s[x])
    x++;
  if (!((new = (char*)malloc(x + 2))))
    return (NULL);
  while (x > ++i)
    new[i] = s[i];
  new[i] = courant;
  new[i + 1] = '\0';
  free(s);
  return (new);
}

static char	*ft_strdup(char *s1)
{
  int	  len;
  char *cpy;
  int   x;

  x = -1;
  len = 0;
  if (!s1)
    return (NULL);
  while (s1[len++]);
  if (!(cpy = (char *)malloc(len + 1)))
    return (NULL);
  while(++x < len)
    cpy[x]= s1[x];
	return (cpy);
}

static int ft_carry(int fd, t_list *list, char ***line)
{
  char *courant;
  char *toreturn;
  char *save;
  int ret;
  int i;
  int x;

  x = 0;
  if (!(courant = (char *)malloc(BUFFER_SIZE)))
    return (-1);
  if (list->str)
  {
    if (!(toreturn = ft_strdup(list->str)))
      return (-1);
    free(list->str);
  }
  else if (!(toreturn = (char *)malloc(1)))
    return (-1);
    while (1)
    {
      i = 0;
      if ((ret = read(fd, courant, BUFFER_SIZE)) < 0)
        return (-1);
      if (courant[i] == '\0')
        break;
      while ( i < ret && courant[i] != '\n' && courant[i] != '\0')
        toreturn = ft_realloc(toreturn, courant[i++]);
      if (courant[i] == '\n')
        break;
    }
  if (!(**line = ft_strdup(toreturn)))
    return (-1);
  free(toreturn);
  if (courant[i + 1] != '\0')
  {
    if (!(save = (char *)malloc(BUFFER_SIZE)))
      return (-1);
    while (i++ < ret)
      save[x++] = courant[i];
    list->str = ft_strdup(save);
    free(save);
  }
  free(courant);
  return (ret);
}


static int ft_checksave(const char *s)
{
  int x;

  x = -1;
  if (s)
    while (s[++x])
      if (s[x] == '\n')
          return (1);
  return (0);
}


static int ft_noread(t_list *list, char ***line)
{
  char *saved;
  char *toreturn;
  int len;
  int x;
  int end;

  x = -1;
  end = 1;
  len = 0;
  if (!(saved = ft_strdup(list->str)))
    return (-1);
  while (saved[len++] != '\n');
  if (!(toreturn = (char *)malloc(len + 1)))
    return (-1);
  while (x++ < len - 2)
    toreturn[x] = saved[x];
  toreturn[x] = '\0';
  **line = ft_strdup(toreturn);
  free(toreturn);
  if (saved[x] == '\0')
    end = 0;
  x++;
  saved = ft_strdup(&saved[x]);
  if (!(list->str = ft_strdup(saved)))
    return (-1);
  free(saved);
  return (end);
}

int get_next_line(int fd, char **line)
{
  static t_list *list;
  t_list *begun;
  int ret;
  int y;

  y = 0;
  ret = 1;
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
  if (y == 0)
    list = add_fd(list, fd, begun);
  if (ft_checksave(list->str) != 0)
    ret = ft_noread(list, &line);
  else
    ret = ft_carry(fd, list, &line);
  printf("line : %s\n", *line);
  free(begun);
  return (ret);
}
