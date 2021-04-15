/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:46:07 by bbaudry           #+#    #+#             */
/*   Updated: 2019/10/24 11:46:10 by bbaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	int		lenght;

	lenght = count * size;
	if (!(ptr = malloc(lenght)))
		return (NULL);
	ft_bzero(ptr, lenght);
	return (ptr);
}
