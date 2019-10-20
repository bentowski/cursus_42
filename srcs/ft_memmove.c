/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:20:01 by bbaudry           #+#    #+#             */
/*   Updated: 2019/10/13 16:20:03 by bbaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *pdst = dst;
	const char *psrc = src;
	const char *lasts = psrc + (len-1);
	char *lastd = pdst + (len-1);
	  if (pdst < psrc)
		{
			printf("0\n");
			while (len--)
			{
				printf("%c", *lastd);
				*pdst++ = *psrc++;
			}
		}
	  else
	    {
				printf("1\n");
	      while (len--)
				{
					printf("%c", *lastd);
					*lastd-- = *lasts--;
				}
	    }
	  return dst;
}
