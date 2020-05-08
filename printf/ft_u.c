# include "ft_printf.h"

void ft_u(va_list *list_args, t_flags *flags)
{
  unsigned int nb;
  int len;
  int rest;

  ft_flags(list_args, flags);
  nb = va_arg(*list_args, unsigned int);
  len = ft_nblenx(nb, 10);
  // printf("{%d, %d, %d, %d, %d} ", flags->neg, flags->width, flags->precision, flags->cutter, flags->zero);
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
  flags->printed += len;
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
    ft_putunbr_fd(nb, 1);
  }
  else
  {
    while (flags->precision-- > len)
      ft_write('0', flags);
    ft_putunbr_fd(nb, 1);
    if (nb == 0 && flags->cutter == 1 && flags->precision < -1)
      ft_write('0', flags);
    if (flags->width > rest)
      while (flags->width-- > rest && flags->width > 0)
        ft_write(' ', flags);
  }
}
