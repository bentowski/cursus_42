#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int ft_strlen(char *s)
{
  int i;

  i = 0;
  while (s[i] && s[i] != '\0')
    i++;
  return (i);
}

char *ft_strjoin(char *s1, char *s2, int opt)
{
  char *ret;
  int i;
  int j;

  i = 0;
  j = 0;
  if (!(s1 || s2))
    return (NULL);
  if (!(ret = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
    return (NULL);
  while (s1[i] && s1[i] != '\n')
  {
    ret[i] = s1[i];
    i++;
  }
  while(s2[j] && s2[j] != '\n')
    ret[i++] = s2[j++];
  ret[i] = '\0';
  if (opt == 2)
    free(s1);
  return (ret);
}

int ft_doublon(char *s)
{
  int i;
  int j;

  i = -1;
  j = 0;
  while (s[++i])
    if (s[i] == '\n')
    {
      while (s[++i] != '\0')
        s[j++] = s[i];
      s[j] = '\0';
      return (1);
    }
  return (0);
}

int ft_read(char ***line, int fd, char *buffer)
{
  int ret;

  while ((ret = read(fd, buffer, BUFFER_SIZE)) >= 0)
  {
    buffer[ret] = '\0';
    if (!(**line = ft_strjoin(**line, buffer, 2)))
      return (-1);
    if (ft_doublon(buffer) == 1)
      return (1);
    if (ret == 0)
      return (0);
  }
  free(**line);
  return (-1);
}

int get_next_line(int fd, char **line)
{
  static char buffer[256][BUFFER_SIZE + 1];

  if (fd <= 0 || BUFFER_SIZE <=0)
    return (-1);
  if (!(*line = ft_strjoin(buffer[fd], "", 1)))
    return (-1);
  if (ft_doublon(buffer[fd]) == 1)
    return (1);
  return (ft_read(&line, fd, buffer[fd]));
}

// int main(int argc, char **argv)
// {
//   if (argc > 1)
//   {
//     int fd;
//     char *line;
//     int x;
//
//     x = 1;
//     fd = open(argv[1], O_RDONLY);
//     while (get_next_line(fd, &line) > 0)
//     {
//       printf("%d) %s\n", x, line);
//       free(line);
//       x++;
//     }
//     printf("%d) %s", x, line);
//     free(line);
//     system("leaks a.out");
//     return (0);
//   }
//   return (-1);
// }
