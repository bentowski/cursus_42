# include "ft_printf.h"

void ft_c(va_list *list_args, t_flags *flags)
{
  char c;

  ft_flags(list_args, flags);
  c = va_arg(*list_args, int);
  if (flags->neg == 0)
  {
    while (--flags->precision > 0)
      ft_write(' ', flags);
    ft_write(c, flags);
  }
  else
  {
    ft_write(c, flags);
    while (--flags->precision > 0)
      ft_write(' ', flags);
  }
}

void ft_s(va_list *list_args, t_flags *flags)
{
  char *s;
  int lenght;
  int x;

  x = 0;
  ft_flags(list_args, flags);
  s = va_arg(*list_args, char *);
  lenght = ft_strlen(s);
  if (flags->neg == 1)
  {
    if (flags->cutter == 0)
    {
      if (flags->width > lenght)
      {
        while (s[x])
          ft_write(s[x++], flags);
        while (flags->width-- > lenght)
          ft_write(' ', flags);
      }
      else
      {
        while (s[x])
          ft_write(s[x++], flags);
      }
    }
    else
    {
      if (flags->width > flags->precision && flags->precision > lenght)
      {
        while (x < lenght - 1)
          ft_write(s[x++], flags);
        while (flags->width-- > lenght)
          ft_write(' ', flags);
      }
      else if (flags->width > flags->precision && flags->precision == lenght)
      {
        while (x < lenght - 1)
          ft_write(s[x++], flags);
        while (flags->width-- > lenght)
          ft_write(' ', flags);
      }
      else if (flags->width > flags->precision && flags->precision < lenght)
      {
        while (x < flags->precision - 1)
          ft_write(s[x++], flags);
        while (flags->width-- > flags->precision)
          ft_write(' ', flags);
      }
      else if (flags->width == flags->precision && flags->precision > lenght)
      {
        while (x < lenght - 1)
          ft_write(s[x++], flags);
        while (flags->width-- > lenght)
          ft_write(' ', flags);
      }
      else if (flags->width == flags->precision && flags->precision < lenght)
      {
        while (x < flags->precision - 1)
          ft_write(s[x++], flags);
        while (flags->width-- > flags->precision)
          ft_write(' ', flags);
      }
      else if (flags->width < flags->precision && flags->precision == lenght)
      {
        while (x < flags->precision - 1)
          ft_write(s[x++], flags);
        while (flags->width-- > flags->precision)
          ft_write(' ', flags);
      }
      else if (flags->width < flags->precision && flags->precision > lenght)
      {
        while (x < lenght - 1)
          ft_write(s[x++], flags);
        while (flags->width-- > flags->precision)
          ft_write(' ', flags);
      }
      else if (flags->width < flags->precision && flags->precision < lenght)
      {
        while (x < flags->precision - 1)
          ft_write(s[x++], flags);
        while (flags->width-- > flags->precision)
          ft_write(' ', flags);
      }
    }
  }
  else
  {
    if (flags->cutter == 0)
    {
      if (flags->width > lenght)
      {
        while (flags->width-- > lenght)
          ft_write(' ', flags);
        while (s[x])
          ft_write(s[x++], flags);
      }
      else
      {
        while (s[x])
          ft_write(s[x++], flags);
      }
    }
    else
    {
      if (flags->width > flags->precision && flags->precision > lenght)
      {
        while (flags->width-- > lenght)
          ft_write(' ', flags);
        while (lenght-- > 0)
          ft_write(s[x++], flags);
      }
      else if (flags->width > flags->precision && flags->precision == lenght)
      {
        while (flags->width-- > lenght)
          ft_write(' ', flags);
        while (lenght-- > 0)
          ft_write(s[x++], flags);
      }
      else if (flags->width > flags->precision && flags->precision < lenght)
      {
        while (flags->width-- > flags->precision)
          ft_write(' ', flags);
        while (flags->precision-- > 0)
          ft_write(s[x++], flags);
      }
      else if (flags->width == flags->precision && flags->precision > lenght)
      {
        while (flags->width-- > lenght)
          ft_write(' ', flags);
        while (lenght-- > 0)
          ft_write(s[x++], flags);
      }
      else if (flags->width == flags->precision && flags->precision < lenght)
      {
        while (flags->width-- > flags->precision)
          ft_write(' ', flags);
        while (flags->precision-- > 0)
          ft_write(s[x++], flags);
      }
      else if (flags->width < flags->precision && flags->precision == lenght)
      {
        while (flags->width-- > flags->precision)
          ft_write(' ', flags);
        while (flags->precision-- > 0)
          ft_write(s[x++], flags);
      }
      else if (flags->width < flags->precision && flags->precision > lenght)
      {
        while (flags->width-- > flags->precision)
          ft_write(' ', flags);
        while (lenght-- > 0)
          ft_write(s[x++], flags);
      }
      else if (flags->width < flags->precision && flags->precision < lenght)
      {
        while (flags->width-- > flags->precision)
          ft_write(' ', flags);
        while (flags->precision-- > 0)
          ft_write(s[x++], flags);
      }
    }
  }
}
