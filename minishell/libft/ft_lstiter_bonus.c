/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:18:00 by bbaudry           #+#    #+#             */
/*   Updated: 2019/10/30 10:34:58 by bbaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *ptr;
	t_list *tmp;

	if (!lst)
		return ;
	ptr = lst;
	while (ptr)
	{
		tmp = ptr->next;
		f(ptr->content);
		ptr = tmp;
	}
	f(lst->content);
}
