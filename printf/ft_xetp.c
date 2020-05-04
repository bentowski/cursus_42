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

  ft_flags(list_args, flags, 0);
  nb = va_arg(*list_args, unsigned long int);
  len = ft_nblenx(nb, 16);
  // if (flags->precision < 0)
  //   flags->precision = 0;
  if (nb == 0 && flags->cutter == 1 && flags->precision == 0)
    return;
  if (flags->neg == 0)
  {
    while (flags->width-- > flags->precision + len)
    {
      printf("%d\n", flags->width);
      printf("[%d]\n", flags->precision);
      if (flags->zero == 1)
        ft_write('0', flags);
      else
        ft_write(' ', flags);
    }
    while (flags->precision-- > len)
    {
      if (flags->zero == 1)
        ft_write('0', flags);
      else
        ft_write(' ', flags);
    }
    ft_candwrite(flags, nb, 1);
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
  int len;

  ft_flags(list_args, flags, 0);
  nb = va_arg(*list_args, unsigned long int);
  len = ft_nblenx(nb, 16);
  if (nb == 0 && flags->cutter == 1 && flags->precision == 0)
    return;
  if (flags->neg == 0)
  {
    while (flags->width-- > flags->precision + len && flags->width > 0)
    {
      if (flags->zero == 1)
        ft_write('0', flags);
      else
        ft_write(' ', flags);
    }
    while (flags->precision-- > len)
    {
      if (flags->zero == 1)
        ft_write('0', flags);
      else
        ft_write(' ', flags);
    }
    ft_candwrite(flags, nb, 2);
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
