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

char *ft_realloc(char *s, char add)
{
  int x;
	int i;
  char *new;

  x = 0;
  while (s[x] != '\0')
    x++;
	printf("%d\n", x);
  if (!((new = (char*)malloc(x + 2))))
    return (NULL);
  while (x >= i)
  {
    new[i] = s[i];
    i--;
  }
	new[i + 1] = add;
	new[i + 2] = '\0';
  return (new);
}

int get_next_line(int fd, char **line)
{
  char *s;
  char courant;
  int i;


  i = 0;
  if (!(s = (char*)malloc(1)))
    return (-1);
	s[1] = '\0';
  if (!(read(fd, &courant, 1)))
    return (-1);
	s[i] = courant;
  while (courant != '\n' && courant != '\0')
  {
    s = ft_realloc(s, courant);
		s[i] = courant;
		i++;
		s[i] = '\0';
    if(!(read(fd, &courant, 1)))
      return (-1);
    // printf("%s", s);
  }
  return (1);
}
