// #include "get_next_line.h"
// #include <fcntl.h>
//
// int main()
// {
//   const char *filename1;
//   // const char *filename2;
//   // const char *filename3;
//   int fd1;
//   // int fd2;
//   // int fd3;
//   char **test;
//   char *essai;
//
//   essai = "";
//   test = &essai;
//   filename1 = "text";
//   // filename2 = "text2";
//   // filename3 = "text3";
//   fd1 = open(filename1, O_RDONLY);
//   // fd2 = open(filename2, O_RDONLY);
//   // fd3 = open(filename3, O_RDONLY);
//   while (get_next_line(fd1, test));
//   // get_next_line(fd2, test);
//   // get_next_line(fd3, test);
//   // get_next_line(fd1, test);
//   // get_next_line(fd2, test);
//   // get_next_line(fd1, test);
//   write(1, "end", 3);
//
//   // system("leaks a.out");
// }


#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "get_next_line.h"
int main(int ac, char **av)
{
    int fd;
    int i = 0;
    char *line;
    int ret;
    (void)ac;
    fd = open(av[1], O_RDONLY);
    printf("debut\n");
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        if (line)
            printf("%s\n", line);
        i++;
        free(line);
    }
    printf("%s\nFIN : %d\n", line, ret);
    close(fd);
    free(line);
    return (0);
}
