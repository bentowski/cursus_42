# include "ft_printf.h"

void ft_write(char c, t_flags *flags)
{
  write(1, &c, 1);
  flags->printed++;
}

// void ft_constante(t_flags *flags, const char *target, int *x, int opt)
// {
//   char test;
//
//
//     if (target[*x] == '*' && opt == 1)
//       flags->constantep = 1;
//     else if (target[*x] == '*' && opt == 2)
//       flags->constantew = 1;
//     else if (target[*x] >= '1' && target[*x] <= '9')
//     {
//       while (target[*x] >= '0' && target[*x] <= '9')
//       {
//         write(1, "ok\n", 3);
//         if (opt == 1)
//           flags->precision = (flags->precision * 10) + (target[*x] - 48);
//         else if (opt == 2)
//           flags->width = (flags->width * 10) + (target[*x] - 48);
//         x++;
//       }
//       x--;
//     }
// }

int ft_disturb(int i, const char *target, char *allindexs, t_flags *flags)
{
  int y;
  int x;
  char test;

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
    else if (flags->cutter == 1)
    {
      if (target[x] == '*')
        flags->constantep += 1;
      else if (target[x] >= '1' && target[x] <= '9')
      {
        while (target[x] >= '0' && target[x] <= '9')
          flags->precision = (flags->precision * 10) + (target[x++] - 48);
        x--;
      }
    }
    else if (flags->cutter == 0)
    {
      if (target[x] == '*')
        flags->constantew += 1;
      else if (target[x] >= '1' && target[x] <= '9')
      {
        while (target[x] >= '0' && target[x] <= '9')
          flags->width = (flags->width * 10) + (target[x++] - 48);
        x--;
      }
    }

    // else if (flags->cutter == 1)
    // {
    //   ft_constante(flags, target, &x, 1);
    // }
    // else if (flags->cutter == 0)
    // {
    //   test = 48 + x;
    //   write(1, &test, 1);
    //   write(1, "ok\n", 3);
    //   ft_constante(flags, target, &x, 2);
    // }
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
  flags->constantep = 0;
  flags->constantew = 0;
}

int ft_printf(const char *line, ...)
{
  void (*functions[8])(va_list *, t_flags *) = {ft_c, ft_s, ft_di, ft_x, ft_X,
    ft_u, ft_di, ft_p};
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
