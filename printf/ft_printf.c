# include "ft_printf.h"

int ft_nblen(int nb)
{
    int x;
    int n;

    n = nb;
    x = 0;
}

void ft_c(va_list *list_args, t_flags *flags)
{

}

void ft_s(va_list *list_args, t_flags *flags)
{

}

void ft_printzero(int *lenght, t_flags *flags)
{
  write(1, "ok\n", 3);
  printf("%d\n", *lenght);
  if (flags->negative == 0)
  {
    while (*lenght > 0)
    {
      if (flags->zero == 1)
        write(1, "0", 1);
      else
        write(1, " ", 1);
      *lenght--;
    }
  }
  else
  {
    while (*lenght-- > 0)
      write(1, "x", 1);
  }
}

void ft_d(va_list *list_args, t_flags *flags)
{
  int lenght;
  int nb;

  nb = va_arg(*list_args, int);
  lenght = ft_nblen(nb) - flags->precision;
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
    // else if (target[x] == "*")
    //   flags->precision = ???;
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
      while ((flags.decalage--) > 0)
        x++;
    }
    else if (line[x] != '%')
      write(1, &line[x], 1);
  }
}

int main()
{
  int x;

  x = 7;
  ft_printf("petit test ici avec %05d nombre pour voir\n", x);
}
