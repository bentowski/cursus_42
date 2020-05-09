# include "ft_printf.h"

static void ft_sgestion(t_flags *flags, int x, int lenght, char *s)
{
  if (flags->cutter == 0)
    if (flags->width > lenght)
      while (flags->width-- > lenght)
        ft_write(' ', flags);
  if (flags->cutter == 1)
  {
    if (flags->width >= flags->precision && flags->precision >= lenght)
      while (flags->width-- > lenght)
        ft_write(' ', flags);
    else if (flags->width >= flags->precision && flags->precision < lenght)
      while (flags->width-- > flags->precision)
        ft_write(' ', flags);
    else if (flags->width < flags->precision && flags->precision > lenght)
      while (flags->width-- > lenght)
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
  if (flags->precision < 0)
    flags->precision = lenght;
  if (flags->neg == 0)
    ft_sgestion(flags, x, lenght, s);
  if (flags->cutter == 0)
    while (s[x])
      ft_write(s[x++], flags);
  else if (flags->precision >= lenght)
    while (x < lenght)
      ft_write(s[x++], flags);
  else
    while (x < flags->precision)
      ft_write(s[x++], flags);
  if (flags->neg == 1)
    ft_sgestion(flags, x, lenght, s);
}

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

void ft_p(va_list *list_args, t_flags *flags)
{
  unsigned long int x;

  if (flags->constantep == 1)
    flags->precision = va_arg(*list_args, int) - 14;
  else
    flags->precision -= 14;
  x = va_arg(*list_args, unsigned long int);
  if (flags->neg == 0)
  {
    while (flags->precision-- > 0)
      ft_write(' ', flags);
    write(1, "0x", 2);
    ft_candwrite(flags, x, 1);
  }
  else
  {
    write(1, "0x", 2);
    ft_candwrite(flags, x, 1);
    while (flags->precision-- > 0)
      ft_write(' ', flags);
  }
}
