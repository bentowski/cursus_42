
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
  int width;
  int neg;
  int zero;
  int cutter;
  int decalage;
  int printed;
  int constantep;
  int constantew;
}               t_flags;

int ft_printf(const char *line, ...);
int ft_nblenx(unsigned int nb, int opt);
int ft_nblend(int nb);
void ft_X(va_list *list_args, t_flags *flags);
void ft_x(va_list *list_args, t_flags *flags);
void ft_p(va_list *list_args, t_flags *flags);
void ft_u(va_list *list_args, t_flags *flags);
void ft_s(va_list *list_args, t_flags *flags);
void ft_c(va_list *list_args, t_flags *flags);
void ft_d(va_list *list_args, t_flags *flags);
void ft_putunbr_fd(long int n, int fd);
void ft_candwrite(t_flags *flags, unsigned long int nb, int opt);
void ft_write(char c, t_flags *flags);
void ft_flags(va_list *list_args, t_flags *flags);




#endif
