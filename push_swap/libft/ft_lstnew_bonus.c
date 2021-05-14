/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaudry <bbaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:50:48 by bbaudry           #+#    #+#             */
/*   Updated: 2021/05/14 11:26:30 by benjaminbaudry   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *lst;

	lst = NULL;
	if (!(lst = (t_list *)malloc(1)))
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
