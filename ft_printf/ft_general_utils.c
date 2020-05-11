/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 09:59:48 by bbaudry           #+#    #+#             */
/*   Updated: 2020/05/11 10:29:58 by bbaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/ft_putchar_fd.c"

int		ft_nblenx(unsigned int nb, int opt)
{
	int				x;
	unsigned int	n;

	n = nb;
	x = 1;
	while ((n = n / opt) > 0)
		x++;
	return (x);
}

int		ft_nblend(int nb)
{
	int	x;
	int	n;

	n = nb;
	x = 1;
	if (nb == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		x++;
	}
	while ((n = n / 10) > 0)
		x++;
	return (x);
}

int		ft_nbzero(t_flags *flags)
{
	if (flags->precision == 0)
		while (flags->width-- > 0)
			ft_write(' ', flags);
	else if (flags->precision < 0 && flags->width <= 1)
		ft_write('0', flags);
	if (flags->width <= 1)
		return (1);
	else
		return (0);
}

void	ft_flags(va_list *list_args, t_flags *flags)
{
	if (flags->constantew == 1)
		flags->width = va_arg(*list_args, int);
	if (flags->constantep == 1)
		flags->precision = va_arg(*list_args, int);
	if (flags->width < 0)
	{
		flags->neg = 1;
		flags->width *= -1;
	}
}

void	ft_putunbr_fd(long int n, int fd)
{
	int r;

	r = n % 10;
	if (n / 10 != 0)
	{
		n = n / 10;
		ft_putunbr_fd(n, fd);
	}
	ft_putchar_fd(r + '0', fd);
}
