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

int ft_nblenx(unsigned int nb)
{
  int x;
  unsigned int n;

  n = nb;
  x = 1;
  while ((nb = nb / 16) > 0)
    x++;
  return (x);
}

int ft_nblend(int nb)
{
  int x;
  int n;

  n = nb;
  x = 1;
    if (n < 0)
    {
      n = -n;
      x++;
    }
    while (( n = n / 10) > 0)
      x++;
  return (x);
}

void ft_d2(int *lenght, t_flags *flags, int nb)
{
  int len;

  len = *lenght;
  if (nb == -2147483648)
    len -= 9;
  if (flags->negative == 0)
  {
    while (len-- > 0)
      (flags->zero == 1 || flags->cutter == 1) ? ft_write('0') : ft_write(' ');
    if (nb <= 2147483647 && nb != -2147483648)
      ft_putnbr_fd(nb, 1);
    else if (nb == -2147483648)
    {
      if (flags->zero == 0 && flags->negative == 0 && flags->cutter == 0)
        write(1, "-2147483648", 11);
      else
        write(1, "2147483648", 10);
    }
  }
  else
  {
    ft_putnbr_fd(nb, 1);
    while (len-- > 0)
      ft_write(' ');
  }
}

void ft_d(va_list *list_args, t_flags *flags)
{
  int lenght;
  int nb;

  if (flags->cutter == 1)
    flags->negative = 0;
  if (flags->constante == 1)
    flags->precision = va_arg(*list_args, int);
  nb = va_arg(*list_args, int);
  lenght = flags->precision - ft_nblend(nb);
  if (nb == 0 && flags->cutter == 1 && flags->precision == 0)
    return;
  if (nb < 0 && (flags->zero == 1 || flags->cutter == 1))
  {
    if (flags->cutter == 1)
      lenght++;
    ft_write('-');
    nb = -nb;
  }
  ft_d2(&lenght, flags, nb);
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

void ft_candwrite(unsigned long int nb, int opt)
{
  int temp1;
  int temp2;

  if (nb > 16)
  {
    ft_candwrite(nb / 16, opt);
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
    flags->precision -= ft_nblenx(nb);
  if (nb == 0 && flags->cutter == 1 && flags->precision == 0)
    return;
  if (flags->negative == 1 && flags->cutter == 0)
  {
    ft_candwrite(nb, 1);
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
    ft_candwrite(nb, 1);
  }
}

void ft_X(va_list *list_args, t_flags *flags)
{
  unsigned long int nb;

  if (flags->constante == 1)
    flags->precision = va_arg(*list_args, int);
  nb = va_arg(*list_args, unsigned long int);
  if (flags->precision != 0)
    flags->precision -= ft_nblenx(nb);
  if (nb == 0 && flags->cutter == 1 && flags->precision == 0)
    return;
  if (flags->negative == 1 && flags->cutter == 0)
  {
    ft_candwrite(nb, 2);
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
    ft_candwrite(nb, 2);
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
  flags->precision -= ft_nblenx(nb);

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
    ft_candwrite(x, 1);
  }
  else
  {
    write(1, "0x", 2);
    ft_candwrite(x, 1);
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
    else if (target[x] == '*')
      flags->constante = 1;
    else if (target[x] >= '1' && target[x] <= '9')
    {
      while (target[x] >= '0' && target[x] <= '9')
        flags->precision = (flags->precision * 10) + (target[x++] - 48);
      x--;
    }
  }
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

  ft_init(&flags);
  x = -1;
  va_start(list_args, line);
  while (line[++x])
  {
    if (x != 0 && line[x - 1] == '%')
    {
      if (line[x] == '%')
        ft_write(line[x]);
      (*functions[ft_disturb(x, line, allindexs, &flags)])(&list_args, &flags);
      while (flags.decalage-- > 0)
        x++;
    }
    else if (line[x] != '%')
      ft_write(line[x]);
  }
}

int main()
{
  int precision;
  int enteri;
  char greetings;

  // greetings = "test juste comme";
  greetings = 48;
  precision = 21;
  enteri = 461984561;

  // // ======== Test d ============
  printf("u 1 : |%.u|\n", enteri);
  ft_printf("u 1 : |%.u|\n\n", enteri);
  printf("u 2 : |%-u|\n", enteri);
  ft_printf("u 2 : |%-u|\n\n", enteri);
  printf("u 3 : |%*u|\n", precision, enteri);
  ft_printf("u 3 : |%*u|\n\n", precision, enteri);
  printf("u 4 : |%0u|\n", enteri);
  ft_printf("u 4 : |%0u|\n\n", enteri);
  printf("u 5 : |%-.u|\n", enteri);
  ft_printf("u 5 : |%-.u|\n\n", enteri);
  printf("u 6 : |%04u|\n", enteri);
  ft_printf("u 6 : |%04u|\n\n", enteri);
  printf("u 7 : |%.0u|\n", enteri);
  ft_printf("u 7 : |%.0u|\n\n", enteri);
  printf("u 8 : |%-.0u|\n", enteri);
  ft_printf("u 8 : |%-.0u|\n\n", enteri);
  printf("u 9 : |%-.*u|\n", precision, enteri);
  ft_printf("u 9 : |%-.*u|\n\n", precision, enteri);
  printf("u 10 : |%-*u|\n", precision, enteri);
  ft_printf("u 10 : |%-*u|\n\n", precision, enteri);
  printf("u 11 : |%0*u|\n", precision, enteri);
  ft_printf("u 11 : |%0*u|\n\n\n\n\n", precision, enteri);
  //
  // // ======== Test i ============
  // printf("i 1 : |%.i|\n", enteri);
  // ft_printf("i 1 : |%.i|\n\n", enteri);
  // printf("i 2 : |%-i|\n", enteri);
  // ft_printf("i 2 : |%-i|\n\n", enteri);
  // printf("i 3 : |%*i|\n", precision, enteri);
  // ft_printf("i 3 : |%*i|\n\n", precision, enteri);
  // printf("i 4 : |%0i|\n", enteri);
  // ft_printf("i 4 : |%0i|\n\n", enteri);
  // printf("i 5 : |%-.i|\n", enteri);
  // ft_printf("i 5 : |%-.i|\n\n", enteri);
  // printf("i 6 : |%04i|\n", enteri);
  // ft_printf("i 6 : |%04i|\n\n", enteri);
  // printf("i 7 : |%.0i|\n", enteri);
  // ft_printf("i 7 : |%.0i|\n\n", enteri);
  // printf("i 8 : |%-.0i|\n", enteri);
  // ft_printf("i 8 : |%-.0i|\n\n", enteri);
  // printf("i 9 : |%-.*i|\n", precision, enteri);
  // ft_printf("i 9 : |%-.*i|\n\n", precision, enteri);
  // printf("i 10 : |%-*i|\n", precision, enteri);
  // ft_printf("i 10 : |%-*i|\n\n", precision, enteri);
  // printf("i 11 : |%0*i|\n", precision, enteri);
  // ft_printf("i 11 : |%0*i|\n\n\n\n\n", precision, enteri);
  //
  //
  // // ============ Test x & X ===========
  // printf("x 1 : |%.x|\n", enteri);
  // ft_printf("x 1 : |%.x|\n\n", enteri);
  // printf("x 2 : |%-x|\n", enteri);
  // ft_printf("x 2 : |%-x|\n\n", enteri);
  // printf("x 3 : |%*x|\n", precision, enteri);
  // ft_printf("x 3 : |%*x|\n\n", precision, enteri);
  // printf("x 4 : |%0x|\n", enteri);
  // ft_printf("x 4 : |%0x|\n\n", enteri);
  // printf("x 5 : |%-.x|\n", enteri);
  // ft_printf("x 5 : |%-.x|\n\n", enteri);
  // printf("x 6 : |%04x|\n", enteri);
  // ft_printf("x 6 : |%04x|\n\n", enteri);
  // printf("x 7 : |%.0x|\n", enteri);
  // ft_printf("x 7 : |%.0x|\n\n", enteri);
  // printf("x 8 : |%-.0x|\n", enteri);
  // ft_printf("x 8 : |%-.0x|\n\n", enteri);
  // printf("x 9 : |%-.*x|\n", precision, enteri);
  // ft_printf("x 9 : |%-.*x|\n\n", precision, enteri);
  // printf("x 10 : |%-*x|\n", precision, enteri);
  // ft_printf("x 10 : |%-*x|\n\n", precision, enteri);
  // printf("x 11 : |%0*x|\n", precision, enteri);
  // ft_printf("x 11 : |%0*x|\n\n\n\n\n", precision, enteri);
  //
  // // =========== Test p ==========
  // printf("p 1 : |%p|\n", &enteri);
  // ft_printf("p 1 : |%.p|\n\n", &enteri);
  // printf("p 2 : |%-p|\n", &enteri);
  // ft_printf("p 2 : |%-p|\n\n", &enteri);
  // printf("p 3 : |%*p|\n", precision, &enteri);
  // ft_printf("p 3 : |%*p|\n\n", precision, &enteri);
  // printf("p 4 : |%p|\n", &enteri);
  // ft_printf("p 4 : |%p|\n\n", &enteri);
  // printf("p 5 : |%-p|\n", &enteri);
  // ft_printf("p 5 : |%-.p|\n\n", &enteri);
  // printf("p 6 : |%4p|\n", &enteri);
  // ft_printf("p 6 : |%4p|\n\n", &enteri);
  // printf("p 7 : |%p|\n", &enteri);
  // ft_printf("p 7 : |%.p|\n\n", &enteri);
  // printf("p 8 : |%-p|\n", &enteri);
  // ft_printf("p 8 : |%-.p|\n\n", &enteri);
  // printf("p 9 : |%-*p|\n", precision, &enteri);
  // ft_printf("p 9 : |%-.*p|\n\n", precision, &enteri);
  // printf("p 10 : |%-*p|\n", precision, &enteri);
  // ft_printf("p 10 : |%-*p|\n\n", precision, &enteri);
  // printf("p 11 : |%*p|\n", precision, &enteri);
  // ft_printf("p 11 : |%*p|\n\n\n\n\n", precision, &enteri);
  //
  //
  // // =========== Test s ==========
  // printf("s 1 : |%-.s|\n", greetings);
  // ft_printf("s 1 : |%-.s|\n\n", greetings);
  // printf("s 2 : |%.s|\n", greetings);
  // ft_printf("s 2 : |%.s|\n\n", greetings);
  // printf("s 3 : |%-8s|\n", greetings);
  // ft_printf("s 3 : |%-8s|\n\n", greetings);
  // printf("s 4 : |%.32s|\n", greetings);
  // ft_printf("s 4 : |%.32s|\n\n", greetings);
  // printf("s 5 : |%-s|\n", greetings);
  // ft_printf("s 5 : |%-s|\n\n", greetings);
  // printf("s 6 : |%-.s|\n", greetings);
  // ft_printf("s 6 : |%-.s|\n\n", greetings);
  // printf("s 7 : |%-.*s|\n", precision, greetings);
  // ft_printf("s 7 : |%-.*s|\n\n", precision, greetings);
  // printf("s 8 : |%*s|\n", precision, greetings);
  // ft_printf("s 8 : |%*s|\n\n", precision, greetings);
  // printf("s 9 : |%.*s|\n", precision , greetings);
  // ft_printf("s 9 : |%.*s|\n\n", precision , greetings);
  // printf("s 10 : |%-.*s|\n", precision, greetings);
  // ft_printf("s 10 : |%-.*s|\n\n", precision, greetings);
  // printf("s 11 : |%-*s|\n", precision , greetings);
  // ft_printf("s 11 : |%-*s|\n\n\n\n\n", precision , greetings);
  //
  //
  // //======== Test c ==========
  // printf("c 1 : |%-8c|\n", enteri);
  // ft_printf("c 1 : |%-8c|\n\n", enteri);
  // printf("c 2 : |%8c|\n", enteri);
  // ft_printf("c 2 : |%8c|\n\n", enteri);
  // printf("c 3 : |%c|\n", enteri);
  // ft_printf("c 3 : |%c|\n\n", enteri);
  // printf("c 4 : |%-c|\n", enteri);
  // ft_printf("c 4 : |%-c|\n\n", enteri);
  // printf("c 5 : |%-*c|\n", precision, enteri);
  // ft_printf("c 5 : |%-*c|\n\n", precision, enteri);
  // printf("c 6 : |%*c|\n", precision, enteri);
  // ft_printf("c 6 : |%*c|\n\n", precision, enteri);
  // printf("c 7 : |%-*c|\n", precision, enteri);
  // ft_printf("c 7 : |%-*c|\n\n\n\n\n", precision, enteri);



  // ======== Test d ============
  // printf("d 1 : |%.d|\n", enteri);
  // ft_printf("d 1 : |%.d|\n\n", enteri);
  // printf("d 2 : |%-d|\n", enteri);
  // ft_printf("d 2 : |%-d|\n\n", enteri);
  // printf("d 3 : |%*d|\n", precision, enteri);
  // ft_printf("d 3 : |%*d|\n\n", precision, enteri);
  // printf("d 4 : |%0d|\n", enteri);
  // ft_printf("d 4 : |%0d|\n\n", enteri);
  // printf("d 5 : |%-.d|\n", enteri);
  // ft_printf("d 5 : |%-.d|\n\n", enteri);
  // printf("d 6 : |%04d|\n", enteri);
  // ft_printf("d 6 : |%04d|\n\n", enteri);
  // printf("d 7 : |%.0d|\n", enteri);
  // ft_printf("d 7 : |%.0d|\n\n", enteri);
  // printf("d 8 : |%-.0d|\n", enteri);
  // ft_printf("d 8 : |%-.0d|\n\n", enteri);
  // printf("d 9 : |%-.*d|\n", precision, enteri);
  // ft_printf("d 9 : |%-.*d|\n\n", precision, enteri);
  // printf("d 10 : |%-*d|\n", precision, enteri);
  // ft_printf("d 10 : |%-*d|\n\n", precision, enteri);
  // printf("d 11 : |%0*d|\n", precision, enteri);
  // ft_printf("d 11 : |%0*d|\n\n\n\n\n", precision, enteri);


}
