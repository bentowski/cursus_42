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
  filename1 = "text";
  filename2 = "text2";
  fd1 = open(filename1, O_RDONLY);
  fd2 = open(filename2, O_RDONLY);
  get_next_line(fd, test);
  get_next_line(fd, test);
  get_next_line(fd, test);
  get_next_line(fd, test);
  get_next_line(fd, test);
  write(1, "end", 3);
}
