#include "get_next_line.h"

int main()
{
  const char *filename;
  int fd;
  char **test;
  char *essai;

  write(1, "tes\n", 4);
  essai = "";
  test = &essai;
  filename = "text.txt";
  fd = open(filename);
  get_next_line(fd, test);
  get_next_line(fd, test);
}
