/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:11:35 by benjamin          #+#    #+#             */
/*   Updated: 2021/05/14 17:55:03 by benjaminbaudry   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void ft_ra(t_list **a)
{
  t_list *ptr;
  t_list *tmp;

  printf("%s\n", "ra");
  if (a)
  {
    ptr = *a;
    if (ptr->next)
    {
      while (ptr->next->next)
        ptr = ptr->next;
      tmp = ptr->next;
      ptr->next = NULL;
      tmp->next = *a;
      *a = tmp;
    }
  }
}

void ft_rb(t_list **b)
{
  t_list *ptr;
  t_list *tmp;

  printf("%s\n", "rb");
  if (b)
  {
    ptr = *b;
    if (ptr->next)
    {
      while (ptr->next->next)
        ptr = ptr->next;
      tmp = ptr->next;
      ptr->next = NULL;
      tmp->next = *b;
      *b = tmp;
    }
  }
}

void ft_rr(t_list **a, t_list **b)
{
  printf("%s\n", "rr");
  ft_ra(a);
  ft_rb(b);
}

void ft_rra(t_list **a)
{
  t_list *ptr;
  t_list *tmp;

  printf("%s\n", "rra");
  if (a)
  {
    ptr = *a;
    if (ptr->next)
    {
      tmp = ptr->next;
      while (ptr->next)
        ptr = ptr->next;
      ptr->next = *a;
      ptr = *a;
      ptr->next = NULL;
      *a = tmp;
    }
  }
}

void ft_rrb(t_list **b)
{
  t_list *ptr;
  t_list *tmp;

  printf("%s\n", "rrb");
  if (b)
  {
    ptr = *b;
    if (ptr->next)
    {
      tmp = ptr->next;
      while (ptr->next)
        ptr = ptr->next;
      ptr->next = *b;
      ptr = *b;
      ptr->next = NULL;
      *b = tmp;
    }
  }
}

void ft_rrr(t_list **a, t_list **b)
{
  printf("%s\n", "rrr");
  ft_rra(a);
  ft_rrb(b);
}
