# include "ft_printf.h"

void ft_write(char c, t_flags *flags)
{
  write(1, &c, 1);
  flags->printed++;
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
      flags->neg = 1;
    else if (target[x] == '.')
      flags->cutter = 1;
    else if (target[x] == '0')
      flags->zero = 1;
    else if (flags->precision == 0)
    {
      if (target[x] == '*')
        flags->constante += 1;
      else if (target[x] >= '1' && target[x] <= '9')
      {
        if (flags->cutter == 0)
          while (target[x] >= '0' && target[x] <= '9')
            flags->width = (flags->width * 10) + (target[x++] - 48);
        else
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
  flags->width = 0;
  flags->neg = 0;
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
        ft_write(line[x], &flags);
      (*functions[ft_disturb(x, line, allindexs, &flags)])(&list_args, &flags);
      while (flags.decalage-- > 0)
        x++;
    }
    else if (line[x] != '%')
      ft_write(line[x], &flags);
  }
  return (flags.printed);
}
