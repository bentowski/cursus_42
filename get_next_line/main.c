#include "get_next_line.h"
#include <fcntl.h>

int main()
{
  const char *filename;
  int fd;
  char **test;
  char *essai;

  essai = "e";
  test = &essai;
  filename = "text";
  fd = open(filename, O_RDONLY);
  write(1, "1 ", 2);
  get_next_line(fd, test);
  write(1, "\n2 ", 3);
  get_next_line(fd, test);
  write(1, "\n3 ", 3);
  get_next_line(fd, test);
  write(1, "\n4 ", 3);
  get_next_line(fd, test);
  write(1, "\n5 ", 3);
  get_next_line(fd, test);
}
