#include "../minirt.h"

int init_sphere(char *line, int i, t_objs **objs)
{
  t_objs *new;
  t_base *ptr;

  i= i + 2;
  if ((new = ft_calloc(1, sizeof(t_objs))))
    if ((new->base = ft_calloc(1, sizeof(t_base))))
    {
      ptr = new->base;
      if ((ptr->origins = ft_calloc(1, sizeof(t_triade))))
        if ((ptr->color = ft_calloc(1, sizeof(t_triade))))
          if ((i = ft_coordonnees(ptr->origins, line, i)) != -1)
            if ((i = ft_space(line, i)) != -1)
              if ((new->diam = ft_routine(new->diam, line, &i, 2)) != -1)
                if ((i = ft_color(ptr->color, line, i)) != -1)
                  if (ptr->color->x >= 0 && ptr->color->x <= 255)
                    if (ptr->color->y >= 0 && ptr->color->y <= 255)
                      if (ptr->color->z >= 0 && ptr->color->z <= 255)
                      {
                        new->type = 1;
                        new->next = *objs;
                        *objs = new;
                        return (i);
                      }
    }
	ft_clear_objs(new);
  return (-1);
}
//
// int init_square(char *line, int i, t_list ****obj)
// {
//   t_list *new;
//   double tmp;
//
//   if (!(new = ft_calloc(1, sizeof(t_list))))
//     return (-1);
//   tmp = .0;
//   i = i + 2;
//   new->type = 2;
//   if ((i = ft_coordonnees(new, line, i, 1)) != -1)
//   	if ((i = ft_structuration(new, line, i, 3)) != -1)
//   		if ((i = ft_structuration(new, line, i, 1)) != -1)
//   			if ((i = ft_color(new, line, i)) != -1)
// 			  {
// 					new->next = ***obj;
// 					***obj = new;
// 					return (i);
// 			  }
// 	free(new);
// 	return (i);
// }
//
// int init_plane(char *line, int i, t_list ****obj)
// {
//   t_list *new;
//   double tmp;
//
//   if (!(new = ft_calloc(1, sizeof(t_list))))
//     return (-1);
//   tmp = .0;
//   i = i + 2;
//   new->type = 3;
//   if ((i = ft_coordonnees(new, line, i, 1)) != -1)
//   	if ((i = ft_structuration(new, line, i, 3)) != -1)
//   		if ((i = ft_color(new, line, i)) != -1)
// 		  {
// 				new->next = ***obj;
// 				***obj = new;
// 				return (i);
// 		  }
// 	free(new);
// 	return (i);
// }
//
// int init_cylinder(char *line, int i, t_list ****obj)
// {
//   t_list *new;
//   double tmp;
//
//   if (!(new = ft_calloc(1, sizeof(t_list))))
//     return (-1);
//   tmp = .0;
//   i = i + 2;
//   new->type = 4;
//   if ((i = ft_coordonnees(new, line, i, 1)) != -1)
//   	if ((i = ft_structuration(new, line, i, 3)) != -1)
//   		if ((i = ft_structuration(new, line, i, 2)) != -1)
//   			if ((i = ft_structuration(new, line, i, 1)) != -1)
// 				  if ((i = ft_color(new, line, i)) != -1)
// 				  {
// 						new->next = ***obj;
// 						***obj = new;
// 						return (i);
// 				  }
// 	free(new);
// 	return (i);
// }
//
// int init_triangle(char *line, int i, t_list ****obj)
// {
// 	t_list *new;
// 	double tmp;
//
// 	if (!(new = ft_calloc(1, sizeof(t_list))))
// 		return (-1);
// 	tmp = .0;
// 	i = i + 2;
// 	new->type = 5;
// 	if ((i = ft_coordonnees(new, line, i, 1)) != -1)
// 		if ((i = ft_coordonnees(new, line, i, 2)) != -1)
// 			if ((i = ft_coordonnees(new, line, i, 3)) != -1)
// 				if ((i = ft_color(new, line, i)) != -1)
// 				{
// 					new->next = ***obj;
// 					***obj = new;
// 					return (i);
// 				}
// 	free(new);
// 	return (i);
// }
