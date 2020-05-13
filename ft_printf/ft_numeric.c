/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numeric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 09:59:48 by bbaudry           #+#    #+#             */
/*   Updated: 2020/05/11 10:29:58 by bbaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_di(va_list *list_args, t_flags *flags)
{
	int	nb;
	int	len;
	int	rest;

	rest = 0;
	ft_flags(list_args, flags);
	flags->opt = 1;
	len = ft_nblend(nb = va_arg(*list_args, int));
	if ((rest = ft_flagsaffin(flags, rest, len, nb)) < 0)
		return ;
	if (nb < 0)
	{
		if ((flags->precision > len || flags->precision + 1 == flags->width))
			rest++;
		if (flags->precision >= len)
			flags->width--;
		if (flags->neg == 0 && (flags->zero == 0 || flags->precision > 0))
			ft_width(flags, rest);
		ft_write('-', flags);
		flags->printed--;
		if (flags->precision > 0)
			flags->precision++;
		nb = -nb;
	}
	ft_diputnbr(flags, nb, len, rest);
}

void	ft_u(va_list *list_args, t_flags *flags)
{
	unsigned long int	nb;
	int					len;
	int					rest;

	rest = 0;
	ft_flags(list_args, flags);
	flags->opt = 2;
	nb = va_arg(*list_args, unsigned long int);
	len = ft_nblenx(nb, 10);
	if ((rest = ft_flagsaffin(flags, rest, len, nb)) < 0)
		return ;
	ft_ugestion(flags, rest, len, nb);
}

void	ft_x(va_list *list_args, t_flags *flags)
{
	unsigned long int	nb;
	int					len;
	int					rest;

	rest = 0;
	ft_flags(list_args, flags);
	flags->opt = 32;
	nb = va_arg(*list_args, unsigned long int);
	len = ft_nblenx(nb, 16);
	if ((rest = ft_flagsaffin(flags, rest, len, nb)) < 0)
		return ;
	ft_ugestion(flags, rest, len, nb);
}

void	ft_xg(va_list *list_args, t_flags *flags)
{
	unsigned long int	nb;
	int					len;
	int					rest;

	rest = 0;
	ft_flags(list_args, flags);
	flags->opt = 0;
	nb = va_arg(*list_args, unsigned long int);
	len = ft_nblenx(nb, 16);
	if ((rest = ft_flagsaffin(flags, rest, len, nb)) < 0)
		return ;
	ft_ugestion(flags, rest, len, nb);
}

void	ft_p(va_list *list_args, t_flags *flags)
{
	unsigned long int	nb;
	int					len;
	int					rest;

	rest = 0;
	ft_flags(list_args, flags);
	flags->opt = 3;
	nb = va_arg(*list_args, unsigned long int);
	len = 12;
	if ((rest = ft_flagsaffin(flags, rest, len, nb)) < 0)
		return ;
	if (nb == 0)
	{
		rest += 4;
		flags->printed += 5;
	}
	else
	{
		rest += 2;
		flags->printed += 2;
	}
	ft_ugestion(flags, rest, len, nb);
}
