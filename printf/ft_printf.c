# include "ft_printf.h"

void ft_write(char c)
{
  write(1, &c, 1);
}

int ft_nblen(int nb)
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
  lenght = flags->precision - ft_nblen(nb);
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

}

void ft_x(va_list *list_args, t_flags *flags)
{

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
  int enteri;
  int precision;
  char d;

  d = 0;
  precision = 5;
  while (d < 88)
  {
    enteri = d;
    printf("c 1 : |%-8c|\n", d);
    ft_printf("c 1 : |%-8c|\n\n", d);
    printf("c 2 : |%8c|\n", d);
    ft_printf("c 2 : |%8c|\n\n", d);
    printf("c 3 : |%c|\n", d);
    ft_printf("c 3 : |%c|\n\n", d);
    printf("c 4 : |%-c|\n", d);
    ft_printf("c 4 : |%-c|\n\n", d);
    printf("c 5 : |%-*c|\n", precision, d);
    ft_printf("c 5 : |%-*c|\n\n", precision, d);
    printf("c 6 : |%*c|\n", precision, d);
    ft_printf("c 6 : |%*c|\n\n", precision, d);
    printf("c 7 : |%-*c|\n", precision, d);
    ft_printf("c 7 : |%-*c|\n\n", precision, d);
    write(1, "\n\n\n\n", 4);
    printf("%d\n", enteri);
    d++;
  }
}


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
