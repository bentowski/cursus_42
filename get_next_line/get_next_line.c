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
  while (courant != '\n')
  {
    s = ft_realloc(s, courant);
		s[i] = courant;
		i++;
		s[i] = '\0';
    if(!(read(fd, &courant, 1)))
			return (-1);
  }
	*line = ft_strdup(s);
	ft_putstr_fd(*line);
	if (courant == 0)
		return (0);
  return (1);
}
