/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:36:25 by benjamin          #+#    #+#             */
/*   Updated: 2021/05/18 11:41:43 by benjaminbaudry   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ps.h"

void ft_print(t_list *a, t_list *b)
{
  while (a || b)
  {
    if (a && b)
    {
      printf(" %s   %s\n", a->content, b->content);
      a = a->next;
      b = b->next;
    }
    else if (a && (!(b)))
    {
      printf(" %s\n", a->content);
      a = a->next;
    }
    else if (b && (!(a)))
    {
      printf("     %s\n", b->content);
      b = b->next;
    }
  }
  printf(" ------\n");
  printf(" %s   %s\n\n\n", "a", "b");
}

int check(t_list *ptr)
{
  int *x;
  int j;
  int i;
  t_list *tmp;

  tmp = ptr;
  j = 0;
  while (tmp)
  {
    j++;
    tmp = tmp->next;
  }
  if (!(x = (int *)malloc(j)))
    return (-1);
  j = 0;
  while (ptr)
  {
    x[j++] = ft_atoi(ptr->content);
    ptr = ptr->next;
  }
  i = -1;
  while (x[++i])
  {
    j = i;
    while (x[++j])
    {
      if (x[i] == x[j])
        break;
      if (x[i] > x[j])
        return (0);
    }
    if (x[j])
      return (-2);
  }
  return (1);
}

void ft_count(t_list **a, t_list **b)
{
  int x;
  int y;
  t_list *ptr;

  ptr = *a;
  x = ft_atoi(ptr->content);
  y = 0;
  while (ptr)
  {
    if (ft_atoi(ptr->content) < x)
      break;
    x = ft_atoi(ptr->content);
    y++;
    ptr = ptr->next;
  }
  while (y-- > 1)
  {
    ft_pb(b, a);
    ft_print(*a, *b);
  }
}

void ft_test(t_list **a, t_list **b)
{
  t_list *ptr;
  t_list *tmp;

  ptr = *a;
  tmp = *b;
  if (ptr && ptr->next && ft_atoi(ptr->content) > ft_atoi(ptr->next->content))
  {
    if (tmp && tmp->next && ft_atoi(tmp->content) < ft_atoi(tmp->next->content))
      ft_ss(a, b);
    else
      ft_sa(a);
    ft_print(*a, *b);
  }
  else if (tmp && tmp->next && ft_atoi(tmp->content) < ft_atoi(tmp->next->content))
  {
    ft_sb(b);
    ft_print(*a, *b);
  }
}

void ft_make_order(t_list **a, t_list **b)
{
    t_list *ptr;
    t_list *tmp;
    int x;

    ft_print(*a, *b);
    ptr = *a;
    x = 0;
    while (*a)
    {
        tmp = *a;
        while (tmp->next)
        {
            if (ft_atoi(tmp->content) > ft_atoi(tmp->next->content))
                break;
            tmp = tmp->next;
        }
        if (!(tmp->next))
            break;
        while(*a && ft_atoi(ptr->content) > x)
        {
            tmp = *a;
            while (tmp->next)
                tmp = tmp->next;
            if (tmp && ptr && ft_atoi(ptr->content) > ft_atoi(tmp->content))
                ft_rra(a);
            // else if (tmp && ptr && ft_atoi(ptr->content) < ft_atoi(tmp->content))
            //     ft_ra(a);
            else
                ft_pb(b, a);
            ft_print(*a, *b);
            x = ft_atoi(ptr->content);
            ptr = *a;
        }
        ft_test(a, b);
        ft_pb(b, a);
        ft_print(*a, *b);
    }
    ft_test(a, b);
    ptr = *b;
    while (*b)
    {
        tmp = *b;
        while (tmp->next)
        {
            if (ft_atoi(tmp->content) > ft_atoi(tmp->next->content))
                break;
            tmp = tmp->next;
        }
        if (!(tmp->next))
            break;
        while(*b && ft_atoi(ptr->content) > x)
        {
            tmp = *b;
            while (tmp->next)
                tmp = tmp->next;
            if (tmp && ptr && ft_atoi(tmp->content) > ft_atoi(ptr->content))
                ft_rrb(b);
            // else if (tmp && ptr && ft_atoi(tmp->content) > ft_atoi(ptr->content))
            //     ft_rrb(b);
            // else
                ft_pa(b, a);
            ft_print(*a, *b);
            x = ft_atoi(ptr->content);
            ptr = *b;
        }
        ft_test(a, b);
        ft_pa(b, a);
        ft_print(*a, *b);
    }
    ft_test(a, b);
}

int main(int argc, char ** argv)
{
  int x;
  int ret;
  t_list *a;
  t_list *b;
  t_list *ptr;

  x = 0;
  b = NULL;
  if (argc >= 2)
  {
    x = argc;
    while (x-- > 1)
    {
      if (!(ptr = ft_lstnew(argv[x])))
        return (-1);
      ft_lstadd_front(&a, ptr);
    }
    while ((ret = check(a)) == 0)
      ft_make_order(&a, &b);
    if (ret > 0)
      ft_print(a, b);
    else if (ret == -2)
      printf("%s\n", "doublon");
    else
      return (-1);
  }
  return (-1);
}
