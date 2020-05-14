/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 09:59:48 by bbaudry           #+#    #+#             */
/*   Updated: 2020/05/11 10:29:58 by bbaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_sgestion(t_flags *flags, int lenght, int opt)
{
	char x;

	x = ' ';
	if (opt == 1)
		x = '0';
	if (flags->cutter == 0)
		if (flags->width > lenght)
			while (flags->width-- > lenght)
				ft_write(x, flags);
	if (flags->cutter == 1)
	{
		if (flags->width >= flags->precision && flags->precision >= lenght)
			while (flags->width-- > lenght)
				ft_write(x, flags);
		else if (flags->width >= flags->precision && flags->precision < lenght)
			while (flags->width-- > flags->precision)
				ft_write(x, flags);
		else if (flags->width < flags->precision && flags->precision > lenght)
			while (flags->width-- > lenght)
				ft_write(x, flags);
	}
}

void			ft_s(va_list *list_args, t_flags *flags)
{
	char	*s;
	int		lenght;
	int		x;

	x = 0;
	ft_flags(list_args, flags);
	if ((s = va_arg(*list_args, char *)) == NULL)
		s = "(null)";
	lenght = ft_strlen(s);
	if (flags->precision < 0)
		flags->precision = lenght;
	if (flags->neg == 0)
		ft_sgestion(flags, lenght, 0);
	if (flags->cutter == 0)
		while (s[x])
			ft_write(s[x++], flags);
	else if (flags->precision >= lenght)
		flags->precision = lenght;
	while (x < flags->precision)
		ft_write(s[x++], flags);
	if (flags->neg == 1)
		ft_sgestion(flags, lenght, 0);
}

void			ft_c(va_list *list_args, t_flags *flags)
{
	ft_flags(list_args, flags);
	if (flags->precision <= 0)
		flags->precision = 1;
	if (flags->neg == 0)
		ft_sgestion(flags, 1, 0);
	ft_write(va_arg(*list_args, int), flags);
	if (flags->neg == 1)
		ft_sgestion(flags, 1, 0);
}

void 			ft_pourcent(va_list *list_args, t_flags *flags)
{
	int opt;

	opt = 0;
	if (flags->constantew == 1)
		flags->width = va_arg(*list_args, int);
	if (flags->constantep == 1)
		flags->precision = va_arg(*list_args, int);
	if (flags->zero == 1 && flags->width > 0)
		opt = 1;
	if (flags->width < 0)
	{
		flags->neg = 1;
		flags->width *= -1;
	}
	if (flags->precision <= 0)
		flags->precision = 1;
	if (flags->neg == 0)
		ft_sgestion(flags, 1, opt);
	ft_write('%', flags);
	if (flags->neg == 1)
		ft_sgestion(flags, 1, opt);
}

void	ft_write(char c, t_flags *flags)
{
	write(1, &c, 1);
	flags->printed++;
}
