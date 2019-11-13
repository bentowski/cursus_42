#include "get_next_line.h"
#include <fcntl.h>

int main()
{
  const char *filename;
  int fd;
  int x;
  char **test;
  char *essai;

  x = 0;
  essai = "e";
  test = &essai;
  filename = "text";
  fd = open(filename, O_RDONLY);
  while (get_next_line(fd, test))
  {
    x++;
    printf("%d\n", x);
  }
}
