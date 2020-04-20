# include "ft_printf.h"

void ft_write(char c)
{
  write(1, &c, 1);
}

void ft_c(va_list *list_args, t_flags *flags)
{
  char c;

  if (flags->constante == 1)
  flags->precision = va_arg(*list_args, int);
  c = va_arg(*list_args, int);
  if (flags->negative == 0)
  {
    while (--flags->precision > 0)
      ft_write(' ');
    ft_write(c);
  }
  else
  {
    ft_write(c);
    while (--flags->precision > 0)
      ft_write(' ');
  }
}

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
    return (12);
  if (n < 0)
  {
    n = -n;
    x++;
  }
  while (( n = n / 10) > 0)
    x++;
  return (x);
}

void ft_d2(t_flags *flags, int nb)
{
  flags->printed += flags->precision;
  if (flags->negative == 0)
  {
    while (flags->precision-- > 0)
    {
      if ((flags->zero == 1 || flags->cutter == 1))
        ft_write('0');
      else
        ft_write(' ');
    }
    if (nb <= 2147483647 && nb != -2147483648)
      ft_putnbr_fd(nb, 1);
    else if (nb == -2147483648)
    {
      if (flags->zero == 0 && flags->cutter == 0)
      {
        write(1, "-2147483648", 11);
        flags->printed += 11;
      }
      else
      {
        write(1, "2147483648", 10);
        flags->printed += 11;
      }
    }
  }
  else
  {
    if (nb <= 2147483647 && nb != -2147483648)
      ft_putnbr_fd(nb, 1);
    else if (nb == -2147483648)
    {
      if (flags->zero == 0 && flags->cutter == 0)
      {
        write(1, "-2147483648", 11);
        flags->printed += 11;
      }
      else
      {
        write(1, "2147483648", 10);
        flags->printed += 11;
      }
    }
    while (flags->precision-- > 0)
      ft_write(' ');
  }
}

void ft_d(va_list *list_args, t_flags *flags)
{
  int nb;
  int len;

  if (flags->cutter == 1)
    flags->negative = 0;
  if (flags->constante == 1)
    flags->precision = va_arg(*list_args, int);
  nb = va_arg(*list_args, int);
  len = ft_nblend(nb);
  if (flags->precision >= len)
    flags->precision -= len;
  else
    flags->precision = 0;
  flags->printed += len;
  if (nb == 0 && flags->cutter == 1 && flags->precision == 0)
    return;
  if (nb < 0 && (flags->zero == 1 || flags->cutter == 1))
  {
    // if (flags->cutter == 1)
    //   flags->precision++;
    ft_write('-');
    nb = -nb;
  }
  ft_d2(flags, nb);
}

void ft_s(va_list *list_args, t_flags *flags)
{
  char *s;
  int lenght;
  int x;

  x = 0;
  if (flags->constante == 1)
    flags->precision = va_arg(*list_args, int);
  s = va_arg(*list_args, char *);
  lenght = ft_strlen(s);
  if (lenght > flags->precision && flags->cutter == 1)
  {
    while (flags->precision-- > 0)
      ft_write(s[x++]);
  }
  else if (flags->cutter == 1)
  {
    while (s[x])
      ft_write(s[x++]);
  }
  else if (flags->negative == 0)
  {
    while (flags->precision-- > lenght)
      ft_write(' ');
    while(s[x])
      ft_write(s[x++]);
  }
  else
  {
    flags->precision -= lenght;
    while (s[x])
      ft_write(s[x++]);
    while (flags->precision-- > 0)
      ft_write(' ');
  }
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
      ft_write(temp2 + 87);
    else
      ft_write(temp2 + 55);
  }
  else
    ft_write(temp2 + 48);
}

void ft_x(va_list *list_args, t_flags *flags)
{
  unsigned long int nb;

  if (flags->constante == 1)
    flags->precision = va_arg(*list_args, int);
  nb = va_arg(*list_args, unsigned long int);
  if (flags->precision != 0)
    flags->precision -= ft_nblenx(nb, 16);
  if (nb == 0 && flags->cutter == 1 && flags->precision == 0)
    return;
  if (flags->negative == 1 && flags->cutter == 0)
  {
    ft_candwrite(flags, nb, 1);
    while (flags->precision-- > 0)
      ft_write(' ');
  }
  else
  {
    if (flags->zero ==1 || flags->cutter == 1)
      while (flags->precision-- > 0)
        ft_write('0');
    else
      while (flags->precision-- > 0)
        ft_write(' ');
    ft_candwrite(flags, nb, 1);
  }
}

