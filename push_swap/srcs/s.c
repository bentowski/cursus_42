/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:36:22 by benjamin          #+#    #+#             */
/*   Updated: 2021/05/14 17:54:21 by benjaminbaudry   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void ft_sa(t_list **a)
{
  t_list *ptr;
  t_list *tmp;
  t_list *tmp2;

  ptr = *a;
  printf("%s\n", "sa");
  if (ptr && ptr->next)
  {
    tmp = ptr->next;
    tmp2 = ptr->next->next;
    tmp->next = ptr;
    ptr->next = tmp2;
    *a = tmp;
  }
}

void ft_sb(t_list **b)
{
  t_list *ptr;
  t_list *tmp;
  t_list *tmp2;

  ptr = *b;
  printf("%s\n", "sb");
  if (ptr && ptr->next)
  {
    tmp = ptr->next;
    tmp2 = ptr->next->next;
    tmp->next = ptr;
    ptr->next = tmp2;
    *b = tmp;
  }
}

void ft_ss(t_list **a, t_list **b)
{
  printf("%s\n", "ss");
  ft_sa(a);
  ft_sb(b);
}
