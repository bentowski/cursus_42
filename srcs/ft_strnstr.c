/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:31:41 by bbaudry           #+#    #+#             */
/*   Updated: 2019/10/24 11:31:44 by bbaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int x;
	int y;

	y = 0;
	if (*needle == '\0')
		return (char *)haystack;
	while (haystack[y] && len > 0)
	{
		x = 0;
		while (haystack[y + x] == needle[x])
		{
			x++;
			if (needle[x] == '\0')
				return (char *)haystack + y;
		}
		y++;
	}
	return (0);
}
