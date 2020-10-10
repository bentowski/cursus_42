#include "mlx.h"
#include <fcntl.h>
#include "minirt.h"
#include <stdio.h>

int init_sphere(char *line, int i, t_list ***obj)
{
  t_list *new;
  double tmp;

  if (!(new = (t_list *)malloc(1)))
    return (-1);
  new_init(new);
  tmp = .0;
  i= i + 2;
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s : %d\n", "sortie1", i);
    free(new);
    return (-1);
  }
  if ((i = ft_coordonnees(new, line, i)) == -1)
  {
    printf("%s : %d\n", "sortie2", i);
    free(new);
    return (-1);
  }
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s : %d\n", "sortie3", i);
    free(new);
    return (-1);
  }
  if ((i = ft_dimensions(new, line, i, 1)) == -1)
  {
    printf("%s : %d\n", "sortie4", i);
    free(new);
    return (-1);
  }
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s : %d\n", "sortie5", i);
    free(new);
    return (-1);
  }
  if ((i = ft_color(new, line, i)) == -1)
  {
    printf("%s : %d\n", "sortie6", i);
    free(new);
    return (-1);
  }
  // printf("%s\n", "sortie ok");
  // if (!(*obj = (t_list *)malloc(1)))
  //   return (-1);
  // new->next = **obj; //en activant cette ligne, erreurs malloc
  // **obj = new; // oui oui celle-ci aussi
  printf("sp : %lf,%lf,%lf %lf, %d, %d, %d\n", new->x, new->y, new->z, new->diameter, new->color1, new->color2, new->color3);
  free(new);
  return (i);
}

// int init_square(char *line, int i, t_list **obj)
// {
//   t_list *new;
//   double tmp;
//
//   if (!(new = (t_list *)malloc(1)))
//     return (-1);
//   tmp = .0;
//   i = i + 2;
//   if ((i = ft_space(line, i)) == -1)
//     return (-1);
//   if ((i = ft_coordonnees(new, line, i)) == -1)
//     return (-1);
//   if ((i = ft_space(line, i)) == -1)
//     return (-1);
//   if ((i = ft_dimensions(new, line, i, 3)) == -1)
//     return (-1);
//   if ((i = ft_space(line, i)) == -1)
//     return (-1);
//   if ((i = ft_dimensions(new, line, i, 1)) == -1)
//     return (-1);
//   if ((i = ft_space(line, i)) == -1)
//     return (-1);
//   if ((i = ft_color(new, line, i)) == -1)
//     return (-1);
//   new->next = *obj;
//   *obj = new;
//   free(new);
//   // printf("sq : %lf,%lf,%lf %lf,%lf,%lf %lf %d, %d, %d\n", obj->x, obj->y, obj->z, obj->vx, obj->vy, obj->vz, obj->height, obj->color1, obj->color2, obj->color3);
//   return (i);
// }
//
// int init_plane(char *line, int i, t_list **obj)
// {
//   t_list *new;
//   double tmp;
//
//   if (!(new = (t_list *)malloc(1)))
//     return (-1);
//   tmp = .0;
//   i = i + 2;
//   if ((i = ft_space(line, i)) == -1)
//     return (-1);
//   if ((i = ft_coordonnees(new, line, i)) == -1)
//     return (-1);
//   if ((i = ft_space(line, i)) == -1)
//     return (-1);
//   if ((i = ft_dimensions(new, line, i, 2)) == -1)
//     return (-1);
//   if ((i = ft_space(line, i)) == -1)
//     return (-1);
//   if ((i = ft_color(new, line, i)) == -1)
//     return (-1);
//   // printf("pl : %lf,%lf,%lf %lf,%lf,%lf %d, %d, %d\n", obj->x, obj->y, obj->z, obj->vx, obj->vy, obj->vz, obj->color1, obj->color2, obj->color3);
//   new->next = *obj;
//   *obj = new;
//   free(new);
//   return (i);
// }
//
// int init_cylinder(char *line, int i, t_list **obj)
// {
//   t_list *new;
//   double tmp;
//
//   if (!(new = (t_list *)malloc(1)))
//     return (-1);
//   tmp = .0;
//   i = i + 2;
//   if ((i = ft_space(line, i)) == -1)
//     return (-1);
//   if ((i = ft_coordonnees(new, line, i)) == -1)
//     return (-1);
//   if ((i = ft_space(line, i)) == -1)
//     return (-1);
//   if ((i = ft_dimensions(new, line, i, 3)) == -1)
//     return (-1);
//   if ((i = ft_space(line, i)) == -1)
//     return (-1);
//   if ((i = ft_dimensions(new, line, i, 2)) == -1)
//     return (-1);
//   if ((i = ft_space(line, i)) == -1)
//     return (-1);
//   if ((i = ft_dimensions(new, line, i, 1)) == -1)
//     return (-1);
//   if ((i = ft_space(line, i)) == -1)
//     return (-1);
//   if ((i = ft_color(new, line, i)) == -1)
//     return (-1);
//   // printf("cy : %lf,%lf,%lf %lf,%lf,%lf %lf %lf %d, %d, %d\n", obj->x, obj->y, obj->z, obj->vx, obj->vy, obj->vz, obj->diameter, obj->height, obj->color1, obj->color2, obj->color3);
//   new->next = *obj;
//   *obj = new;
//   free(new);
//   return (i);
// }
