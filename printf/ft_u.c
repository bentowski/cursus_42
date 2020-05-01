# include "ft_printf.h"

void ft_u(va_list *list_args, t_flags *flags)
{
  // unsigned int nb;
  // int len;
  //
  // if (flags->cutter == 1)
  //   flags->neg = 0;
  // if (flags->constantep == 1)
  //   flags->precision = va_arg(*list_args, int);
  // nb = va_arg(*list_args, unsigned int);
  // len = ft_nblenx(nb, 10);
  // flags->precision -= len;
  // if (nb == 0 && flags->cutter == 1 && flags->precision == 0)
  //   return;
  // flags->printed += len;
  // if (flags->neg == 0)
  // {
  //   while (flags->precision-- > 2)
  //   {
  //     (flags->zero == 1 || flags->cutter == 1) ? ft_write('0', flags) : ft_write(' ', flags);
  //   }
  //   ft_putunbr_fd(nb, 1);
  // }
  // else
  // {
  //   ft_putunbr_fd(nb, 1);
  //   while (flags->precision-- > 2)
  //   {
  //     ft_write(' ', flags);
  //   }
  // }
}
