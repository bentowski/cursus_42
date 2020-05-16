/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 09:59:48 by bbaudry           #+#    #+#             */
/*   Updated: 2020/05/11 10:29:58 by bbaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int		ft_constante(t_flags *flags, const char *target, int x, int opt)
{
	int	tmp;

	tmp = x;
	if (target[tmp] == '*' && opt == 1)
		flags->constantep = 1;
	else if (target[tmp] == '*' && opt == 2)
		flags->constantew = 1;
	else if (target[tmp] >= '1' && target[tmp] <= '9')
	{
		while (target[tmp] >= '0' && target[tmp] <= '9')
		{
			if (opt == 1)
				flags->precision = (flags->precision * 10) +
					(target[tmp++] - 48);
			else if (opt == 2)
				flags->width = (flags->width * 10) + (target[tmp++] - 48);
		}
		tmp--;
	}
	return (tmp);
}

int		ft_choose(int i, const char *target, char *allindexs, t_flags *flags)
{
	int	y;
	int	x;

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
		else if (target[x] == '0' && flags->neg == 0 && flags->cutter == 0)
			flags->zero = 1;
		else if (flags->cutter == 1)
			x = ft_constante(flags, target, x, 1);
		else if (flags->cutter == 0)
			x = ft_constante(flags, target, x, 2);
	}
	return (-1);
}

int		ft_dispatch(va_list *list_args, t_flags *flags, const char *line)
{
	void	(*functions[9])(va_list *, t_flags *);
	char	*allindexs;
	int		x;

	allindexs = "csdxXuip%";
	functions[0] = ft_c;
	functions[1] = ft_s;
	functions[2] = ft_di;
	functions[3] = ft_x;
	functions[4] = ft_xg;
	functions[5] = ft_u;
	functions[6] = ft_di;
	functions[7] = ft_p;
	functions[8] = ft_pourcent;
	if (line[++flags->suivi] != '%')
	{
		if ((x = ft_choose(flags->suivi, line, allindexs, flags)) < 0)
			return (0);
		(*functions[x])(list_args, flags);
	}
	else
		ft_write(line[flags->suivi], flags);
	while (flags->decalage-- > 0)
		flags->suivi++;
	return (1);
}

int		ft_printf(const char *line, ...)
{
	va_list	list_args;
	t_flags	flags;

	flags.printed = 0;
	flags.suivi = -1;
	va_start(list_args, line);
	while (line[++flags.suivi])
	{
		flags.precision = 0;
		flags.width = 0;
		flags.neg = 0;
		flags.zero = 0;
		flags.cutter = 0;
		flags.decalage = 0;
		flags.constantep = 0;
		flags.constantew = 0;
		if (line[flags.suivi] == '%')
		{
			if (!(ft_dispatch(&list_args, &flags, line)))
				return (-1);
		}
		else
			ft_write(line[flags.suivi], &flags);
	}
	return (flags.printed);
}
