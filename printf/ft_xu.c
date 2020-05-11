# include "ft_printf.h"

static void ft_ugestion(t_flags *flags, int rest, int len, unsigned long int nb, int opt)
{
  if (flags->neg == 0)
  {
    while (flags->width-- > rest && flags->width > 0)
    {
      if (flags->zero == 1 && flags->precision <= 0)
        ft_write('0', flags);
      else
        ft_write(' ', flags);
    }
  }
  while (flags->precision-- > len)
    ft_write('0', flags);
  if (opt == 0)
    ft_putunbr_fd(nb, 1);
  else if (opt == 1)
    ft_candwrite(flags, nb, 1);
  else if (opt == 2)
    ft_candwrite(flags, nb, 2);
  if (flags->neg == 1)
  {
    if (nb == 0 && flags->cutter == 1 && flags->precision < -1)
      ft_write('0', flags);
    while (flags->width-- > rest && flags->width > 0)
      ft_write(' ', flags);
  }
}



void ft_u(va_list *list_args, t_flags *flags)
{
  unsigned long int nb;
  int len;
  int rest;

  ft_flags(list_args, flags);
  nb = va_arg(*list_args, unsigned long int);
  len = ft_nblenx(nb, 10);
  if (nb == 0 && flags->cutter == 1 && flags->precision <= 0)
    if (ft_nbzero(flags) == 1)
      return;
  flags->printed += len;
  if (flags->cutter == 1 && flags->precision <= 1 && flags->precision >= 0)
    flags->zero = 0;
  if (flags->precision < 0)
    flags->precision = 0;
  if (flags->precision <= len)
    rest = len;
  else
    rest = flags->precision;
  ft_ugestion(flags, rest, len, nb, 0);
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
    if (ft_nbzero(flags) == 1)
      return;
  if (flags->cutter == 1 && flags->precision <= 1 && flags->precision >= 0)
    flags->zero = 0;
  if (flags->precision < 0)
    flags->precision = 0;
  if (flags->precision < 0 || (flags->precision <= len))
    rest = len;
  else
    rest = flags->precision;
  ft_ugestion(flags, rest, len, nb, 1);
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
    if (ft_nbzero(flags) == 1)
      return;
  if (flags->cutter == 1 && flags->precision <= 1 && flags->precision >= 0)
    flags->zero = 0;
  if (flags->precision < 0)
    flags->precision = 0;
  if (flags->precision < 0 || (flags->precision <= len))
    rest = len;
  else
    rest = flags->precision;
  ft_ugestion(flags, rest, len, nb, 2);
}
