# include "ft_printf.h"

int ft_nblenx(unsigned int nb, int opt)
{
  int x;
  unsigned int n;

  n = nb;
  x = 1;
  while ((n = n / opt) > 0)
    x++;
  return (x);
}

int ft_nblend(int nb)
{
  int x;
  int n;

  n = nb;
  x = 1;
  if (nb == -2147483648)
    return (11);
  if (n < 0)
  {
    n = -n;
    x++;
  }
  while (( n = n / 10) > 0)
    x++;
  return (x);
}

void ft_candwrite(t_flags *flags, unsigned long int nb, int opt)
{
  int temp1;
  int temp2;

  if (nb > 16)
  {
    ft_candwrite(flags, nb / 16, opt);
    temp1 = nb / 16;
    temp2 = nb - (temp1 * 16);
    temp1 = nb;
  }
  else
    temp2 = nb;
  if (temp2 > 9)
  {
    if (opt == 1)
      ft_write(temp2 + 87, flags);
    else
      ft_write(temp2 + 55, flags);
  }
  else
    ft_write(temp2 + 48, flags);
}

void ft_putunbr_fd(long int n, int fd)
{
  int r;

  r = n % 10;
  if (n / 10 != 0)
  {
    n = n / 10;
    ft_putunbr_fd(n, fd);
  }
  ft_putchar_fd(r + '0', fd);
}

void ft_flags(va_list *list_args, t_flags *flags)
{

  if (flags->constantew == 1)
  {
    flags->width = va_arg(*list_args, int);
  }
  else if (flags->constantep == 1)
    flags->precision = va_arg(*list_args, int);
  printf("{%d, %d, %d} ", flags->neg, flags->width, flags->precision);
  if (flags->cutter == 1)
    flags->zero = 1;
  if (flags->width < 0)
    flags->neg = 1;
  if (flags->width < 0)
    flags->width *= -1;
  printf("[%d, %d, %d] ", flags->neg, flags->width, flags->zero);
}
