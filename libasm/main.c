#include "libasm.h"

int main(int argc, char **argv)
{
  size_t len;
  size_t buffer_size;
  char *message;
  char *line;
  int fd;
  int fd2;

  if (argc >= 2)
  {
    if ((fd = open(argv[1], O_RDONLY)) <= 0)
      return (-1);
    if ((fd2 = open(argv[1], O_RDONLY)) <= 0)
      return (-1);
    if (!(line = malloc(1 * sizeof(char))))
      return (-1);
    buffer_size = 10;
    len = 23;
    message = "Hello World !";
    printf("============== ft_write =================\n");
    printf("%zd\n", write(1, message, len));
    printf("%zd\n", write(1, "\n", 1));
    printf("%zd\n", ft_write(1, message, len));
    printf("%zd\n", ft_write(1, "\n", 1));
    printf("============== ft_read =================\n");
    printf("%zd : %s\n", read(fd, line, buffer_size), line);
    printf("%zd : %s\n", ft_read(fd2, line, buffer_size), line);
    printf("%zd : %s\n", read(fd, line, buffer_size), line);
    printf("%zd : %s\n", ft_read(fd2, line, buffer_size), line);
    printf("%zd : %s\n", read(fd, line, buffer_size), line);
    printf("%zd : %s\n", ft_read(fd2, line, buffer_size), line);
    printf("%zd : %s\n", read(fd, line, buffer_size), line);
    printf("%zd : %s\n", ft_read(fd2, line, buffer_size), line);
    printf("%zd : %s\n", read(fd, line, buffer_size), line);
    printf("%zd : %s\n", ft_read(fd2, line, buffer_size), line);
    printf("%zd : %s\n", read(-1, line, buffer_size), line);
    printf("%zd : %s\n", ft_read(-1, line, buffer_size), line);
    printf("============== ft_strcpy =================\n");
    printf("%s\n", strcpy(line, message));
    printf("%s\n", ft_strcpy(line, message));
    printf("============== ft_strlen =================\n");
    printf("%zu\n", strlen(message));
    printf("%zu\n", ft_strlen(message));
    printf("============== ft_strcmp =================\n");
    printf("%d\n", strcmp(message, line));
    printf("%d\n", ft_strcmp(message, line));
    printf("%d\n", strcmp(line, message));
    printf("%d\n", ft_strcmp(line, message));
    printf("%d\n", strcmp("", message));
    printf("%d\n", ft_strcmp("", message));
    printf("%d\n", strcmp(line, ""));
    printf("%d\n", ft_strcmp(line, ""));
    printf("============== ft_strdup =================\n");
    printf("%s\n", strdup(message));
    printf("%s\n", ft_strdup(message));
  }
  return (1);
}
