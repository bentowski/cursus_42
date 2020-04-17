#include "ft_printf.h"

int main()
{
  char	c = 'a';
  int		i = 8;
  int		j = -12;
  int		k = 123456789;
  int		l = 0;
  int		m = -12345678;
  char	*n = "abcdefghijklmnop";

  ft_printf(" --- Return : %d\n", ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j));
}
