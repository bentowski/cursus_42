#include "get_next_line.h"

static int ft_checksave(const char *s)
{
  int x;
  int len;

  x = -1;
  len = 0;
  if (!s)
    return (-1);
  while (s[len++]);
  while (s[++x])
    if (s[x] == '\n')
      return (1);
  return (0);
}

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

int ft_read(int fd, char ***line, char **saved)
{
  char *courant;
  char *toreturn;
  int ret;
  int i;
  int x;

  x = 0;
  if (!(courant = (char *)malloc(BUFFER_SIZE + 1)))
    return (-1);
  if (*saved)
  {
    if (!(toreturn = ft_strdup(*saved)))
      return (-1);
    free(*saved);
  }
 else if (!(toreturn = (char *)malloc(1)))
    return (-1);
  while (1)
  {
    i = 0;
    if ((ret = read(fd, courant, BUFFER_SIZE)) < 0)
      return (-1);
    while (i < ret && courant[i] !='\n' && courant[i] != '\0')
      toreturn = ft_realloc(toreturn, courant[i++]);
    if (courant[i] == '\n' || (courant[i] == '\0' && i < ret))
      break;
  }
  if (!(**line = ft_strdup(toreturn)))
    return (-1);
  free(toreturn);
  while (x <= BUFFER_SIZE)
    if (courant[x++] == '\0')
      return (0);
  i++;
  if (!(*saved = ft_strdup(&courant[i])))
    return (-1);
  free(courant);
  return (1);
}


static int ft_noread(char **saved, char ***line)
{
  char *toreturn;
  int len;
  int x;

  len = 0;
  x = -1;
  while (*saved[len] != '\n' && saved[len] != '\0')
    len++;
  if (!(toreturn = (char *)malloc(len + 1)))
    return (-1);
  toreturn[len + 1] = '\0';
  while (len > x++)
    toreturn[x] = *saved[x];
  if (!(**line = ft_strdup(toreturn)))
    return (-1);
  free(toreturn);
  if (!(*saved = ft_strdup(saved[len])))
    return (-1);
  return (1);
}


int get_next_line(int fd, char **line)
{
  static char *global[255];
  int ret;

  if (ft_checksave(global[fd]) == 1)
  {
    if (!(ft_noread(&global[fd], &line)))
      return (0);
  }
  if (!(ret = ft_read(fd, &line, &global[fd])))
    return (0);
  return (1);
}
