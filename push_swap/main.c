/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:36:25 by benjamin          #+#    #+#             */
/*   Updated: 2021/05/20 18:17:56 by bbaudry          ###   ########.fr       */
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

int rcheck(t_list *ptr)
{
  int *x;
  int j;
  int i;
  int end;
  t_list *tmp;

  tmp = ptr;
  end = 0;
  if (!(tmp))
      return (1);
  if (!(tmp->next))
    return (1);
  while (tmp)
  {
    end++;
    tmp = tmp->next;
  }
  if (!(x = (int *)malloc(end)))
    return (-1);
  j = 0;
  while (ptr)
  {
    x[j++] = ft_atoi(ptr->content);
    ptr = ptr->next;
  }
  i = -1;
  while (++i < end - 1)
  {
    j = i;
    while (++j < end)
      if (x[i] < x[j])
      {
          free(x);
          return (0);
      }
  }
  free(x);
  return (1);
}

int check(t_list *ptr)
{
  int *x;
  int j;
  int i;
  int end;
  t_list *tmp;

  tmp = ptr;
  end = 0;
  while (tmp)
  {
    end++;
    tmp = tmp->next;
  }
  if (!(x = (int *)malloc(end)))
    return (-1);
  j = 0;
  while (ptr)
  {
    x[j++] = ft_atoi(ptr->content);
    ptr = ptr->next;
  }
  i = -1;
  while (++i < end - 1)
  {
    j = i;
    while (++j < end)
    {
      if (x[i] == x[j])
        break;
      if (x[i] > x[j])
      {
          free(x);
          return (0);
      }
    }
    if (j < end)
    {
        free(x);
        return (-2);
    }
  }
  free(x);
  return (1);
}

// void ft_count(t_list **a, t_list **b)
// {
//   int x;
//   int y;
//   t_list *ptr;
//
//   ptr = *a;
//   x = ft_atoi(ptr->content);
//   y = 0;
//   while (ptr)
//   {
//     if (ft_atoi(ptr->content) < x)
//       break;
//     x = ft_atoi(ptr->content);
//     y++;
//     ptr = ptr->next;
//   }
//   while (y-- > 1)
//   {
//     ft_pb(b, a);
//     ft_print(*a, *b);
//   }
// }

// void ft_test(t_list **a, t_list **b)
// {
//   t_list *ptr;
//   t_list *tmp;
//
//   ptr = *a;
//   tmp = *b;
//   if (ptr && ptr->next && ft_atoi(ptr->content) > ft_atoi(ptr->next->content))
//   {
//     if (tmp && tmp->next && ft_atoi(tmp->content) < ft_atoi(tmp->next->content))
//       ft_ss(a, b);
//     else
//       ft_sa(a);
//     ft_print(*a, *b);
//   }
//   else if (tmp && tmp->next && ft_atoi(tmp->content) < ft_atoi(tmp->next->content))
//   {
//     ft_sb(b);
//     ft_print(*a, *b);
//   }
// }

// int only_one(t_list **lst)
// {
//     t_list *ptr;
//
//     ptr = *lst;
//     if (!(ptr->next))
//         return (1);
//     return (0);
// }
//
// int only_two(t_list **lst)
// {
//     t_list *ptr;
//
//     ptr = *lst;
//     if (!(ptr->next->next))
//         return (1);
//     return (0);
// }

// int swap_only_top(t_list **lst)
// {
//     t_list *ptr;
//     int x;
//
//     ptr = *lst;
//     if (ft_atoi(ptr->content) > ft_atoi(ptr->next->content))
//         x = ft_atoi(ptr->content);
//     ptr = ptr->next->next;
//     while (ptr)
//     {
//         if (ft_atoi(ptr->content) > x)
//             return (0);
//         ptr = ptr->next;
//     }
//     return (1);
// }
//
// int only_last_little(t_list **lst)
// {
//     t_list *ptr;
//
//     ptr = *lst;
//     while (ptr->next->next)
//     {
//         if (ft_atoi(ptr->content) > ft_atoi(ptr->next->content))
//             return (0);
//         ptr = ptr->next;
//     }
//     return (1);
// }
//
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

// void order_a(t_list **a, t_list **b)
// {
//     t_list *ptr;
//     t_list *tmp;
//
//     ptr = *a;
//     tmp = *b;
//     if (only_first_big(a))
//         ft_rra(a);
//     else if (swap_only_top(a))
//         ft_sa(a);
//     else if (only_last_little(a))
//         ft_ra(a);
//     else if (ft_atoi(ptr->content) < ft_atoi(ptr->next->content))
//     {
//         if ((!(tmp)) || ft_atoi(ptr->content) < ft_atoi(tmp->content))
//             ft_sa(a);
//         ft_print(*a, *b);
//         ft_pb(b, a);
//     }
//     else
//         ft_pb(b, a);
//     ft_print(*a, *b);
// }
//
// void order_b(t_list **a, t_list **b)
// {
//     if (only_one(b))
//         ft_pa(b, a);
//     else if (only_first_big(b))
//         ft_rrb(b);
//     else if (swap_only_top(b))
//         ft_sb(b);
//     else if (only_last_little(b))
//         ft_rb(b);
//     else
//         ft_pa(b, a);
// }

void order_b(t_list **a, t_list **b)
{
    t_list *tmp;

    while (rcheck(*b) == 0)
    {
        tmp = *b;
        if (tmp)
        {
            if (only_first_little(b) || first_little(b))
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

    while (check(*a) == 0)
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
    // while (check(*a) == 0)
    // {
    //     ptr = *a;
    //     tmp = *b;
    //     end = ptr;
    //     while (end->next)
    //         end = end->next;
    //     if (only_last_little(a))
    //         ft_ra(a);
    //     else if (ft_atoi(ptr->content) > ft_atoi(end->content))
    //         ft_rra(a);
    //     else if (ft_atoi(ptr->content) > ft_atoi(ptr->next->content))
    //     {
    //             ft_pb(b, a);
    //         if (tmp && ft_atoi(tmp->content) < ft_atoi(ptr->content))
    //             ft_sb(b);
    //     }
    //     else
    //         ft_pb(b, a);
    //     ft_print(*a, *b);
    // }
    // while (*b)
    // {
    //     ptr = *b;
    //     tmp = *a;
    //     end = ptr;
    //     if (ft_atoi(ptr->content) < ft_atoi(end->content))
    //         ft_rrb(b);
    //     else if (ptr->next && ft_atoi(ptr->content) > ft_atoi(ptr->next->content))
    //     {
    //         ft_pa(b, a);
    //         if (ft_atoi(ptr->content) > ft_atoi(tmp->content))
    //             ft_sa(a);
    //     }
    //     else if (ptr->next && ft_atoi(ptr->content) < ft_atoi(ptr->next->content))
    //         ft_sb(b);
    //     else
    //         ft_pa(b, a);
    //     ft_print(*a, *b);
    // }
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
    // while ((ret = check(a)) == 0)
    ft_make_order(&a, &b);
    if (ret == -2)
      printf("%s\n", "doublon");
    else
      return (-1);
    // while (a)
    // {
    //     ptr = a->next;
    //     free(a);
    //     a = ptr;
    // }
  }
  return (-1);
}
