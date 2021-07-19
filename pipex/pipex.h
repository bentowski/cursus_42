#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

// typedef struct s_list
// {
//   char **content;
//   struct s_cmd	*next;
// }             t_cmd;

typedef struct s_struct
{
  char *f1;
  char *f2;
  t_list *cmds;
}             t_struct;
