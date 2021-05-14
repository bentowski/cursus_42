/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:44:48 by benjamin          #+#    #+#             */
/*   Updated: 2021/05/14 17:07:14 by benjaminbaudry   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
  void *content;
  struct s_list *next;
}             t_list;

void	ft_lstadd_front(t_list **alst, t_list *new);
t_list	*ft_lstnew(void *content);
int	ft_atoi(const char *str);
void ft_sa(t_list **a);
void ft_sb(t_list **b);
void ft_ss(t_list **a, t_list **b);
void ft_pa(t_list **a, t_list **b);
void ft_pb(t_list **b, t_list **a);
void ft_ra(t_list **a);
void ft_rb(t_list **b);
void ft_rr(t_list **a, t_list **b);
void ft_rra(t_list **a);
void ft_rrb(t_list **b);
void ft_rrr(t_list **a, t_list **b);

#endif
