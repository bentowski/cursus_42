# include "ft_printf.h"

static void ft_dputnbr(t_flags *flags, int nb)
{
  if (nb == 0 && flags->cutter == 1)
    if (flags->precision == -1 || (flags->neg == 1 && flags->precision <= 0))
  {
    flags->printed--;
    return;
  }
  if (nb <= 2147483647 && nb != -2147483648)
    ft_putnbr_fd(nb, 1);
  else if (nb == -2147483648)
  {
    if (flags->zero == 0 && flags->cutter == 0)
      write(1, "-2147483648", 11);
    else
      write(1, "2147483648", 10);
  }
}

static void ft_dgestion(t_flags *flags, int nb, int nblen)
{
  if (flags->neg == 0)
  {
    // if (nb == 0 && flags->cutter == 1)
    //   flags->width++;
    // while (flags->width-- > flags->precision + nblen && flags->width > 0)
    //   ft_write(' ', flags);
    // while (flags->precision-- > nblen && flags->precision > 0)
    // {
    //   if (flags->zero == 1)
    //     ft_write('0', flags);
    //   else
    //     ft_write(' ', flags);
    // }
    ft_dputnbr(flags, nb);
  }
  else
  {
    // write(1, "ok\n", 3);
    ft_dputnbr(flags, nb);
    // if (nb == 0 && flags->cutter == 1 && flags->precision <= 0)
    //   flags->width++;
    // if (flags->width > flags->precision + nblen)
    //   while (flags->width-- > 0)
    //     printf("%d\n", flags->width);
    // else
    //   while (flags->width-- > nblen && flags->width > 0)
    //     ft_write(' ', flags);
    // if (flags->cutter == 0)
    //   while (flags->precision-- > nblen && flags->precision > 0)
    //     ft_write(' ', flags);
  }
}

void ft_d(va_list *list_args, t_flags *flags)
{
  int nb;
  int nblen;

  ft_flags(list_args, flags);
  nb = va_arg(*list_args, int);
  if (flags->cutter == 1 && nb == 0 && flags->width == 0 && flags->precision == 0)
    return;
  nblen = ft_nblend(nb);
  flags->printed += nblen;
  if (nb < 0 && flags->zero == 1)
  {
    ft_write('-', flags);
    flags->printed--;
    if (flags->zero == 1 && flags->neg == 0 && flags->cutter == 1)
      flags->precision++;
    nb = -nb;
  }
  ft_dgestion(flags, nb, nblen);
}
