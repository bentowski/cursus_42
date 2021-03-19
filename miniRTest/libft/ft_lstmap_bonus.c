/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaudry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:48:29 by bbaudry           #+#    #+#             */
/*   Updated: 2019/10/30 10:34:12 by bbaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *ptr;
	t_list *new;

	if (!lst)
		return (NULL);
	if (!f)
		return ((t_list *)lst);
	if (!(new = ft_lstnew(f(lst->content))))
		return (NULL);
	ptr = new;
	while (lst->next)
	{
		lst = lst->next;
		if (!(new->next = ft_lstnew(f(lst->content))))
			ft_lstclear(&ptr, del);
		new = new->next;
	}
	return (ptr);
}
