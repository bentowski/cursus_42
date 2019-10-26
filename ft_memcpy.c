/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:20:00 by bbaudry           #+#    #+#             */
/*   Updated: 2019/10/08 16:20:05 by bbaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *psrc;
	char *pdst;

	psrc = (char *)src;
	pdst = (char *)dst;
	if (!src && !dst)
		return (NULL);
	while (n > 0)
	{
		pdst[n - 1] = psrc[n - 1];
		n--;
	}
	return (dst);
}
