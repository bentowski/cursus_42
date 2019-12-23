#include "get_next_line.h"

static void print_list(t_list *list)
{
  int x;

  x = 0;
  while (list)
  {
    printf("%d : %d\n", x, list->fd);
    list = list->next;
    x++;
  }
}


static t_list *add_fd(t_list *clist, int fd, t_list *begun)
{
  t_list *tmp;

  if(!(tmp = malloc(sizeof(t_list))))
    return (NULL);
  tmp->fd = fd;
  clist = begun->next;
  begun->next = tmp;
  if (!clist)
    tmp->next = NULL;
  else
    tmp->next = clist;
  return (begun->next);
}


int get_next_line(int fd, char **list)
{
  static t_list *clist;
  t_list *begun;
  int y;

  y = 0;
  if (!(begun = malloc(sizeof(t_list))))
    return (-1);
  if (clist)
    begun->next = clist;
  while (clist)
  {
    if (clist->fd == fd)
    {
      y = 1;
      break;
    }
    clist = clist->next;
  }
  printf("\nfd : %d\n", fd);
  if (y == 0)
    clist = add_fd(clist, fd, begun);
  print_list(clist);
  return (0);
}
