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
#include "libft/ft_strlen.c"

static	void	ft_sgestion(t_flags *flags, int lenght, int opt)
{
	if (opt == 1 && flags->precision < lenght)
		flags->precision = 0;
	if (flags->cutter == 0)
		if (flags->width > lenght)
			while (flags->width-- > lenght)
				ft_write(' ', flags);
	if (flags->cutter == 1)
	{
		if (flags->width >= flags->precision && flags->precision >= lenght)
			while (flags->width-- > lenght)
				ft_write(' ', flags);
		else if (flags->width >= flags->precision && flags->precision < lenght)
			while (flags->width-- > flags->precision)
				ft_write(' ', flags);
		else if (flags->width < flags->precision && flags->precision > lenght)
			while (flags->width-- > lenght)
				ft_write(' ', flags);
	}
}

static	void	ft_special(t_flags *flags, int x)
{
	char	*s;
	int		lenght;

	s = "(null)";
	lenght = 6;
	if (flags->precision < 0)
		flags->precision = lenght;
	if (flags->neg == 0)
		ft_sgestion(flags, lenght, 1);
	if (flags->cutter == 0 || flags->precision >= lenght)
	{
		while (x < lenght)
			ft_write(s[x++], flags);
	}
	if (flags->neg == 1)
		ft_sgestion(flags, lenght, 1);
}

void			ft_s(va_list *list_args, t_flags *flags)
{
	char	*s;
	int		lenght;
	int		x;

	x = 0;
	ft_flags(list_args, flags);
	if ((s = va_arg(*list_args, char *)) == NULL)
	{
		ft_special(flags, x);
		return ;
	}
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
	if (flags->neg == 0)
		ft_sgestion(flags, 1, 0);
	ft_write(va_arg(*list_args, int), flags);
	if (flags->neg == 1)
		ft_sgestion(flags, 1, 0);
}
