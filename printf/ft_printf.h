
#ifndef PRINTF_H
# define PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_struct
{
  int precision;
  int negative;
  int zero;
  int cutter;
  int decalage;
  int constante;
}               t_flags;

int ft_printf(const char *line, ...);

#endif
