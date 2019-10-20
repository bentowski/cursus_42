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

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char *psrc;
	char *pdst;

	psrc = (char *)src;
	pdst = (char *)dst;
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
