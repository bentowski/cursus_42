/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:53:10 by bbaudry           #+#    #+#             */
/*   Updated: 2019/10/24 11:53:12 by bbaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	x;
	int				lenght;
	char			*d;

	x = 0;
	if ((ft_strlen(s) - start) > len)
		lenght = len + 1;
	else
		lenght = (ft_strlen(s) - start) + 1;
	if (!(d = malloc(sizeof(char) * lenght)) || !s)
		return (NULL);
	while (s[x + start] && x < len)
	{
		d[x] = s[x + start];
		x++;
	}
	d[x] = "\0";
	return (d);
}
