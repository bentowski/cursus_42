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


char				*ft_itoa(int n, int size)
{
	char	*str;

	if (!(str = (char *)malloc(size)))
		return (0);
	str[size - 1] = '\0';
	if (n == 0)
		str[0] = '0';
	else
	{
		while (n > 0)
		{
			str[size - 2] = n % 10 + '0';
			n /= 10;
			size--;
		}
	}
	return ((char *)str);
}



static char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*cpy;
  size_t x;

	len = 0;
  x = 0;
  if (!s1)
    return (NULL);
	while (s1[len])
		len++;
	if (!(cpy = (char *)malloc(len + 1)))
		return (NULL);
  while(x < len)
  {
    cpy[x]= s1[x];
    x++;
  }
  cpy[x] = '\0';
	return (cpy);
}


static char *ft_realloc(char *s, char courant)
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
	new[i] = courant;
	new[i + 1] = '\0';
	free(tmp);
  return (new);
}


static int ft_carry(char **s, int fd, char ***line)
{
	char *courant;
	int i;
  char *save;
	int ret;
	int y;
	int n;

	n = 0;
	y = 0;
  if (!(save = (char *)malloc(BUFFER_SIZE + 1)))
    return (-1);
	if (!(courant = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
  if (s)
    save = ft_strdup(*s);
	while (n == 0)
	{
		i = 0;
		if ((ret = read(fd, courant, BUFFER_SIZE)) < 0)
			return (-1);
		if (courant[i] == '\0')
			n = 1;
		else
			while (i < ret && courant[i] != '\n' && courant[i] != '\0')
				save = ft_realloc(save, courant[i++]);
		if (courant[i] == '\n')
			n = 1;
    }
	**line = ft_strdup(save);
	return (ret);
}


static char	**new_tab(char *fd, int n, char **tab, int size)
{
	int		x;
	char	**next_tab;

	if (!(next_tab = (char **)malloc(n + 1)))
		return (NULL);
	x = -1;
	while (++x < n)
		if (!(next_tab[x] = ft_strdup(tab[x])))
			return (NULL);
	free(tab);
	if(!(next_tab[n] = (char *)malloc(BUFFER_SIZE + size + 1)))
		return (NULL);
  next_tab[n][BUFFER_SIZE + 1 + size] = '\0';
	while (size > 0)
  {
    next_tab[n][BUFFER_SIZE + size] = fd[size - 1];
    size--;
  }
  while (size >= -BUFFER_SIZE)
  {
    next_tab[n][BUFFER_SIZE + size] = '\0';
    size--;
  }
	next_tab[n + 1] = NULL;
	return (next_tab);
}


int get_next_line(int fd, char **line)
{
	static char **s;
	int x;
	int ret;
  int size;
  char *ffd;
  int nb;

  nb = fd;
  size = 2;
  while (nb / 10 > 0)
  {
    nb /= 10;
    size++;
  }
	x = 0;
	ret = 0;
  ffd = ft_itoa(fd, size);
  printf("fd : %d\n", fd);
  if (s)
  {printf("x1 : %d\n", x);
    printf("buffer : %s\n", &s[x][BUFFER_SIZE + 1]);
    printf("ffd : %s\n", ffd);
    printf("size : %d\n", size);
    while (s[x])
    {
        if (&s[x][BUFFER_SIZE + 3] != ffd)
        {
          x++;
        }
        else
        {
          printf("yeeeeesssssssssssss %d\n", x);
          break;
        }
    }
  }
  if (!(s = new_tab(ffd, x, s, size)))
    return (-1);
  printf("x : %d\n", x);
	if (ret == ft_carry(&s[x], fd, &line))
		return (0);
	write(1, "\nline : ", 8);
	ft_putstr_fd(*line);
	write(1, "\n", 1);
	return (1);
}
