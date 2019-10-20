#include <stdlib.h>

void *ft_calloc(size_t count, size_t size)
{
  void *new;
  int lenght;

  lenght = count * size;
  if (!(new = malloc(lenght))
    return NULL;
  ft_bzero(new, lenght);
  return new;
}
