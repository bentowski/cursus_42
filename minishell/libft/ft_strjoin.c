/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 10:27:33 by bbaudry           #+#    #+#             */
/*   Updated: 2019/10/30 10:27:38 by bbaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	int		len;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(d = (char *)malloc(len)))
		return (NULL);
	while (*s1)
	{
		d[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		d[i] = *s2++;
		i++;
	}
	d[i] = '\0';
	return (d);
}
