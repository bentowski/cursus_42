/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:42:25 by benjamin          #+#    #+#             */
/*   Updated: 2021/05/14 17:55:15 by benjaminbaudry   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void ft_pa(t_list **a, t_list **b)
{
  t_list *ptr;
  t_list *tmp;

  printf("%s\n", "pa");
  if (b)
  {
    ptr = *a;
    tmp = ptr->next;
    ptr->next = *b;
    *b = ptr;
    *a = tmp;
  }
}

void ft_pb(t_list **b, t_list **a)
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
