/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:00:22 by bbaudry           #+#    #+#             */
/*   Updated: 2020/03/02 16:00:24 by bbaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_strjoin(char *s1, char const *s2, int *i)
{
	char	*d;
	int		len;
	int   len2;
	int		y;
	int   x;

	y = 0;
	x = 0;
	len = 0;
	len2 = 0;
	if (!s2)
		return (NULL);
	while (s1[len++]);
	while (s2[len2] && s2[len2] != '\n')
		len2++;
	len += len2 + 1;
	if (!(d = (char *)malloc(len)))
		return (NULL);
	while (s1[x])
		d[y++] = s1[x++];
	x = 0;
	while (s2[x] && s2[x] != '\n')
		d[y++] = s2[x++];
	d[y] = '\0';
	*i = x;
	free(s1);
	return (d);
}
