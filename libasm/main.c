#include "libasm.h"

int main()
{
  size_t len;
  char *message;

  len = 23;
  message = "Hello World !";
  printf("%zd\n", write(-1, message, len));
  printf("%zd\n", write(1, "\n", 1));
  printf("%zd\n", ft_write(-1, message, len));
  printf("%zd\n", ft_write(1, "\n", 1));
  return (1);
}
