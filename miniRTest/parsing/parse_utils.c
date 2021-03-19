#include "../../minirt.h"

double ft_routinedeux(double x, char *line, int **i)
{
  double tmp;
  int div;

  tmp = .0;
  div = 0;
  **i = **i + 1;
  while (line[**i] >= '0' && line[**i] <= '9')
  {
    tmp = tmp * 10 + line[**i] - 48;
    div++;
    **i = **i + 1;
  }
  while (div-- > 0)
    tmp = tmp / 10;
  x = x + tmp;
  return (x);
}

int ft_routine(double *x, char *line, int *i, int opt)
{
  int neg;

  neg = 1;
  if (line[*i] == '-')
  {
    neg = -1;
    *i = *i + 1;
  }
  while (line[*i] >= '0' && line[*i] <= '9')
  {
    *x = *x * 10 + line[*i] - 48;
    *i = *i + 1;
  }
  if (line[*i] == '.')
    *x = ft_routinedeux(*x, line, &i);
  else if (line[*i] != ',' && opt == 1)
  {
    printf("%s\n", "sortie ERREUR routine");
    return (-1);
  }
  *x = *x * neg;
  return (1);
}

int foisdeux(char *line, int *ayet, int *ryet)
{
  if (line[0] == 'A')
  {
    if (*ayet == 1)
    {
      printf("%s\n%s", "Error", "Ambiant x2");
      return (-1);
    }
    else
      *ayet = *ayet + 1;
  }
  if (line[0] == 'R')
  {
    if (*ryet == 1)
    {
      printf("%s\n%s", "Error", "Resolution x2");
      return (-1);
    }
    else
      *ryet = *ryet + 1;
  }
  return (1);
}

int ft_space(char *line, int i)
{
  while (line[i] && (line[i] < '0' || line[i] > '9') && line[i] != '-')
    if (line[i++] != ' ')
    {
      printf("%s\n", "ERROR MAP CONFIG, CHARACTER UNEXPECTED");
      return (-1);
    }
  return (i);
}

int ft_check_color_vdir(t_triade *check, int opt)
{
  int min;
  int max;

  if (opt == 1)
  {
    min = -1;
    max = 1;
  }
  if (opt == 2)
  {
    min = 0;
    max = 255;
  }
  if (check->x >= min && check->x <= max)
    if (check->y >= min && check->y <= max)
      if (check->z >= min && check->z <= max)
        return (1);
  return (-1);
}
