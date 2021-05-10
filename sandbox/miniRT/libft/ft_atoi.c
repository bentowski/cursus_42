/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:35:43 by bbaudry           #+#    #+#             */
/*   Updated: 2019/10/08 14:35:46 by bbaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int p;
	int t;

	p = 1;
	t = 0;
	while (*str == '\t' || *str == '\n' || *str == '\r' || *str == '\v' ||
		*str == '\f' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			p = p * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		t = t * 10 + (*str - 48);
		str++;
	}
	return (t * p);
}
