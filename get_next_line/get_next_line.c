#include "get_next_line.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char *ft_realloc(char *s)
{
  int x;
  char *new;

  x = 0;
  while (*s)
    x++;
  write(1 , "realloc\n", 7);
  if (!((new = (char*)malloc(x + 2))))
    return (NULL);
  new[x + 1] = '\0';
  while (x >= 0)
  {
    new[x] = s[x];
    x--;
  }
  return (new);
}

int get_next_line(int fd, char **line)
{
  char *s;
  char courant;
  int i;


  i = 0;
  courant = 'n';
  if (!(s = (char*)malloc(2)))
    return (-1);
  if (!(read(fd, &courant, 1)))
    return (-1);
  while (courant != '\n' && courant != '\0')
  {
    s[i] = courant;
    i++;
    s = ft_realloc(s);
    write(1, "p\n", 2);
    if(!(read(fd, &courant, 1)))
      return (-1);
    printf("%s", s);
  }
  return (1);
}
