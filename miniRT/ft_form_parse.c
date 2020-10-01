#include "mlx.h"
#include <fcntl.h>
#include "minirt.h"
#include <stdio.h>

int init_sphere(char *line, int i, t_coo *coo)
{
  double tmp;

  tmp = .0;
  i = i + 2;
  printf("%s\n", "ok");
  if ((i = ft_space(line, i)) == -1)
    return (-1);
  if ((i = ft_coordonnees(coo, line, i)) == -1)
    return (-1);
  if ((i = ft_space(line, i)) == -1)
    return (-1);
  if ((i = ft_dimensions(coo, line, i, 1)) == -1)
    return (-1);
  if ((i = ft_space(line, i)) == -1)
    return (-1);
  if ((i = ft_color(coo, line, i)) == -1)
    return (-1);
  printf("sp : %lf,%lf,%lf %lf, %d, %d, %d\n", coo->x, coo->y, coo->z, coo->diameter, coo->color1, coo->color2, coo->color3);
  return (i);
}

int init_square(char *line, int i, t_coo *coo)
{
  double tmp;

  tmp = .0;
  i = i + 2;
  if ((i = ft_space(line, i)) == -1)
    return (-1);
  if ((i = ft_coordonnees(coo, line, i)) == -1)
    return (-1);
  if ((i = ft_space(line, i)) == -1)
    return (-1);
  if ((i = ft_dimensions(coo, line, i, 3)) == -1)
    return (-1);
  if ((i = ft_space(line, i)) == -1)
    return (-1);
  if ((i = ft_dimensions(coo, line, i, 1)) == -1)
    return (-1);
  if ((i = ft_space(line, i)) == -1)
    return (-1);
  if ((i = ft_color(coo, line, i)) == -1)
    return (-1);
  printf("sq : %lf,%lf,%lf %lf,%lf,%lf %lf %d, %d, %d\n", coo->x, coo->y, coo->z, coo->vx, coo->vy, coo->vz, coo->height, coo->color1, coo->color2, coo->color3);
  return (i);
}

int init_plane(char *line, int i, t_coo *coo)
{
  double tmp;

  tmp = .0;
  i = i + 2;
  if ((i = ft_space(line, i)) == -1)
    return (-1);
  if ((i = ft_coordonnees(coo, line, i)) == -1)
    return (-1);
  if ((i = ft_space(line, i)) == -1)
    return (-1);
  if ((i = ft_dimensions(coo, line, i, 2)) == -1)
    return (-1);
  if ((i = ft_space(line, i)) == -1)
    return (-1);
  if ((i = ft_color(coo, line, i)) == -1)
    return (-1);
  printf("pl : %lf,%lf,%lf %lf,%lf,%lf %d, %d, %d\n", coo->x, coo->y, coo->z, coo->vx, coo->vy, coo->vz, coo->color1, coo->color2, coo->color3);
  return (i);
}

int init_cylinder(char *line, int i, t_coo *coo)
{
  double tmp;

  tmp = .0;
  i = i + 2;
  if ((i = ft_space(line, i)) == -1)
    return (-1);
  if ((i = ft_coordonnees(coo, line, i)) == -1)
    return (-1);
  if ((i = ft_space(line, i)) == -1)
    return (-1);
  if ((i = ft_dimensions(coo, line, i, 3)) == -1)
    return (-1);
  if ((i = ft_space(line, i)) == -1)
    return (-1);
  if ((i = ft_dimensions(coo, line, i, 2)) == -1)
    return (-1);
  if ((i = ft_space(line, i)) == -1)
    return (-1);
  if ((i = ft_dimensions(coo, line, i, 1)) == -1)
    return (-1);
  if ((i = ft_space(line, i)) == -1)
    return (-1);
  if ((i = ft_color(coo, line, i)) == -1)
    return (-1);
  printf("cy : %lf,%lf,%lf %lf,%lf,%lf %lf %lf %d, %d, %d\n", coo->x, coo->y, coo->z, coo->vx, coo->vy, coo->vz, coo->diameter, coo->height, coo->color1, coo->color2, coo->color3);
  return (i);
}
