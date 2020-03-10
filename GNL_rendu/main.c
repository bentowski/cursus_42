
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
        {
          printf("%d : %s\n", ret, line);
          free(line);
        }
        i++;
    }
    printf("%d : %s\n", ret, line);
    free(line);
    close(fd);
    system("leaks a.out");
    return (0);
}
