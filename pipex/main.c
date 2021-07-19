#include "pipex.h"

void ft_free(t_list *cmds)
{
  t_list *tmp;
  t_list *fr;

  tmp = cmds;
  while (tmp)
  {
    fr = tmp->next;
    free(tmp);
    tmp = fr;
  }
}

char *ft_search_path_line_in_env(char **env)
{
  int i;

  i = -1;
  while (env[++i])
  {
    if (ft_strncmp("PATH", env[i], 4) == 0)
      return (env[i]);
  }
  return (NULL);
}

char *get_path(void *cmd, char **env)
{
  char **possible;
  char *path_line;
  char *end_path;
  int x;
  char **i;

  path_line = ft_search_path_line_in_env(env);
  possible = ft_split(ft_substr(path_line, 5, ft_strlen(path_line) - 5), ':');
  i = ft_split(cmd, ' ');
  end_path = i[0];
  while (possible[x])
  {
    possible[x] = ft_strjoin(possible[x], "/");
    possible[x] = ft_strjoin(possible[x], end_path);
    if (access(possible[x], F_OK) == 0)
      return (possible[x]);
    x++;
  }
  return (NULL);
}

int ft_execute(t_list *cmds, char **env)
{
  char *path;
  char *path_line;
  char **cmd;
  int x;
  int pid;
  int ret;
  int fd[2];

  path = get_path(cmds->content, env);
  pipe(fd);
  pid = fork();
  if (pid == 0)
  {
    close(fd[0]);
    dup2(fd[1], 1);
    cmd = ft_split(cmds->content, ' ');
    execve(path, &cmd[0], env);
  }
  else
  {
    close(fd[1]);
    dup2(fd[0], 0);
    cmds = cmds->next;
    path = get_path(cmds->content, env);
    cmd = ft_split(cmds->content, ' ');
    execve(path, &cmd[0], env);
  }
  x = 0;
  return (1);
}

t_struct ft_parse(char **argv)
{
  t_struct lst;
  int x;

  x = 2;
  lst.f1 = argv[1];
  while (argv[x + 1])
    ft_lstadd_back(&lst.cmds, ft_lstnew(argv[x++]));
  lst.f2 = argv[x];
  return (lst);
}

int main(int argc, char **argv, char **env)
{
  t_struct lst;
  int ret;
  int pid;

  if (argc >= 5)
  {
    lst = ft_parse(argv);
    pid = fork();
    if (pid == 0)
      ft_execute(lst.cmds, env);
    else
    {
      waitpid(pid, &ret, 0);
      ft_free(lst.cmds);
    }
    return (0);
  }
  printf("%s\n", "Bad, to much or missing any arguments");
  return (-1);
}
