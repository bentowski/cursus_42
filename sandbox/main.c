#include "get_next_line.h"
#include <fcntl.h>

int main()
{
  const char *filename1;
  const char *filename2;
  const char *filename3;
  int fd1;
  int fd2;
  int fd3;
  char **test;
  char *essai;

  essai = "";
  test = &essai;
  filename1 = "text";
  filename2 = "text2";
  filename3 = "text3";
  fd1 = open(filename1, O_RDONLY);
  fd2 = open(filename2, O_RDONLY);
  fd3 = open(filename3, O_RDONLY);
  get_next_line(fd2, test);
  get_next_line(fd3, test);
  get_next_line(fd1, test);
  get_next_line(fd2, test);
  get_next_line(fd3, test);
  write(1, "end", 3);

  // system("leaks a.out");
}
