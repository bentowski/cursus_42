# include "ft_printf.h"

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

void ft_x(va_list *list_args, t_flags *flags)
{
  unsigned long int nb;

  if (flags->constantep == 1)
    flags->precision = va_arg(*list_args, int);
  nb = va_arg(*list_args, unsigned long int);
  if (flags->precision != 0)
    flags->precision -= ft_nblenx(nb, 16);
  if (nb == 0 && flags->cutter == 1 && flags->precision == 0)
    return;
  if (flags->neg == 1 && flags->cutter == 0)
  {
    ft_candwrite(flags, nb, 1);
    while (flags->precision-- > 0)
      ft_write(' ', flags);
  }
  else
  {
    if (flags->zero ==1 || flags->cutter == 1)
      while (flags->precision-- > 0)
        ft_write('0', flags);
    else
      while (flags->precision-- > 0)
        ft_write(' ', flags);
    ft_candwrite(flags, nb, 1);
  }
}

void ft_X(va_list *list_args, t_flags *flags)
{
  unsigned long int nb;

  if (flags->constantep == 1)
    flags->precision = va_arg(*list_args, int);
  nb = va_arg(*list_args, unsigned long int);
  if (flags->precision != 0)
    flags->precision -= ft_nblenx(nb, 16);
  if (nb == 0 && flags->cutter == 1 && flags->precision == 0)
    return;
  if (flags->neg == 1 && flags->cutter == 0)
  {
    ft_candwrite(flags, nb, 2);
    while (flags->precision-- > 0)
      ft_write(' ', flags);
  }
  else
  {
    if (flags->zero ==1 || flags->cutter == 1)
      while (flags->precision-- > 0)
        ft_write('0', flags);
    else
      while (flags->precision-- > 0)
        ft_write(' ', flags);
    ft_candwrite(flags, nb, 2);
  }
}
