# include "ft_printf.h"

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
    while ((n / 10) > 0)
    {
      n = n / 10;
      x++;
    }
    return (x);
}

void ft_c(va_list *list_args, t_flags *flags)
{

}

void ft_s(va_list *list_args, t_flags *flags)
{

}

void ft_printzero(int *lenght, t_flags *flags)
{
  int len;

  len = *lenght;
  if (flags->negative == 0)
  {
    while (len > 0)
    {
      if (flags->zero == 1 || flags->cutter == 1)
        write(1, "0", 1);
      else
        write(1, " ", 1);
      len--;
    }
  }
  else
  {
    while (len-- > 0)
      write(1, " ", 1);
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
    write(1, "-", 1);
    nb = -nb;
  }
  if (flags->negative == 0)
  {
    ft_printzero(&lenght, flags);
    ft_putnbr_fd(nb, 1);
  }
  else
  {
    ft_putnbr_fd(nb, 1);
    ft_printzero(&lenght, flags);
  }
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
  int countprecision;

  x = i;
  countprecision = 0;
  while (target[x])
  {
    y = 0;
    while (y < 8)
    {
      if (allindexs[y] == target[x])
      {
        return (y);
      }
      y++;
    }
    if (target[x] == '-')
    {
      flags->negative = 1;
      x++;
    }
    else if (target[x] == '.')
    {
      flags->cutter = 1;
      x++;
    }
    else if (target[x] == '0')
    {
      flags->zero = 1;
      x++;
    }
    else if (target[x] == '*')
    {
      flags->constante = 1;
      x++;
    }
    else if (target[x] >= '1' && target[x] <= '9')
    {
      while (target[x] >= '0' && target[x] <= '9')
      {
        countprecision = (countprecision * 10) + (target[x] - 48);
        flags->precision = countprecision;
        x++;
      }
    }
    else
      x++;
    flags->decalage++;
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
        write(1, "%", 1);
      (*functions[ft_disturb(x, line, allindexs, &flags)])(&list_args, &flags);
      while (flags.decalage-- > 0)
        x++;
    }
    else if (line[x] != '%')
      write(1, &line[x], 1);
  }
}

int main()
{
  int enteri;
  int precision;

  enteri = -05;
  precision = 5;
  printf("d 1 : |%.d|\n", enteri);
  ft_printf("d 1 : |%.d|\n\n", enteri);
  printf("d 2 : |%-d|\n", enteri);
  ft_printf("d 2 : |%-d|\n\n", enteri);
  printf("d 3 : |%*d|\n", precision, enteri);
  ft_printf("d 3 : |%*d|\n\n", precision, enteri);
  printf("d 4 : |%0d|\n", enteri);
  ft_printf("d 4 : |%0d|\n\n", enteri);
  printf("d 5 : |%-.d|\n", enteri);
  ft_printf("d 5 : |%-.d|\n\n", enteri);
  printf("d 6 : |%04d|\n", enteri);
  ft_printf("d 6 : |%04d|\n\n", enteri);
  printf("d 7 : |%.0d|\n", enteri);
  ft_printf("d 7 : |%.0d|\n\n", enteri);
  printf("d 8 : |%-.0d|\n", enteri);
  ft_printf("d 8 : |%-.0d|\n\n", enteri);
  printf("d 9 : |%-.*d|\n", precision, enteri);
  ft_printf("d 9 : |%-.*d|\n\n", precision, enteri);
  printf("d 10 : |%-*d|\n", precision, enteri);
  ft_printf("d 10 : |%-*d|\n\n", precision, enteri);
  printf("d 11 : |%0*d|\n", precision, enteri);
  ft_printf("d 11 : |%0*d|\n\n", precision, enteri);
}
