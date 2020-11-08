// #include "mlx.h"
#include "minirt.h"


int main(int argc, char **argv)
{
  int win_width;
  int win_height;

  if (argc != 2)
    return (-1);
  win_width = 0;
  win_height = 0;
  ft_parse(argv[1], &win_width, &win_height);
  system("leaks a.out");
}
