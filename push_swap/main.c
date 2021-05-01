/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bentowsk <bentowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:18:42 by bentowsk          #+#    #+#             */
/*   Updated: 2021/04/29 17:29:01 by bentowski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int main(int agrc, char **argv)
{
  t_list *a;

  if (argc >= 2)
  {
    while (argv[x])
      ft_lstadd_back(*a, ft_lstnew(ft_atoi(argv[x++])));
    while (a)
    {
      printf("%d\n", a->content);
      a = a->next;
    }
  }
  write(1, "KO", 2);
  write(1, "\n", 1);
  return (-1);
}
