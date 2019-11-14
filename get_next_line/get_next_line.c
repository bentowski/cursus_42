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
  while (x >= i)
  {
    new[i] = s[i];
    i++;
  }
	new[i + 1] = add;
	new[i + 2] = '\0';
	free(tmp);
  return (new);
}

static char	**new_tab(int fd, char **tab)
{
	int		n;
	char	**next_tab;

	if (!(next_tab = (char **)malloc(fd + 1)))
		return (NULL);
	n = 0;
	while (n < fd)
	{
		next_tab[n] = tab[n];
		n++;
	}
	free(tab);
	if(!(tab[n] = (char *)malloc(2)))
		return (NULL);
	next_tab[fd][0] = ft_itoa(fd);
	next_tab[fd][1] = '\0';
	next_tab[fd + 1] = NULL;
	return (next_tab);
}

static char **first_tab(int fd)
{
	char **first_tab;

	if (!(first_tab = (char **)malloc(2)))
		return (NULL);
	if (!(first_tab[0] = (char *)malloc(2)))
	first_tab[0][0] = ft_itoa(fd);
	first_tab[0][1] = '\0';
	first_tab[1] = NULL;
	write(1, "test\n", 5);
	return (first_tab);
}

static int ft_check(char **s, int fd)
{
	int n;

	n = -1;
	while (s[++n])
		if (s[n][0] == 4)
			return (n);
	if (!(s = new_tab(fd, s)))
		return (-1);
	write(1, "aaaaaah", 7);
	return (0);
}

int get_next_line(int fd, char **line)
{
	static char **s;
  char courant;
  int i;
	int x;
	int ret;

	i = 0;
	if (!(s))
	{
		if (!(s = first_tab(fd)))
			return (-1);
	}
	if (!(x = ft_check(s, fd)))
		return (-1);
  if (!(ret = read(fd, &courant, 1)))
		return (-1);
  while (courant != '\n' && courant != '\0')
  {
    s[x] = ft_realloc(s[x], courant);
		s[x][i] = courant;
		i++;
		s[x][i] = '\0';
    if(!(ret = read(fd, &courant, 1)))
		{
			return (-1);
		}
  }
	*line = ft_strdup(s[x]);
	ft_putstr_fd(*line);
	if (ret == 0)
	{
		write(1, "sortie", 6);
		return (0);
	}
	write(1, "\n", 1);
  return (1);
}
