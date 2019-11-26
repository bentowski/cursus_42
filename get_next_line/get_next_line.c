#include "get_next_line.h"

void	ft_putchar_fd(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_fd(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s);
		s++;
	}
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

static char	**new_tab(int fd, int n, char **tab)
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

int ft_carry(char **s, int x, int fd)
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
	return (ret);
}

int get_next_line(int fd, char **line)
{
	static char **s;
  char courant;
  int i;
	int x;
	int ret;

	i = 1;
	if (!(s))
	{
		if (!(s = first_tab(fd)))
			return (-1);
	}
	else if ((x = ft_check(&s, fd)) < 0)
		return (-1);
	ret = ft_carry(&*s, x, fd);
	if (ret == 0)
	{
		write(1, "sortie\n", 7);
		return (0);
	}
	else
	{
		*line = ft_strdup(s[x]);
		ft_putstr_fd(*line);
	}
	write(1, "\n", 1);
  return (1);
}
