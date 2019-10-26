/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:18:09 by bbaudry           #+#    #+#             */
/*   Updated: 2019/10/09 14:18:30 by bbaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *psrc;
	unsigned char *pdst;

	psrc = (unsigned char *)src;
	pdst = (unsigned char *)dst;
	while (n > 0)
	{
		if (*psrc == c)
		{
			pdst++;
			return (pdst);
		}
		*pdst++ = *psrc++;
		n--;
	}
	return (0);
}
