#include "minishell.h"

int ft_echo(char **cmd_parts)
{
  int x;
  int n;

  printf("%s\n", "OK");
  if (!(cmd_parts[1]))
    return (-1);
  x = 1;
  n = ft_strncmp(cmd_parts[1], "-n", 2);
  if (n == 0)
    x = 2;
  while (cmd_parts[x])
  {
    ft_putstr_fd(cmd_parts[x++], 1);
    if (cmd_parts[x])
      write(1, " ", 1);
  }
  if (n != 0)
    write(1, "\n", 1);
  return (1);
}

int cd_pp(char **cmd_parts, int lenght, char *buf)
{
  char *new;
  int len;

  len = lenght;
  while (buf[len] != '/')
    len--;
  if (!(new = malloc(len * sizeof(char))))
    return (-1);
  new[len] = '\0';
  while (len-- != 0)
    new[len] = buf[len];
  chdir(new);
  free(buf);
  free(new);
  return (1);
}

// int cd_abs(char **cmd_parts, int lenght)
// {
//
// }

int cd_base(char **cmd_parts, int lenght, char *buf)
{
  char *new;
  int len;
  int x;
  int y;

  x = 0;
  y = 0;
  while (y < 3)
    if (buf[x++] == '/')
      y++;
  y = -1;
  if (!(new = malloc((x - 1) * sizeof(char))))
    return (-1);
  while (++y < x)
    new[y] = buf[y];
  chdir(new);
  free(new);
  free(buf);
  return (1);
}

int cd_relative(char **cmd_parts, int lenght, char *buf)
{
  char *new;
  int len;
  int x;

  printf("%s\n", "OK");
  len = lenght + ft_strlen(cmd_parts[1]);
  x = -1;
  if (!(new = malloc(len)))
    return (-1);
  while (buf[++x])
    new[x] = buf[x];
  x = -1;
  while (cmd_parts[1][++x])
    new[x + lenght] = cmd_parts[1][x];
  printf("%s\n", new);
  chdir(new);
  free(new);
  free(buf);
  return (1);
}

int ft_cd(char **cmd_parts)
{
  char *buf;
  size_t len;

  len = 0;
  if (!(buf = malloc(len * sizeof(char))))
    return (-1);
  while (getcwd(buf, len) == NULL)
  {
    free(buf);
    if (!(buf = malloc(len * sizeof(char))))
      return (-1);
    len++;
  }
  if (cmd_parts[1] == NULL)
  {
    if (cd_base(cmd_parts, len, buf) != 1)
      return (-1);
  }
  else if (cmd_parts[2] != NULL)
    return (-1);
  else if (ft_strncmp(cmd_parts[1], "..", 2) == 0)
  {
    if (cd_pp(cmd_parts, len, buf) != 1)
      return (-1);
  }
  else
  {
    if (ft_strncmp(cmd_parts[1], buf, len) != 0)
      if (cd_relative(cmd_parts, len, buf) != 1)
        return (-1);
  }
  return (1);
}

int ft_pwd(char **cmd_parts)
{
  char *buf;
  size_t len;

  len = 0;
  if (!(buf = malloc(len * sizeof(char))))
    return (-1);
  while (getcwd(buf, len) == NULL)
  {
    free(buf);
    if (!(buf = malloc(len * sizeof(char))))
      return (-1);
    len++;
  }
  ft_putstr_fd(buf, 1);
  write(1, "\n", 1);
  free(buf);
  return (1);
}

int ft_export(char **cmd_parts)
{
  return (1);
}

int ft_unset(char **cmd_parts)
{
  return (1);
}

int ft_env(char **cmd_parts)
{
  return (1);
}

int ft_exit(char **cmd_parts)
{
  return (0);
}
