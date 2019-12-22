#include "get_next_line.h"

static void print_list(t_list *list)
{
  int x;

  x = 0;
  while (list)
  {
    printf("%d : %d\n", x, list->x);
    list = list->next;
    x++;
  }
}


static t_list *add_fd(t_list *list, int x, t_list *begun)
{
  t_list *tmp;

  if(!(tmp = malloc(sizeof(t_list))))
    return (NULL);
  tmp->x = x;
  list = begun->next;
  begun->next = tmp;
  if (!list)
    tmp->next = NULL;
  else
    tmp->next = list;
  return (begun->next);
}


int get_next_line()
{
  static t_list *list;
  t_list *begun;
  int x;

  x = 0;
  if (!(begun = malloc(sizeof(t_list))))
    return (-1);
  if (list)
    begun->next = list;
  while (list)
  {
    x++;
    list = list->next;
  }
  printf("\nx : %d\n", x);
  list = add_fd(list, x, begun);
  print_list(list);
  return (0);
}
