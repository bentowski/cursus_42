#include "ft_printf.h"

void ft_d(va_list *list_args, t_flags *flags)
{
  int nb;

  if (flags->constantew == 1)
    flags->width = va_arg(*list_args, int);
  if (flags->constantep == 1)
    flags->precision = va_arg(*list_args, int);
  nb = va_arg(*list_args, int);
  printf("{%d, %d, %d} ", flags->width, flags->precision, nb);

}

int ft_disturb(int i, const char *target, t_flags *flags)
{
  int y;
  int x;

  x = i - 1;
  while (target[++x] && (flags->decalage = x - i) >= 0)
  {
    if (target[x] == '-')
    {
      flags->neg = 1;
    }
    else if (target[x] == '.')
    {
      flags->cutter = 1;
    }
    else if (target[x] == '0')
    {
      flags->zero = 1;
    }
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
  // void (*functions[8])(va_list *, t_flags *) = {ft_c, ft_s, ft_d, ft_x, ft_X,
  //   ft_u, ft_d, ft_p};
  // char allindexs[9] = {'c', 's', 'd', 'x', 'X', 'u', 'i', 'p', '\0'};
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
      // if (line[x] == '%')
      //   ft_write(line[x], &flags);
      // (*functions[ft_disturb(x, line, allindexs, &flags)])(&list_args, &flags);
      ft_disturb(x, line, &flags);
      ft_d(&list_args, &flags);
      while (flags.decalage-- > 0)
        x++;
    }
    // else if (line[x] != '%')
    //   ft_write(line[x], &flags);
  }
  return (flags.printed);
}

int main()
{
  int		a = -2;
	int		b = -2;
  char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		i = 8;
	int		j = -12;
  int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";



  printf(" --- Return : %d\n", printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
  ft_printf(" --- Return : %d\n", ft_printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));

}
