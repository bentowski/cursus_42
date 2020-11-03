#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>


int main(int argc, char **argv)
{
  int fd;
  char *line;

  printf("%s\n", "ft_parse");
  fd = open(argv[1], O_RDONLY);
  while (get_next_line(fd, &line) > 0)
  {
    free(line);
  }
  free(line);
  printf("%s\n", "sortie correcte ft_parse");
  return (1);
}
