#include "get_next_line.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *psrc;
	char *pdst;
	size_t x;

	x = 1;
	psrc = (char *)src;
	pdst = (char *)dst;
	if (!src && !dst)
		return (NULL);
	while (n > x)
	{
		pdst[x - 1] = psrc[x];
		x++;
	}
	pdst[x - 1] = '\0';
	return (dst);
}

static char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*cpy;

	len = 0;
	while (s1[len])
		len++;
	if (!(cpy = (char *)malloc(len + 1)))
		return (NULL);
	ft_memcpy(cpy, s1, len);
	return (cpy);
}

static char *ft_realloc(char *s, char add)
{
  int x;
	int i;
  char *new;
	char *tmp;

  x = 0;
	i = 0;
	tmp = s;
  while (s[x] != '\0')
		x++;
  if (!((new = (char*)malloc(x + 2))))
    return (NULL);
  while (x > i)
  {
    new[i] = s[i];
    i++;
  }
	new[i + 1] = add;
	new[i + 2] = '\0';
	free(tmp);
  return (new);
}

char	**new_tab(int fd, int n, char **tab)
{
	int		x;
	char	**next_tab;

	if (!(next_tab = (char **)malloc(n + 1)))
	return (NULL);
	x = 0;
	while (x < n)
	{
		if (!(next_tab[x] = ft_strdup(tab[x])))
		return (NULL);
		x++;
	}
	free(tab);
	if(!(next_tab[n] = (char *)malloc(2)))
	return (NULL);
	next_tab[n][0] = fd;
	next_tab[n][1] = '\0';
	next_tab[n + 1] = NULL;
	return (next_tab);
}

int ft_carry(char **s, int x, int fd, char ***line)
{
	char courant;
	int i;
	int ret;

	i = 1;
	if ((ret = read(fd, &courant, 1)) < 0)
		return (-1);
	while (courant != '\n' && courant != '\0')
	{
		s[x] = ft_realloc(s[x], courant);
		s[x][i] = courant;
		i++;
		s[x][i] = '\0';
		if ((ret = read(fd, &courant, 1)) < 0)
			return (-1);
	}
	**line = ft_strdup(s[x]);
	return (ret);
}
