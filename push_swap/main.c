/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:36:25 by benjamin          #+#    #+#             */
/*   Updated: 2021/06/10 12:53:08 by bentowski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ps.h"

void ft_print(t_list *a, t_list *b)
{
  while (a || b)
  {
    // printf("%s\n", "DEBUT");
    if (a && b)
    {
      printf(" %s   %s\n", a->content, b->content);
      a = a->next;
      b = b->next;
    }
    else if (a && (!(b)))
    {
      printf(" %s\n", a->content);
      // printf("%s\n", "STOP");
      a = a->next;
    }
    else if (b && (!(a)))
    {
      printf("     %s\n", b->content);
      b = b->next;
    }
    // printf("%s\n", "FIN");
  }
  printf(" ------\n");
  printf(" %s   %s\n\n\n", "a", "b");
}

int mediane(t_list *lst)
{
  int ret;
  int count;
  t_list *ptr;

  ret = 0;
  count = 0;
  ptr = lst;
  while (ptr)
  {
    ret = ret + ft_atoi(ptr->content);
    count++;
    ptr = ptr->next;
  }
  return (ret / count);
}

int order(t_list **a, int opt)
{
  t_list *tmp;

  tmp = *a;
  while (tmp->next)
  {
    if (opt == 1)
      if (ft_atoi(tmp->content) > ft_atoi(tmp->next->content))
        return (0);
    if (opt == 2)
      if (ft_atoi(tmp->content) < ft_atoi(tmp->next->content))
        return (0);
    tmp = tmp->next;
  }
  return (1);
}

int bigest_one(t_list **a)
{
  t_list *stop;
  int x;

  stop = *a;
  if (ft_atoi(stop->content) <= mediane(*a))
    return (0);
  x = 1;
  while (stop->next && ft_atoi(stop->content) < ft_atoi(stop->next->content))
  {
    x++;
    stop = stop->next;
  }
  return (x);
}

int smallest_last(t_list **a)
{
  t_list *ptr;

  ptr = *a;
  while (ptr->next)
    ptr = ptr->next;
  if (ft_atoi(ptr->content) < mediane(*a))
    return (1);
  return (0);
}

int smallest_one(t_list **a)
{
  t_list *tmp;
  t_list *ptr;

  tmp = *a;
  ptr = *a;
  while (tmp->next)
  {
    tmp = tmp->next;
    if (ft_atoi(ptr->content) > ft_atoi(tmp->content))
      return (0);
  }
  return (1);
}

void b_in(t_list **a, t_list **b)
{
  t_list *tmp;

  ft_pb(a, b);
  ft_print(*a, *b);
  while (order(b, 2) == 0)
  {
    tmp = *b;
    if (tmp->next && ft_atoi(tmp->content) < ft_atoi(tmp->next->content))
    {
      ft_sb(b);
      ft_print(*a, *b);
      tmp = *b;
      if (tmp->next->next && ft_atoi(tmp->next->content) < ft_atoi(tmp->next->next->content))
      {
        ft_pa(a, b);
        ft_print(*a, *b);
      }
    }
  }
}

int make_order(t_list **a, t_list **b)
{
  t_list *tmp;
  t_list *ptr;
  int count;
  // int x;

  tmp = *a;
  while (order(a, 1) == 0 || *b)
  {
    while (order(a, 1) == 0)
    // x =0;
    // while (x++ < 5)
    {
      count = 0;
      if (smallest_last(a))
        while(smallest_last(a))
        {
          ft_ra(a);
          ft_print(*a, *b);
        }
      else if ((count = bigest_one(a)) > 0)
      {
        while (count-- > 0)
        {
          ft_rra(a);
          ft_print(*a, *b);
        }
      }
      else if (smallest_one(a))
      {
        ft_pb(a, b);
        ft_print(*a, *b);
      }
      else if (tmp->next && (ft_atoi(tmp->content) < ft_atoi(tmp->next->content)))
      {
        ft_pb(a, b);
        ft_print(*a, *b);
      }
      else
      {
        ptr = *b;
        if (ptr && ptr->next && ft_atoi(ptr->content) < ft_atoi(ptr->next->content))
          ft_ss(a, b);
        else
          ft_sa(a);
        ft_print(*a, *b);
      }
      tmp = *a;
    }
    if (*b)
    {
      ptr = *b;
      if (ft_atoi(ptr->content) >= mediane(*b))
      {
        ft_pa(a, b);
        ft_print(*a, *b);
      }
      else
      {
        ft_rrb(b);
        ft_print(*a, *b);
      }
      tmp = *a;
    }
    if (ft_atoi(tmp->content) > ft_atoi(tmp->next->content))
    {
      ft_sa(a);
      ft_print(*a, *b);
    }
  }
  return (0);
}

void ft_free(t_list *lst)
{
  t_list *ptr;

  while (lst)
  {
    ptr = lst->next;
    free(lst);
    lst = ptr;
  }
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
  ret = 0;
  if (argc >= 2)
  {
    if (!(a = (t_list *)malloc(1)))
      return (-1);
    b = NULL;
    x = argc;
    while (x-- > 1)
    {
      if (ft_atoi(argv[x]) == 0 && *argv[x] != '0')
      {
        printf("%s\n", "error");
        ft_free(a);
        return (-1);
      }
      if (!(ptr = ft_lstnew(argv[x])))
        return (-1);
      ft_lstadd_front(&a, ptr);
    }
    ptr = a;
    while (a->next->next)
      a = a->next;
    free(a->next);
    a->next = NULL;
    a = ptr;
    make_order(&a, &b);
    // ft_print(a, b);
    ft_free(a);
  }
  return (-1);
}


// ptr = a;
// while (ptr->content != NULL)
// {
//   printf("while for free : %s\n", ptr->content);
//   ptr = ptr->next;
// }
// free(ptr);
// make_order(&a, &b);
// while (a)
// {
//   printf("LA : %s\n", a->content);
//     ptr = a->next;
//     free(a);
//     a = ptr;
// }
