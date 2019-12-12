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


static char	*ft_itoa(int n, int size)
{
	char	*str;

	if (!(str = (char *)malloc(size)))
		return (0);
	str[size - 1] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[size - 2] = n % 10 + '0';
		n /= 10;
		size--;
	}
	return ((char *)str);
}



static char	*ft_strdup(const char *s1, int n, int select)
{
	int	len;
	char	*cpy;
  int x;

  x = -1;
  if (select == 0)
  {
    len = 0;
    if (!s1)
      return (NULL);
    while (s1[len++]);
    if (!(cpy = (char *)malloc(len + 1)))
      return (NULL);
    while(++x < len)
      cpy[x]= s1[x];
  }
  else if (!(cpy = (char *)malloc(n - 1)))
    return (NULL);
  else
    while (x++ < n)
      cpy[x] = s1[x];
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
	i = -1;
	tmp = s;
  while (s[x] != '\0')
		x++;
  if (!((new = (char*)malloc(x + 2))))
    return (NULL);
  while (x > ++i)
    new[i] = s[i];
	new[i] = courant;
	new[i + 1] = '\0';
	free(tmp);
  return (new);
}


static int ft_carry(char ***s, int y, int fd, char ***line)
{
	char *courant;
	int i;
  char *save;
	int ret;
  int x;
  char **s2;

  x = 0;
  s2 = s[y];
  printf("s2 : %s\n", *s2);
	if (!(courant = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
  save = ft_strdup(*s2, 0 , 0);
	while (1)
	{
		i = 0;
		if ((ret = read(fd, courant, BUFFER_SIZE)) < 0)
			return (-1);
		if (courant[i] == '\0')
			break;
		else
			while (i < ret && courant[i] != '\n' && courant[i] != '\0')
				save = ft_realloc(save, courant[i++]);
		if (courant[i] == '\n')
			break;
  }
	**line = ft_strdup(save, 0, 0);
  free(save);
  while (i++ < ret)
    s[y][x++] = &courant[i];
	return (ret);
}


static char	**new_tab(char *fd, int n, char **tab, int size)
{
	int		x;
	char	**next_tab;
  if (!*tab[n])
  {
    write(1, "ok\n", 3);
    if (!(next_tab = (char **)malloc(n + 2)))
    return (NULL);
    x = -1;
    while (++x <= n)
    if(!(next_tab[n] = (char *)malloc(BUFFER_SIZE + size + 2)))
    return (NULL);
    x = -1;
    if (tab)
    while(++x < n)
    if (!(next_tab[x] = ft_strdup(tab[x], BUFFER_SIZE + size + 1, 1)))
    return (NULL);
    if (tab)
    printf("next : %s\n", next_tab[0]);
    free(tab);
    next_tab[n][BUFFER_SIZE + size + 1] = '\0';
    size++;
    while (--size > 0)
    next_tab[n][BUFFER_SIZE + size] = fd[size - 1];
    next_tab[n][BUFFER_SIZE + size] = '\0';
    next_tab[n + 1] = NULL;
    return (next_tab);
  }
  else
    return (tab);
}


int get_next_line(int fd, char **line)
{
	static char **s;
	int x;
	int ret;
  int size;
  char *ffd;
  int nb;
  int y;

  nb = fd;
  size = 2;
  y = 1;
  while (nb / 10 > 0)
  {
    nb /= 10;
    size++;
  }
	x = 0;
	ret = 0;
  ffd = ft_itoa(fd, size);
  if (!s)
    if (!(s = (char **)malloc(2)))
      return (-1);
  //   while (s[x])
  //   {
  //       if (s[x][BUFFER_SIZE + 1] == *ffd)
  //         break;
  //       else
  //         x++;
  //   }

  if (!(s = new_tab(ffd, x, s, size + 1)))
    return (-1);
  printf("s2 : %s\n", *s);
	if ((ret = ft_carry(&s, x, fd, &line)) < 0)
		return (0);
  printf("s : %s\n", *s);
  write(1, "\nline : ", 8);
  ft_putstr_fd(*line);
  write(1, "\n", 1);
	return (1);
}
