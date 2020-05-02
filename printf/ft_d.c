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

static void ft_dgestion(t_flags *flags, int nb, int nblen, int rest)
{
  if (nb == 0 && flags->precision == 0 && flags->cutter == 1)
  {
    flags->width++;
    flags->zero = 0;
  }
  if (flags->neg == 0)
  {
    while (flags->width-- > flags->precision + nblen && flags->width > 0)
    {
      if (flags->zero == 1)
        ft_write('0', flags);
      else
        ft_write(' ', flags);
    }
    while (flags->precision-- > nblen)
    {
      if (flags->zero == 1)
        ft_write('0', flags);
      else
        ft_write(' ', flags);
    }
    ft_dputnbr(flags, nb);
  }
  else
  {
    ft_dputnbr(flags, nb);
    if (nb == 0 && flags->cutter == 1 && flags->precision < 0)
      ft_write('0', flags);
    if (flags->width > rest)
      while (flags->width-- > rest && flags->width > 0)
        ft_write(' ', flags);
    if (flags->cutter == 0)
      while (flags->precision-- > nblen + 1)
        ft_write(' ', flags);
  }
}

void ft_d(va_list *list_args, t_flags *flags)
{
  int nb;
  int nblen;
  int rest;

  ft_flags(list_args, flags, 1);
  nb = va_arg(*list_args, int);
  if (flags->cutter == 1 && nb == 0 && flags->width == 0 && flags->precision == 0)
    return;
  nblen = ft_nblend(nb);
  // printf("{%d} ", nblen);
  flags->printed += nblen;
  if (nb < 0 && flags->zero == 1)
  {
    ft_write('-', flags);
    flags->printed--;
    if (flags->zero == 1 && flags->neg == 0 && flags->cutter == 1)
      flags->precision++;
    nb = -nb;
  }
  if (flags->precision < 0 || (flags->precision <= nblen && flags->cutter == 1))
    rest = nblen;
  else
    rest = flags->precision + nblen;
  ft_dgestion(flags, nb, nblen, rest);
}
