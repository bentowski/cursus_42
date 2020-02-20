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

static char	*ft_strjoin(char *s1, char const *s2, int *i)
{
	char	*d;
	int		len;
  int   len2;
	int		y;
  int   x;

	y = 0;
  x = 0;
  len = 0;
  len2 = 0;
	if (!s2)
		return (NULL);
  while (s1[len++]);
  while (s2[len2] && s2[len2] != '\n')
    len2++;
	len += len2 + 1;
	if (!(d = (char *)malloc(len)))
		return (NULL);
	while (s1[x])
		d[y++] = s1[x++];
  x = 0;
	while (s2[x] && s2[x] != '\n')
		d[y++] = s2[x++];
	d[y] = '\0';
  *i = x;
  free(s1);
	return (d);
}

static int ft_readdeux(int fd, char **toreturn, char ***saved)
{
  int ret;
  char courant[BUFFER_SIZE + 1];
  int i;

  i = 0;
  courant[BUFFER_SIZE] = '\0';
  while (1)
  {
    i = 0;
    if ((ret = read(fd, courant, BUFFER_SIZE)) <= 0)
      break;
    if (!(*toreturn = ft_strjoin(*toreturn, courant, &i)))
      return (-1);
    if (courant[0] == '\0')
      return (0);
    if (courant[i] == '\n')
      break;
  }
  if (ret < 0)
    return (-1);
  if (courant[i + 1] != '\0')
    if (!(**saved = ft_strdup(&courant[i + 1])))
      return (-1);
  if (ret == 0)
    return (0);
  return (1);
}

static int ft_read(int fd, char ***line, char **saved)
{
  char *toreturn;
  int ret;

  if (*saved != NULL)
  {
    if (!(toreturn = ft_strdup(*saved)))
      return (-1);
    free(*saved);
  }
  else if (!(toreturn = (char *)malloc(1)))
    return (-1);
  if ((ret = ft_readdeux(fd, &toreturn, &saved)) <= 0)
    return (ret);
  if (!(**line = ft_strdup(toreturn)))
    return (-1);
  free(toreturn);
  return (ret);
}

static int ft_noread(char **saved, char ***line)
{
  char *toreturn;
  char *tmp;
  int len;
  int x;

  len = -1;
  x = -1;
  if (!(tmp = ft_strdup(*saved)))
    return (-1);
  free(*saved);
  while (tmp[++len] != '\0')
    if (tmp[len] == '\n')
      break;
  if (!(toreturn = (char *)malloc(len + 1)))
    return (-1);
  toreturn[len] = '\0';
  while (len > ++x)
    toreturn[x] = tmp[x];
  if (!(**line = ft_strdup(toreturn)))
    return (-1);
  free(toreturn);
  if (!(*saved = ft_strdup(&tmp[len + 1])))
    return (-1);
  free(tmp);
  return (1);
}

int get_next_line(int fd, char **line)
{
  static char *global[255];
  int ret;

  ret = 0;
  if (fd >= 0)
  {
    if (ft_checksave(global[fd]) == 1)
      ret = ft_noread(&global[fd], &line);
    else
      ret = ft_read(fd, &line, &global[fd]);
    // if (ret == 0)
    //   free(global[fd]);
    // printf("saved : %s\n", global[fd]);
    return (ret);
  }
  return (-1);
}
