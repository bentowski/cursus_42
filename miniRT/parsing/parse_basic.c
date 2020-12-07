#include "../minirt.h"

int resolution(t_map *map, char *line, int i)
{
  i++;
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR MAP CONFIG win_width, &win_heightOLUTION", i);
    return (-1);
  }

  while (line[i] >= '0' && line[i] <= '9')
    map->resolution->win_width = map->resolution->win_width * 10 + (line[i++] - 48);
  printf("%s\n", "BOOM");
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR MAP CONFIG win_width, &win_heightOLUTION", i);
    return (-1);
  }

  while (line[i] >= '0' && line[i] <= '9')
    map->resolution->win_height = (map->resolution->win_height * 10) + (line[i++] - 48);
  return (i);
}

// int ambiance(char *line, int i, t_list ****obj)
// {
//   t_list *new;
//
//   if (!(new = ft_calloc(1, sizeof(t_list))))
//     return (-1);
//   i = i + 2;
//   new->type = 0;
//   if ((i = ft_space(line, i)) != -1)
//     if ((new->puissance = ft_routine(new->puissance, line, &i, 1)) != -1)
//       if ((i = ft_color(new, line, i)) != -1)
//       {
//         new->next = ***obj;
//         ***obj = new;
//         return (i);
//       }
//   free(new);
//   return (i);
// }
//
// int camera(char *line, int i, t_list ****obj)
// {
//   t_list *new;
//
//   if (!(new = ft_calloc(1, sizeof(t_list))))
//     return (-1);
//   i = i + 1;
//   new->type = 8;
//   if ((i = ft_coordonnees(new, line, i, 1)) != -1)
//     if ((i = ft_structuration(new, line, i, 3)) != -1)
//       if ((i = ft_space(line, i)) != -1)
//         if ((new->fov = ft_routine(new->fov, line, &i, 2)) != -1)
//         {
//           new->next = ***obj;
//           ***obj = new;
//           return (i);
//         }
//   free(new);
//   return (i);
// }
//
// int light(char *line, int i, t_list ****obj)
// {
//   t_list *new;
//
//   if (!(new = ft_calloc(1, sizeof(t_list))))
//     return (-1);
//   i = i + 1;
//   new->type = 9;
//   if ((i = ft_coordonnees(new, line, i, 1)) != -1)
//     if ((i = ft_space(line, i)) != -1)
//       if ((new->puissance = ft_routine(new->puissance, line, &i, 1)) != -1)
//         if ((i = ft_color(new, line, i)) != -1)
//         {
//           new->next = ***obj;
//           ***obj = new;
//           return (i);
//         }
//   free(new);
//   return (i);
// }
