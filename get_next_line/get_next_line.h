#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int get_next_line(int fd, char **line);
char	**new_tab(int fd, int n, char **tab);
int ft_carry(char **s, int x, int fd, char ***line);

#endif
