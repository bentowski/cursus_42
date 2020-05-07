# include "ft_printf.h"

void ft_u(va_list *list_args, t_flags *flags)
{
  unsigned int nb;
  int len;
  int rest;

  ft_flags(list_args, flags);
  nb = va_arg(*list_args, unsigned int);
  len = ft_nblenx(nb, 10);
  // if (nb == 0 && flags->width == 0 && flags->precision == 0)
  //   return;
  if (nb == 0 && flags->cutter == 1 && flags->precision == 0 && flags->width == 1)
  {
    ft_write(' ', flags);
    return;
  }
  if (flags->precision < 0)
    flags->precision = 0;
  flags->printed += len;
  if (flags->precision < 0 || (flags->precision <= len && flags->cutter == 1))
    rest = len;
  else
    rest = flags->precision + len;
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
    if (nb == 0 && flags->cutter == 1 && flags->precision < 0)
      ft_write('0', flags);
    ft_putunbr_fd(nb, 1);
  }
  else
  {
    ft_putunbr_fd(nb, 1);
    if (nb == 0 && flags->cutter == 1 && flags->precision < 0)
      ft_write('0', flags);
    if (flags->width > rest)
      while (flags->width-- > rest && flags->width > 0)
        ft_write(' ', flags);
    while (flags->precision-- > len + 1)
      ft_write(' ', flags);
  }
}
