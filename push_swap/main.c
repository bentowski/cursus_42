/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:36:25 by benjamin          #+#    #+#             */
/*   Updated: 2021/05/20 22:40:40 by benjaminbaudry   ###   ########.fr       */
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

int ft_counting(t_list *ptr)
{
    t_list *tmp;
    int end;

    tmp = ptr;
    end = 0;
    while (tmp)
    {
        end++;
        tmp = tmp->next;
    }
    return (end);
}

int *create_tab(t_list *ptr, int *ret)
{
    int i;
    t_list *tmp;

    i = 0;
    tmp = ptr;
    while (tmp)
    {
      ret[i++] = ft_atoi(tmp->content);
      tmp = tmp->next;
    }
    return (ret);
}

int check_order(int *x, int end, int opt)
{
    int i;
    int j;

    i = -1;
    while (++i < end - 1)
    {
      j = i;
      while (++j < end)
      {
          if (x[i] == x[j])
              return (-2);
          if (opt == 1)
              if (x[i] > x[j])
                  return (0);
          if (opt == 2)
              if (x[i] < x[j])
                  return (0);
      }
    }
    return (1);
}

int check(t_list *ptr, int opt)
{
  int *x;
  int end;
  t_list *tmp;

  tmp = ptr;
  // if (!(tmp))
  //     return (1);
  // if (!(tmp->next))
  //   return (1);
  end = ft_counting(ptr);
  if (!(x = (int *)malloc(end)))
    return (-1);
  x = create_tab(tmp, x);
  return (check_order(x, end, opt));
}

int only_first_big(t_list **lst)
{
    t_list *ptr;
    int x;

    ptr = *lst;
    x = ft_atoi(ptr->content);
    while (ptr->next)
    {
        if (x < ft_atoi(ptr->next->content))
            return (0);
        ptr = ptr->next;
    }
    return (1);
}

int only_first_little(t_list **lst)
{
    t_list *ptr;
    int x;

    ptr = *lst;
    x = ft_atoi(ptr->content);
    while (ptr->next)
    {
        if (x > ft_atoi(ptr->next->content))
            return (0);
        ptr = ptr->next;
    }
    return (1);
}

int first_little(t_list **lst)
{
    t_list *ptr;
    int x;

    ptr = *lst;
    x = ft_atoi(ptr->content);
    while (ptr->next)
        ptr = ptr->next;
    if (x < ft_atoi(ptr->content))
        return (0);
    return (1);
}

void order_b(t_list **a, t_list **b)
{
    t_list *tmp;

    while (check(*b, 2) == 0)
    {
        tmp = *b;
        if (tmp)
        {
            if (only_first_little(b))
            {
                ft_rrb(b);
                ft_print(*a, *b);
            }
            if (tmp->next && ft_atoi(tmp->content) < ft_atoi(tmp->next->content))
            {
                ft_sb(b);
                ft_print(*a, *b);
                tmp = *b;
                if (tmp->next->next && ft_atoi(tmp->next->content) < ft_atoi(tmp->next->next->content))
                {
                    ft_pa(b, a);
                    ft_print(*a, *b);
                }
            }
        }
    }
}

int ft_make_order(t_list **a, t_list **b)
{
    t_list *ptr;
    t_list *tmp;

    while (check(*a, 1) == 0)
    {
        ptr = *a;
        tmp = *b;
        if (only_first_big(a))
        {
            ft_rra(a);
            ft_print(*a, *b);
        }
        else if (ptr->next && ft_atoi(ptr->content) > ft_atoi(ptr->next->content))
        {
            ft_pb(b, a);
            ft_print(*a, *b);
        }
        else
        {
            ft_sa(a);
            ft_print(*a, *b);
            if (only_first_big(a))
                ft_rra(a);
            else
                ft_pb(b, a);
            ft_print(*a, *b);
        }
        order_b(a, b);
    }
    ptr = *a;
    tmp = *b;
    while (ft_atoi(tmp->content) > ft_atoi(ptr->content))
    {
        ft_pb(b, a);
        ft_print(*a, *b);
        order_b(a, b);
        ptr = *a;
        tmp = *b;
    }
    while (tmp)
    {
        ft_pa(b, a);
        ft_print(*a, *b);
        tmp = *b;
    }
    return (1);
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
    x = argc;
    while (x-- > 1)
    {
      if (!(ptr = ft_lstnew(argv[x])))
        return (-1);
      ft_lstadd_front(&a, ptr);
    }
    ft_make_order(&a, &b);
    if (ret == -2)
      printf("%s\n", "doublon");
    else
      return (-1);
    while (a)
    {
        ptr = a->next;
        free(a);
        a = ptr;
    }
  }
  return (-1);
}
