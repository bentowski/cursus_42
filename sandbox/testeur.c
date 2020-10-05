#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
  int x;
  struct s_list *next;

}               t_list;



void new_lst(t_list **lst, int valeur)
{
  t_list *new;

  if (!(new = (t_list *)malloc(1)))
  {
    printf("%s\n", "erreur malloc");
    return ;
  }
  new->x = valeur;
  new->next = *lst;
  *lst = new;

}

int main(int argc, char **argv)
{
  t_list *lst;

  if (argc != 2)
  {
    printf("%s\n", "argument missing");
    return (-1);
  }
  lst = NULL;
  new_lst(&lst, 2);
  new_lst(&lst, 5);
  new_lst(&lst, 9);
  new_lst(&lst, 10);
  while (lst)
  {
    printf("%d\n", lst->x);
    lst = lst->next;
  }
  return (1);
}
