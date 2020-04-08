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

int ft_nblen(int nb, int opt)
{
  int x;
  int n;

  n = nb;
  x = 1;
  if (opt == 1)
  {
    if (n < 0)
    {
      n = -n;
      x++;
    }
    while (( n = n / 10) > 0)
      x++;
  }
  if (opt == 2)
  {
    while ((nb = nb / 16) > 0)
      x++;
  }
  return (x);
}

void ft_d2(int *lenght, t_flags *flags, int nb)
{
  int len;

  len = *lenght;
  if (flags->negative == 0)
  {
    while (len-- > 0)
      (flags->zero == 1 || flags->cutter == 1) ? ft_write('0') : ft_write(' ');
    ft_putnbr_fd(nb, 1);
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
  lenght = flags->precision - ft_nblen(nb, 1);
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

void ft_candwrite(int nb)
{
  int temp1;
  int temp2;

  if (nb > 16)
  {
    ft_candwrite(nb / 16);
    temp1 = nb / 16;
    temp2 = nb - (temp1 * 16);
    temp1 = nb;
  }
  else
    temp2 = nb;
  if (temp2 > 9)
  {
    ft_write(temp2 + 87);
  }
  else
  {
    ft_write(temp2 + 48);
  }
}

void ft_x(va_list *list_args, t_flags *flags)
{
  int nb;

  if (flags->constante == 1)
    flags->precision = va_arg(*list_args, int);
  nb = va_arg(*list_args, int);
  if (flags->precision != 0)
    flags->precision -= ft_nblen(nb, 2);
  if (nb == 0 && flags->cutter == 1 && flags->precision == 0)
    return;
  if (flags->negative == 1 && flags->cutter == 0)
  {
    ft_candwrite(nb);
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
    ft_candwrite(nb);
  }
}

void ft_X(va_list *list_args, t_flags *flags)
{

}

void ft_u(va_list *list_args, t_flags *flags)
{

}

void ft_i(va_list *list_args, t_flags *flags)
{

}

void ft_p(va_list *list_args, t_flags *flags)
{

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
  void (*functions[8])(va_list *, t_flags *) = {ft_c, ft_s, ft_d, ft_x, ft_X, ft_u,
    ft_i, ft_p};
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
  char *greetings;

  greetings = "test juste comme";
  precision = 19;
  enteri = -2147483640;

  while (enteri > -2147483648)
  {
    printf("x 1 : |%.x|\n\n", enteri);
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
    // ft_printf("x 11 : |%0*x|\n\n", precision, enteri);
    enteri--;
  }
}


// =========== Test s ==========
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
// ft_printf("s 11 : |%-*s|\n\n", precision , greetings);


//======== Test c ==========
// printf("c 1 : |%-8c|\n", d);
// ft_printf("c 1 : |%-8c|\n\n", d);
// printf("c 2 : |%8c|\n", d);
// ft_printf("c 2 : |%8c|\n\n", d);
// printf("c 3 : |%c|\n", d);
// ft_printf("c 3 : |%c|\n\n", d);
// printf("c 4 : |%-c|\n", d);
// ft_printf("c 4 : |%-c|\n\n", d);
// printf("c 5 : |%-*c|\n", precision, d);
// ft_printf("c 5 : |%-*c|\n\n", precision, d);
// printf("c 6 : |%*c|\n", precision, d);
// ft_printf("c 6 : |%*c|\n\n", precision, d);
// printf("c 7 : |%-*c|\n", precision, d);
// ft_printf("c 7 : |%-*c|\n\n", precision, d);



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
// ft_printf("d 11 : |%0*d|\n\n", precision, enteri);
