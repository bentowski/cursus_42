#include "minishell.h"

int select_cmd(char **cmd_parts)
{
  int (*functions[7])(char **cmd_parts);
  int len;
  int x;
  char *cmd;
  char *lst[8] = { "echo", "cd", "pwd", "export", "unset", "env", "exit" };

  functions[0] = ft_echo;
  functions[1] = ft_cd;
  functions[2] = ft_pwd;
  functions[3] = ft_export;
  functions[4] = ft_unset;
  functions[5] = ft_env;
  functions[6] = ft_exit;
  if (cmd_parts[0])
  {
    x = -1;
    len = ft_strlen(cmd_parts[0]);
    while (lst[++x])
      if (ft_strncmp(cmd_parts[0], lst[x], len))
        (*functions[x])(cmd_parts);
  }
  return (-1);
}

int main()
{
  char *line;
  char **cmd_parts;
  char separator;
  int x;

  separator = 32;
  while (1)
  {
    x = 0;
    write(1, "minishell $> ", 13);
    cmd_parts = NULL;
    line = NULL;
    get_next_line(0, &line);
    cmd_parts = ft_split(line, separator);
    free(line);
    if (select_cmd(cmd_parts) == 0)
      break;
    while (cmd_parts[x])
      free(cmd_parts[x++]);
    free(cmd_parts[x]);
    free(cmd_parts);
  }
  return (EXIT_SUCCESS);
}
