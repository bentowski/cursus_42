/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numeric_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 09:59:48 by bbaudry           #+#    #+#             */
/*   Updated: 2020/05/11 10:29:58 by bbaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flagsaffin(t_flags *flags, int len, int nb, int opt)
{
	int rest;

	rest = 0;
	if (nb == 0 && flags->cutter == 1 && flags->precision <= 0 && opt == 0)
		if (ft_nbzero(flags) == 1)
			return (-1);
	if (flags->opt != 0 && flags->opt != 32 && flags->opt != 3)
		flags->printed += len;
	if (flags->cutter == 1 && flags->precision <= 1 &&
			flags->precision >= 0)
		flags->zero = 0;
	if (flags->precision < 0)
	{
		if (flags->opt != 1)
			flags->precision = 0;
		if (flags->opt == 1 && (flags->zero == 0 ||
					(flags->neg == 1 && flags->width == 2)))
			flags->precision = 1;
	}
	if (flags->precision <= len)
		rest = len;
	else
		rest = flags->precision;
	return (rest);
}

void	ft_diputnbr(t_flags *flags, int nb, int len, int rest)
{
	if (flags->neg == 0)
		ft_width(flags, rest);
	while (flags->precision-- > len)
		ft_write('0', flags);
	if (nb == 0 && flags->precision == -1 && flags->cutter == 1)
		flags->printed--;
	else if (nb <= 2147483647 && nb != -2147483648)
		ft_putnbr_fd(nb, 1);
	else if (nb == -2147483648)
		write(1, "2147483648", 10);
	if (flags->neg == 1)
		ft_width(flags, rest);
}

void	ft_width(t_flags *flags, int rest)
{
	while (flags->width-- > rest && flags->width > 0)
	{
		if (flags->zero == 1 && flags->precision <= 0 && flags->neg == 0)
			ft_write('0', flags);
		else
			ft_write(' ', flags);
	}
}

void	ft_ugestion(t_flags *flags, int rest, int len, unsigned long int nb)
{
	if (flags->neg == 0)
		ft_width(flags, rest);
	while (flags->precision-- > len && flags->opt != 3)
		ft_write('0', flags);
	if (flags->opt == 2)
		ft_putunbr_fd(nb, 1);
	else if (flags->opt == 3)
	{
		write(1, "0x", 2);
		while (flags->precision-- >= len - 2)
			ft_write('0', flags);
		if (nb != 0 || (nb == 0 && flags->cutter == 0))
			ft_candwrite(flags, nb, 32);
	}
	else
		ft_candwrite(flags, nb, flags->opt);
	if (flags->neg == 1)
		ft_width(flags, rest);
}

void	ft_candwrite(t_flags *flags, unsigned long int nb, int opt)
{
	int temp1;
	int temp2;

	if (nb > 16)
	{
		ft_candwrite(flags, nb / 16, opt);
		temp1 = nb / 16;
		temp2 = nb - (temp1 * 16);
		temp1 = nb;
	}
	else
		temp2 = nb;
	if (temp2 > 9 && temp2 != 16)
		ft_write(temp2 + 55 + opt, flags);
	else if (temp2 != 16)
		ft_write(temp2 + 48, flags);
	else
	{
		ft_write('1', flags);
		ft_write('0', flags);
	}
}
