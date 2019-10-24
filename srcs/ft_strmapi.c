/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:53:04 by bbaudry           #+#    #+#             */
/*   Updated: 2019/10/24 11:53:06 by bbaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*d;
	unsigned int	x;

	if (s == NULL || f == NULL)
		return (NULL);
	if (!(d = malloc(sizeof(char) * (ft_srlen(s) + 1)));
		return (NULL);
	ft_strcpy(d, s);
	while (d[x])
	{
		d[x] = (*f)(x, d[x])
		x++;
	}
	d[x] = "\0";
	return (d);
}
