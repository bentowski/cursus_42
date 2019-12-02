 #include "get_next_line.h"

void	ft_putstr_fd(char *s)
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






static char *ft_realloc(char **s, char courant)
{
  int x;
	int i;
  char *new;
	char *tmp;

  x = 0;
	i = 0;
	tmp = *s;
  while (s[x] != '\0')
		x++;
  if (!((new = (char*)malloc(x + 2))))
    return (NULL);
  while (x > i)
  {
    new[i] = *s[i];
    i++;
  }
	new[i] = courant;
	new[i + 1] = '\0';
	free(tmp);
  return (new);
}






static int ft_carry(char ***s, int x, int fd, char ***line)
{
	char *courant;
	int i;
	int ret;
	int y;
	int n;

	n = 0;
	y = 0;
	if (!(courant = (char *)malloc(BUFFER_SIZE + y + 1)))
		return (-1);
	while (n == 0)
	{
		i = 0;
		if ((ret = read(fd, courant, BUFFER_SIZE)) < 0)
			return (-1);
		if (courant[i] == '\0')
			n = 1;
		else
		{
			while (i < ret && courant[i] != '\n' && courant[i] != '\0')
			{
				write(1, "ok\n", 3);
				*s[x] = ft_realloc(&*s[x], courant[i]);
				i++;
			}
		}
		if (courant[i] == '\n')
			n = 1;
	}
	write(1, "\ns : ", 5);
	ft_putstr_fd(s[x][0]);
	y = 1;
	**line = ft_strdup(*s[x]);
	free(s[x][1]);
	if(!(*s[x] = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (i++ < ret)
	{
		s[x][y] = &courant[i];
		y++;
	}
	s[x][y] = 0;
	return (ret);
}






static char	**new_tab(int fd, int n, char **tab)
{
	int		x;
	char	**next_tab;
	int f;

	f = fd;
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

static int ft_check(char ***s, int fd)
{
	int n;

	n = 0;
	while (s[n])
	{
		if (*s[n][0] == fd)
			return (n);
		n++;
	}
	if (!(*s = new_tab(fd, n, *s)))
		return (-1);
	return (n);
}


int get_next_line(int fd, char **line)
{
	static char **s;
	int x;
	int ret;

	x = 0;
	ret = 0;
	if ((x = ft_check(&s, fd)) < 0)
		return (-1);
	if (!(s = new_tab(fd, x, s)))
		return (-1);
	if (ret == ft_carry(&s, x, fd, &line))
		return (0);
	else
		write(1, "\nline : ", 8);
		ft_putstr_fd(*line);
		write(1, "\n", 1);
  	return (1);
}
