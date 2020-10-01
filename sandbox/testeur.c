#include "../miniRT/mlx.h"
#include <fcntl.h>
#include "minirt.h"
#include <stdio.h>
#include <math.h>
#include <unistd.h>


void	ft_lstadd_front(t_coo **alst, t_coo *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}

t_coo *coo_init(t_coo **coo, int opt)
{
  t_coo *new;

  if (!(new = (t_coo *)malloc(1)))
    return (NULL);

  new->x = opt;
  new->next = *coo;
  *coo = new;

  return (*coo);
}

void ft_clear(t_coo **coo)
{
  t_coo *tmp;
  t_coo *ptr;

  ptr = *coo;
  if (!coo)
    return ;
  while (ptr)
  {
    tmp = ptr->next;
    free(ptr);
    ptr = tmp;
  }
  *coo = NULL;
}

void ft_print(t_coo **coo)
{
  t_coo *test;

  test = *coo;
  while (test)
  {
    printf("%lf\n", test->x);
    test = test->next;
  }
  // printf("%lf\n", test->x);
}

int main(int argc, char **argv)
{
  t_coo *coo;
  t_coo *ptr;

  if (argc != 2)
    return (-1);
  if (!(coo = (t_coo *)malloc(1)))
    return (-1);
  coo->x = 1;
  coo->next= NULL;
  coo_init(&coo, 2);
  coo_init(&coo, 3);
  coo_init(&coo, 4);
  ft_print(&coo);
  ft_clear(&coo);

  free(coo);
}
