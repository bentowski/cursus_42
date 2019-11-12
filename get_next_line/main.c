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
  filename = "/dev/random";
  fd = open(filename, O_RDONLY);
  while (get_next_line(fd, test));
}
