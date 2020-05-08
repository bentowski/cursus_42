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
  int len;
  int rest;

  ft_flags(list_args, flags);
  nb = va_arg(*list_args, unsigned long int);
  len = ft_nblenx(nb, 16);
  if (nb == 0 && flags->cutter == 1 && flags->precision <= 0)
  {
    if (flags->precision == 0)
      while (flags->width-- > 0)
        ft_write(' ', flags);
    else if (flags->precision < 0 && flags->width <= 1)
      ft_write('0', flags);
    if (flags->width <= 1)
      return;
  }
  if (flags->precision < 0)
    flags->precision = 0;
  if (flags->precision < 0 || (flags->precision <= len && flags->cutter == 1))
    rest = len;
  else
    rest = flags->precision + len;
  if (flags->neg == 0)
  {
    while (flags->width-- > flags->precision + len)
    {
      if (flags->zero == 1 && (flags->cutter == 0 || flags->precision < 0))
        ft_write('0', flags);
      else
        ft_write(' ', flags);
    }
    while (flags->precision-- > len)
        ft_write('0', flags);
    ft_candwrite(flags, nb, 1);
  }
  else
  {
    while (flags->precision-- > len)
      ft_write('0', flags);
    ft_candwrite(flags, nb, 1);
    if (nb == 0 && flags->cutter == 1 && flags->precision < -1)
      ft_write('0', flags);
    if (flags->width > rest)
      while (flags->width-- > rest && flags->width > 0)
        ft_write(' ', flags);
  }
}

void ft_X(va_list *list_args, t_flags *flags)
{
  unsigned long int nb;
  int len;
  int rest;

  ft_flags(list_args, flags);
  nb = va_arg(*list_args, unsigned long int);
  len = ft_nblenx(nb, 16);
  if (nb == 0 && flags->cutter == 1 && flags->precision <= 0)
  {
    if (flags->precision == 0)
      while (flags->width-- > 0)
        ft_write(' ', flags);
    else if (flags->precision < 0 && flags->width <= 1)
      ft_write('0', flags);
    if (flags->width <= 1)
      return;
  }
  if (flags->precision < 0)
    flags->precision = 0;
  if (flags->precision < 0 || (flags->precision <= len && flags->cutter == 1))
    rest = len;
  else
    rest = flags->precision + len;
  if (flags->neg == 0)
  {
    while (flags->width-- > flags->precision + len && flags->width > 0)
    {
      if (flags->zero == 1 && (flags->cutter == 0 || flags->precision < 0))
        ft_write('0', flags);
      else
        ft_write(' ', flags);
    }
    while (flags->precision-- > len)
        ft_write('0', flags);
    ft_candwrite(flags, nb, 2);
  }
  else
  {
    while (flags->precision-- > len)
      ft_write('0', flags);
    ft_candwrite(flags, nb, 2);
    if (nb == 0 && flags->cutter == 1 && flags->precision < -1)
      ft_write('0', flags);
    if (flags->width > rest)
      while (flags->width-- > rest && flags->width > 0)
        ft_write(' ', flags);
  }
}
