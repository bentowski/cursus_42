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
  essai = "";
  test = &essai;
  filename = "text";
  fd = open(filename, O_RDONLY);
  while (get_next_line(fd, test) != 0)
  {
    write(1, "\n", 1);
  }
  write(1, "end", 3);
}
