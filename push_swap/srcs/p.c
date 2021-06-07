/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:42:25 by benjamin          #+#    #+#             */
/*   Updated: 2021/06/05 22:18:57 by bentowski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void ft_pa(t_list **a, t_list **b)
{
  t_list *ptr;
  t_list *tmp;

  printf("%s\n", "pa");
  if (a)
  {
    ptr = *b;
    tmp = ptr->next;
    ptr->next = *a;
    *a = ptr;
    *b = tmp;
  }
}

void ft_pb(t_list **a, t_list **b)
{
  t_list *ptr;
  t_list *tmp;

  printf("%s\n", "pb");
  if (b)
  {
    ptr = *a;
    tmp = ptr->next;
    ptr->next = *b;
    *b = ptr;
    *a = tmp;
  }
}
