# include "ft_printf.h"

void ft_u(va_list *list_args, t_flags *flags)
{
  unsigned int nb;
  int len;

  ft_flags(list_args, flags, 0);
  nb = va_arg(*list_args, unsigned int);
  len = ft_nblenx(nb, 10);
  if (nb == 0 && flags->cutter == 1 && flags->precision == 0)
    return;
  flags->printed += len;
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
    ft_putunbr_fd(nb, 1);
  }
  else
  {
    ft_putunbr_fd(nb, 1);
    while (flags->precision-- > 2)
    {
      ft_write(' ', flags);
    }
  }
}
