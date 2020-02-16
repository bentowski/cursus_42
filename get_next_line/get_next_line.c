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
    if (ret == 0)
    {
      free(courant);
      free(toreturn);
      return (0);
    }
    while (i < ret && courant[i] !='\n' && courant[i] != '\0')
      toreturn = ft_realloc(toreturn, courant[i++]);
    if (courant[i] == '\n')
      break;
  }
  if (!(**line = ft_strdup(toreturn)))
    return (-1);
  free(toreturn);
  i++;
  if (!(*saved = ft_strdup(&courant[i])))
    return (-1);
  free(courant);
  return (1);
}


static int ft_noread(char **saved, char ***line)
{
  char *toreturn;
  char *tmp;
  int len;
  int x;

  len = 0;
  x = -1;
  if (!(tmp = ft_strdup(*saved)))
    return (-1);
  while (tmp[len] != '\0')
  {
    if (tmp[len] == '\n')
      break;
    len++;
  }
  if (!(toreturn = (char *)malloc(len + 1)))
    return (-1);
  toreturn[len + 1] = '\0';
  while (len - 1 > x++)
    toreturn[x] = tmp[x];
  if (!(**line = ft_strdup(toreturn)))
    return (-1);
  free(toreturn);
  free(*saved);
  if (!(*saved = ft_strdup(&tmp[len + 1])))
    return (-1);
  free(tmp);
  return (1);
}

int get_next_line(int fd, char **line)
{
  static char *global[255];

  if (fd > 0)
  {
    if (ft_checksave(global[fd]) == 1)
    {
      if (!(ft_noread(&global[fd], &line)))
        return (0);
      // printf("line : %s\n", *line);
      // printf("saved : %s\n", global[fd]);
    }
    else if ((ft_read(fd, &line, &global[fd])) == 0)
      return (0);
    // printf("read line : %s\n", *line);
    // printf("read saved : %s\n", global[fd]);
    return (1);
  }
  return (-1);
}
