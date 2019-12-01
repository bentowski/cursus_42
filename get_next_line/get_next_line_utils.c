#include "get_next_line.h"

static void	ft_putstr_fd(char *s)
{
	int x;

	x = 0;
	if (!s)
		return ;
	while (s[x])
	{
		write(1, &s[x], 1);
		x++;
	}
}

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

static char *ft_realloc(char *s)
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
	char *courant;
	char *save;
	int i;
	int ret;
	int y;
	int n;

	n = 0;
	y = 0;
	while (s[x][y])
		y++;
	if (!(courant = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (n == 0)
	{
		i = 1;
		if ((ret = read(fd, courant, BUFFER_SIZE)) < 0)
			return (-1);
		write(1, "\ntour\n", 6);
		while (courant[i - 1] != '\n' && courant[i - 1] != '\0' && i <= ret)
		{
			s[x] = ft_realloc(s[x]);
			s[x][i] = courant[i - 1];
			i++;
			y++;
		}
		if (courant[i - 2] == '\n')
		{
			write(1, "\nok\n", 4);
			n = 1;
		}
	}
	s[x][y] = '\0';
	y = 0;
	if(!(save = (char *)malloc(BUFFER_SIZE - i + 2)))
		return (-1);
	while (i++ <= ret)
	{
		save[y] = courant[i - 1];
		y++;
	}
	save[y] = '\0';
	**line = ft_strdup(s[x]);
	write(1, "s : ", 4);
	ft_putstr_fd(s[x]);
	write(1, "\nsave : ", 8);
	ft_putstr_fd(save);
	s[x] = ft_strdup(save);
	return (ret);
}
