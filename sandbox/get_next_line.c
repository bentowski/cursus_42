#include "get_next_line.h"

static void print_list(t_list *list)
{
  while (list)
  {
    printf("%d\n", list->fd);
    list = list->next;
  }
}


static t_list *add_fd(t_list *list, int fd)
{
  t_list *tmp;

  if(!(tmp = malloc(sizeof(t_list))))
    return (NULL);
  tmp->fd = fd;
  tmp->next = NULL;
  if (list)
    list->next = tmp;
  return (tmp);
}


int get_next_line(int fd)
{
  static t_list *list;
  int yet;

  yet = 0;
  printf("fd : %d\n", fd);
  while (list && yet != 1)
  {
    if (list->fd == fd)
    {
      yet = 1;
      break;
    }
    printf("fd2 : %d\n", list->fd);
    if (!list->next)
      break;
    list = list->next;
  }
  printf("yet : %d\n", yet);
  if (yet == 0)
    list = add_fd(list, fd);
  else
    list = list->next;
  print_list(list);
  return (0);
}
