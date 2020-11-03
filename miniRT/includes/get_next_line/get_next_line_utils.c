/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:00:22 by bbaudry           #+#    #+#             */
/*   Updated: 2020/03/12 23:30:56 by bbaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *s)
{
	int	x;

	x = 0;
	while (s[x] && s[x] != '\n')
	{
		x++;
	}
	return (x);
}

static char *ft_copyjoin(char *s1, char const *s2, int len, int **i)
{
	int y;
	int x;
	char *d;

	x = 0;
	y = 0;
	if (!(d = (char *)malloc(len)))
		return (NULL);
	while (s1[x])
		d[y++] = s1[x++];
	x = 0;
	while (s2[x] && s2[x] != '\n')
		d[y++] = s2[x++];
	d[y] = '\0';
	**i = x;
	return (d);
}

char	*ft_strjoin(char *s1, char const *s2, int *i)
{
	char	*d;
	int		len;
	int   len2;

	len = 0;
	len2 = 0;
	if (!s2)
		return (NULL);
	while (s1[len])
		len++;
	while (s2[len2] && s2[len2] != '\n')
		len2++;
	len += len2 + 1;
	if (!(d = ft_copyjoin(s1, s2, len, &i)))
		return (NULL);
	free(s1);
	return (d);
}
