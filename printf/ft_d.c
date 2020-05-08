# include "ft_printf.h"

static void ft_diputnbr(t_flags *flags, int nb, int relou)
{
  if (nb == 0 && relou == 1 && flags->cutter == 1)
    flags->printed--;
  else if (nb <= 2147483647 && nb != -2147483648)
    ft_putnbr_fd(nb, 1);
  else if (nb == -2147483648)
      write(1, "2147483648", 10);
}

static void ft_digestion(t_flags *flags, int nb, int nblen, int rest)
{
  int relou;

  relou = 0;
  if (flags->precision == 0)
    relou = 1;
  // printf("[%d, %d, %d, %d, %d] ", nblen, flags->width, flags->precision, flags->cutter, flags->zero);
  if (flags->neg == 0)
  {
    while (flags->width-- > rest && flags->width > 0)
    {
      if (flags->zero == 1 && (flags->cutter == 0 || flags->precision < 0))
        ft_write('0', flags);
      else
        ft_write(' ', flags);
    }
    while (flags->precision-- > nblen)
        ft_write('0', flags);
    ft_diputnbr(flags, nb, relou);
  }
  else
  {
    if (flags->precision == 0)
      relou = 1;
    while (flags->precision-- > nblen)
      ft_write('0', flags);
    ft_diputnbr(flags, nb, relou);
    if (flags->width > rest)
      while (flags->width-- > rest && flags->width > 0)
        ft_write(' ', flags);
  }
}

void ft_di(va_list *list_args, t_flags *flags)
{
  int nb;
  int nblen;
  int rest;

  ft_flags(list_args, flags);
  nb = va_arg(*list_args, int);
  if (flags->cutter == 1 && nb == 0 && flags->width == 0 && flags->precision == 0)
    return;
  nblen = ft_nblend(nb);
  flags->printed += nblen;
  if (flags->precision < 0 || (flags->precision <= nblen && flags->cutter == 1))
    rest = nblen;
  else
    rest = flags->precision + nblen;
  if (nb == 0 && flags->precision == 0 && flags->cutter == 1)
    flags->width++;
  if (nblen == 1 && (flags->width - 1 == flags->precision) && flags->cutter == 1 && flags->precision > 1)
    flags->width++;
  // printf("{%d, %d} ", nb, nblen);
  if ((flags->neg != 1 && flags->zero != 1))
    while (flags->width-- > rest && flags->width > 0)
      ft_write(' ', flags);
  if (nb < 0)
  {
    // if ((flags->neg != 1 && flags->zero != 1) || (flags->precision == 0 && flags->cutter == 1))
    //   while (flags->width-- > rest && flags->width > 0)
    //     ft_write(' ', flags);
    ft_write('-', flags);
    flags->printed--;
    if (flags->precision > 0)
      flags->precision++;
    nb = -nb;
  }
  ft_digestion(flags, nb, nblen, rest);
}
