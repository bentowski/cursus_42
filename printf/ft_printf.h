
#ifndef PRINTF_H
# define PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

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
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);

#endif
