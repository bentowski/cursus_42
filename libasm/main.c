#include "libasm.h"

int main(int argc, char **argv)
{
  size_t len;
  size_t buffer_size;
  char *message;
  char *line;
  char *test;
  int fd;
  int fd2;

  if (argc >= 2)
  {
    test = NULL;
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
    printf("== declared string ==\n");
    printf("real : %zd\n", write(1, message, len));
    printf("mine : %zd\n", ft_write(1, message, len));
    printf("== carriage return ==\n");
    printf("real : %zd\n", write(1, "\n", 1));
    printf("mine : %zd\n", ft_write(1, "\n", 1));
    printf("== negative len ==\n");
    printf("real : %zd\n", write(1, "test", -4));
    printf("mine : %zd\n", ft_write(1, "test", -4));
    printf("== negative fd ==\n");
    printf("real : %zd\n", write(-1, "test", 4));
    printf("mine : %zd\n", ft_write(-1, "test", 4));
    printf("== fd = 2 ==\n");
    printf("real : %zd\n", write(2, "test", 4));
    printf("mine : %zd\n", ft_write(2, "test", 4));
    printf("============== ft_read =================\n");
    printf("== classique read ==\n");
    printf("real : %zd : %s\n", read(fd, line, buffer_size), line);
    printf("mine : %zd : %s\n", ft_read(fd2, line, buffer_size), line);
    printf("== standard input ==\n");
    printf("real : %zd : %s\n", read(0, line, buffer_size), line);
    printf("mine : %zd : %s\n", ft_read(0, line, buffer_size), line);
    printf("== hazard fd (5) ==\n");
    printf("real : %zd : %s\n", read(5, line, buffer_size), line);
    printf("mine : %zd : %s\n", ft_read(5, line, buffer_size), line);
    printf("== no alloued line ==\n");
    printf("real : %zd : %s\n", read(fd, test, buffer_size), line);
    printf("mine : %zd : %s\n", ft_read(fd2, test, buffer_size), line);
    printf("== negative fd ==\n");
    printf("real : %zd : %s\n", read(-1, line, buffer_size), line);
    printf("mine : %zd : %s\n", ft_read(-1, line, buffer_size), line);
    printf("============== ft_strcpy =================\n");
    printf("== string declared ==\n");
    printf("real : %s\n", strcpy(line, message));
    printf("mine : %s\n", ft_strcpy(line, message));
    // printf("== NULL string input ==\n");
    // printf("real : %s\n", strcpy(test, message));
    // printf("mine : %s\n", ft_strcpy(test, message));
    // printf("== NULL string output ==\n");
    // printf("real : %s\n", strcpy("test", test));
    // printf("mine : %s\n", ft_strcpy("test", test));
    // printf("== NULL string both ==\n");
    // printf("real : %s\n", strcpy(test, test));
    // printf("mine : %s\n", ft_strcpy(test, test));
    printf("============== ft_strlen =================\n");
    printf("== declared string ==\n");
    printf("real : %zu\n", strlen(message));
    printf("mine : %zu\n", ft_strlen(message));
    printf("== string input ==\n");
    printf("real : %zu\n", strlen("essai"));
    printf("mine : %zu\n", ft_strlen("essai"));
    printf("== void string input ==\n");
    printf("real : %zu\n", strlen(""));
    printf("mine : %zu\n", ft_strlen(""));
    printf("============== ft_strcmp =================\n");
    printf("== declared string ==\n");
    printf("real : %d\n", strcmp(message, line));
    printf("mine : %d\n", ft_strcmp(message, line));
    printf("== reverse ==\n");
    printf("real : %d\n", strcmp(line, message));
    printf("mine : %d\n", ft_strcmp(line, message));
    printf("== void string first ==\n");
    printf("real : %d\n", strcmp("", message));
    printf("mine : %d\n", ft_strcmp("", message));
    printf("== void string second ==\n");
    printf("real : %d\n", strcmp(line, ""));
    printf("mine : %d\n", ft_strcmp(line, ""));
    printf("== void string both ==\n");
    printf("real : %d\n", strcmp("", ""));
    printf("mine : %d\n", ft_strcmp("", ""));
    // printf("== NULL string first ==\n");
    // printf("real : %d\n", strcmp(test, message));
    // printf("mine : %d\n", ft_strcmp(test, message));
    // printf("== NULL string second ==\n");
    // printf("real : %d\n", strcmp(line, test));
    // printf("mine : %d\n", ft_strcmp(line, test));
    // printf("== NULL string both ==\n");
    // printf("real : %d\n", strcmp(test, test));
    // printf("mine : %d\n", ft_strcmp(test, test));
    printf("== same ==\n");
    printf("real : %d\n", strcmp("essai", "essai"));
    printf("mine : %d\n", ft_strcmp("essai", "essai"));
    printf("== different ==\n");
    printf("real : %d\n", strcmp("ok", "nook"));
    printf("mine : %d\n", ft_strcmp("ok", "nook"));
    printf("============== ft_strdup =================\n");
    printf("== declared string ==\n");
    printf("real : %s\n", strdup(message));
    printf("mine : %s\n", ft_strdup(message));
    printf("== input string ==\n");
    printf("real : %s\n", strdup("ceci est un test"));
    printf("mine : %s\n", ft_strdup("ceci est un test"));
    printf("== void string ==\n");
    printf("real : %s\n", strdup(""));
    printf("mine : %s\n", ft_strdup(""));
    // printf("== NULL string ==\n");
    // printf("real : %s\n", strdup(test));
    // printf("mine : %s\n", ft_strdup(test));
  }
  return (1);
}
