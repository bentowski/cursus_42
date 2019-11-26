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

static char **first_tab(int fd)
{
	char **first_tab;

	if (!(first_tab = (char **)malloc(2)))
		return (NULL);
	if (!(first_tab[0] = (char *)malloc(2)))
		return (NULL);
	first_tab[0][0] = fd;
	first_tab[0][1] = '\0';
	first_tab[1] = NULL;
	return (first_tab);
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
	if (ret == ft_carry(&*s, x, fd, &line))
		return (0);
	else
		ft_putstr_fd(*line);
	write(1, "\n", 1);
  return (1);
}
