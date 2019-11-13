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

size_t	ft_strlen(const char *s)
{
	size_t x;

	x = 0;
	while (*s)
	{
		x++;
		s++;
	}
	return (x);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *psrc;
	char *pdst;

	psrc = (char *)src;
	pdst = (char *)dst;
	if (!src && !dst)
		return (NULL);
	while (n > 0)
	{
		pdst[n - 1] = psrc[n - 1];
		n--;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*cpy;

	len = ft_strlen(s1) + 1;
	if (!(cpy = (char *)malloc(len)))
		return (NULL);
	ft_memcpy(cpy, s1, len);
	return (cpy);
}


char *ft_realloc(char *s, char add)
{
  int x;
	int i;
  char *new;

  x = 0;
	i = 0;
  while (s[x] != '\0')
    x++;
  if (!((new = (char*)malloc(x + 2))))
    return (NULL);
  while (x >= i)
  {
    new[i] = s[i];
    i++;
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
  if (!(s = (char*)malloc(2)))
    return (-1);
	s[1] = '\0';
  if (!(read(fd, &courant, 1)))
    return (-1);
  while (courant != '\n' && courant != '\0')
  {
    s = ft_realloc(s, courant);
		s[i] = courant;
		i++;
		s[i] = '\0';
    if(!(read(fd, &courant, 1)))
      return (-1);
  }
	*line = ft_strdup(s);
	printf("%s\n", *line);
	if (courant == '\0')
	{
		write(1, "end", 3);
		return (0);
	}
  return (1);
}
