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
  t_list *previous;
  t_list *next;
};

int get_next_line(int fd, char **list);


#endif