void ft_X(va_list *list_args, t_flags *flags)
{
  unsigned long int nb;

  if (flags->constante == 1)
    flags->precision = va_arg(*list_args, int);
  nb = va_arg(*list_args, unsigned long int);
  if (flags->precision != 0)
    flags->precision -= ft_nblenx(nb, 16);
  if (nb == 0 && flags->cutter == 1 && flags->precision == 0)
    return;
  if (flags->negative == 1 && flags->cutter == 0)
  {
    ft_candwrite(flags, nb, 2);
    while (flags->precision-- > 0)
      ft_write(' ');
  }
  else
  {
    if (flags->zero ==1 || flags->cutter == 1)
      while (flags->precision-- > 0)
        ft_write('0');
    else
      while (flags->precision-- > 0)
        ft_write(' ');
    ft_candwrite(flags, nb, 2);
  }
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

void ft_u(va_list *list_args, t_flags *flags)
{
  unsigned int nb;

  if (flags->cutter == 1)
    flags->negative = 0;
  if (flags->constante == 1)
    flags->precision = va_arg(*list_args, int);
  nb = va_arg(*list_args, unsigned int);
  flags->precision -= ft_nblenx(nb, 10);
  if (nb == 0 && flags->cutter == 1 && flags->precision == 0)
    return;
  if (flags->negative == 0)
  {
    while (flags->precision-- > 2)
      (flags->zero == 1 || flags->cutter == 1) ? ft_write('0') : ft_write(' ');
    ft_putunbr_fd(nb, 1);
  }
  else
  {
    ft_putunbr_fd(nb, 1);
    while (flags->precision-- > 2)
      ft_write(' ');
  }
}

void ft_p(va_list *list_args, t_flags *flags)
{
  unsigned long int x;

  if (flags->constante == 1)
    flags->precision = va_arg(*list_args, int) - 14;
  else
    flags->precision -= 14;
  x = va_arg(*list_args, unsigned long int);
  if (flags->negative == 0)
  {
    while (flags->precision-- > 0)
      ft_write(' ');
    write(1, "0x", 2);
    ft_candwrite(flags, x, 1);
  }
  else
  {
    write(1, "0x", 2);
    ft_candwrite(flags, x, 1);
    while (flags->precision-- > 0)
      ft_write(' ');
  }
}

int ft_disturb(int i, const char *target, char *allindexs, t_flags *flags)
{
  int y;
  int x;

  x = i - 1;
  while (target[++x] && (flags->decalage = x - i) >= 0)
  {
    y = -1;
    while (y++ < 8)
      if (allindexs[y] == target[x])
        return (y);
    if (target[x] == '-')
      flags->negative = 1;
    else if (target[x] == '.')
      flags->cutter = 1;
    else if (target[x] == '0')
      flags->zero = 1;
    else if (flags->precision == 0)
    {
      if (target[x] == '*')
        flags->constante = 1;
      else if (target[x] >= '1' && target[x] <= '9')
      {
        while (target[x] >= '0' && target[x] <= '9')
          flags->precision = (flags->precision * 10) + (target[x++] - 48);
        x--;
      }
    }

  }
  return (-1);
}

void ft_init(t_flags *flags)
{
  flags->precision = 0;
  flags->negative = 0;
  flags->zero = 0;
  flags->cutter = 0;
  flags->decalage = 0;
  flags->constante = 0;
}

int ft_printf(const char *line, ...)
{
  void (*functions[8])(va_list *, t_flags *) = {ft_c, ft_s, ft_d, ft_x, ft_X,
    ft_u, ft_d, ft_p};
  char allindexs[9] = {'c', 's', 'd', 'x', 'X', 'u', 'i', 'p', '\0'};
  va_list list_args;
  int x;
  t_flags flags;

  x = -1;
  flags.printed = 0;
  va_start(list_args, line);
  while (line[++x])
  {
    ft_init(&flags);
    if (x != 0 && line[x - 1] == '%')
    {
      if (line[x] == '%')
      {
        ft_write(line[x]);
        flags.printed++;
      }
      (*functions[ft_disturb(x, line, allindexs, &flags)])(&list_args, &flags);
      // printf(" [%d] ", flags.printed);
      while (flags.decalage-- > 0)
        x++;
    }
    else if (line[x] != '%')
    {
      ft_write(line[x]);
      flags.printed++;
    }
  }
  return (flags.printed);
}
