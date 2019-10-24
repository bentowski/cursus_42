/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:17:26 by bbaudry           #+#    #+#             */
/*   Updated: 2019/10/24 11:17:44 by bbaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*pdst;
	const char	*psrc;
	int			dstlen;
	int			x;

	x = 0;
	pdst = (char *)dst;
	psrc = (char *)src;
	dstlen = ft_strlen(dst);
	while ((dstlen + x) < dstsize)
	{
		pdst[x + dstlen] = psrc[x];
		x++;
	}
	pdst[x + dstlen] = '\0';
	return (dstlen + x);
}
