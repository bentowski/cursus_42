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
	char			*d;
	unsigned int	x;

	x = 0;
	if (!s)
		return (NULL);
	if (!f)
		return ((char *)s);
	if (!(d = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[x])
	{
		d[x] = f(x, s[x]);
		x++;
	}
	d[x] = '\0';
	return (d);
}
