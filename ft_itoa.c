/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:51:33 by bbaudry           #+#    #+#             */
/*   Updated: 2019/10/24 11:51:35 by bbaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_itoa(int n)
{
	int	i;

	i = 0;
	while ((n / 10) != 0)
	{
		n = n / 10;
		i++;
	}
	if (!(tab = (char *)malloc(i + 1)))
		return (NULL);
	i = 0;
	while (n != 0)
	{
		tab[i] = n % 10;
		n = n / 10;
		i++;
	}
	tab[i] = '\0';
}
