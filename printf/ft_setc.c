# include "ft_printf.h"

void ft_c(va_list *list_args, t_flags *flags)
{
  char c;

  ft_flags(list_args, flags);
  c = va_arg(*list_args, int);
  if (flags->neg == 0)
  {
    while (--flags->precision > 0)
      ft_write(' ', flags);
    ft_write(c, flags);
  }
  else
  {
    ft_write(c, flags);
    while (--flags->precision > 0)
      ft_write(' ', flags);
  }
}

void ft_s(va_list *list_args, t_flags *flags)
{
  char *s;
  int lenght;
  int x;

  x = 0;
  ft_flags(list_args, flags);
  s = va_arg(*list_args, char *);
  lenght = ft_strlen(s);
  printf("[%d, %d, %d] ", lenght, flags->width, flags->precision);
  if (flags->cutter == 1 && flags->precision == 0)
  {
    while (flags->width-- > 0)
      ft_write(' ', flags);
    return;
  }
  if (lenght > flags->precision && flags->cutter == 1 && flags->neg == 0)
    while (flags->precision-- > 0)
      ft_write(s[x++], flags);
  else if (flags->cutter == 1 && flags->width == 0)
    while (s[x])
      ft_write(s[x++], flags);
  else if (flags->neg == 0)
  {
    while (flags->width-- > flags->precision + lenght)
      ft_write(' ', flags);
    while (flags->precision-- > lenght && flags->precision >= 0)
      ft_write(' ', flags);
    while(s[x])
      ft_write(s[x++], flags);
  }
  else
  {
    while (s[x])
      ft_write(s[x++], flags);
    // if (flags->width > flags->precision + lenght)
    //   while (flags->width-- > flags->precision + lenght)
    //     ft_write(' ', flags);
    // else
    //   while (flags->width-- > lenght)
    //     ft_write(' ', flags);
    while (flags->precision-- > lenght)
      ft_write(' ', flags);
  }
}
