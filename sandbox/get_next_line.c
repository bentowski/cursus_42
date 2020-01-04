#include "get_next_line.h"

// static void print_list(t_list *list)
// {
//   int x;
//
//   x = 0;
//   while (list->next)
//   {
//     printf("%d : %d\n", x, list->fd);
//     printf("s : %s\n", list->str);
//     list = list->next;
//     x++;
//   }
// }

static t_list *add_fd(t_list *list, int fd, t_list *begun)
{
  t_list *tmp;

  if(!(tmp = malloc(sizeof(t_list))))
  return (NULL);
  tmp->fd = fd;
  tmp->str = NULL;
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
  while (s[x])
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


static int ft_useagain(const char *s1, char **toreturn)
{
  int len;
  int x;

  x = -1;
  len = 1;
  if (!s1)
    return (-1);
  while (s1[len] && s1[len] != '\n')
    len++;
  if (!(*toreturn = (char *)malloc(len)))
    return (-1);
  while (++x < len && s1[x] != '\n')
  {
    if (s1[x] == '\n')
      return (1);
    *toreturn[x] = s1[x];
  }
  return (0);
}



static char	*ft_strdup(const char *s1)
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
  int retchar;
  int ret;
  int i;
  int x;

  x = 0;
  retchar = 0;
  if (!(save = (char *)malloc(BUFFER_SIZE)))
    return (-1);
  if (!(courant = (char *)malloc(BUFFER_SIZE)))
    return (-1);
  if (list->str)
  {
    if ((retchar = ft_useagain(list->str, &toreturn)) < 0)
      return (-1);
  }
  else if (!(toreturn = (char *)malloc(1)))
    return (-1);
  printf("toreturn : %s\n", toreturn);
  if (retchar == 0)
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
  **line = ft_strdup(toreturn);
  free(toreturn);
  if (courant[i + 1] != '\0')
  {
    while (i++ < ret)
      save[x++] = courant[i];
    list->str = ft_strdup(save);
  }
  printf("save : %s\n", save);
  printf("\n");
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
        if (s[x + 1])
          return (1);
  return (0);
}


static int ft_noread(t_list *list, char ***line)
{
  char *saved;
  int x;
  int y;
  int end;

  x = 0;
  end = 1;
  if (!(saved = ft_strdup(list->str)))
    return (-1);
  while (saved[x] && saved[x] != '\n')
      if (!(**line = ft_realloc(**line, saved[x++])))
        return (-1);
  if (saved[x] == '\0')
    end = 0;
  while (saved[++x])
    saved[y++] = saved[x];
  saved[x] = '\0';
  if (!(list->str = ft_strdup(saved)))
    return (-1);
  free(saved);
  return (end);
}


int get_next_line(int fd, char **line)
{
  static t_list *list;
  t_list *begun;
  int y;

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
  if (y == 0)
    list = add_fd(list, fd, begun);
  if (ft_checksave(list->str) != 0)
  {
    ft_noread(list, &line);
  }
  else
    ft_carry(fd, list, &line);
  printf("line : %s\n", *line);
  return (0);
}
