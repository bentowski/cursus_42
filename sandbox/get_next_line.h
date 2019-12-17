#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list t_list;

struct s_list
{
  char *str;
  int fd;
  t_list *next;
};

int get_next_line(int fd);
// char	**new_tab(int fd, int n, char **tab);
// int ft_carry(char **s, int x, int fd, char ***line);
// void	ft_putstr_fd(char *s);

#endif
