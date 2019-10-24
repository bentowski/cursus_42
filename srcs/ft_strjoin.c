/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:52:13 by bbaudry           #+#    #+#             */
/*   Updated: 2019/10/24 11:52:15 by bbaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char const	*d;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(d = (char *)malloc(len) || !s1 || !s2))
		return (NULL);
	while (*s1)
		*d++ = *s1++;
	while (*s2)
		*d++ = *s2++;
	*d = '\0';
	return (d);
}
