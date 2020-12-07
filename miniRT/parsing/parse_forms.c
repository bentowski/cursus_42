// #include "../minirt.h"
//
// int init_sphere(char *line, int i, t_list ****obj)
// {
//   t_list *new;
//   double tmp;
//
//   if (!(new = ft_calloc(1, sizeof(t_list))))
//     return (-1);
//   tmp = .0;
//   i= i + 2;
//   new->type = 1;
//   if ((i = ft_coordonnees(new, line, i, 1)) != -1)
//   	if ((i = ft_structuration(new, line, i, 1)) != -1)
//   		if ((i = ft_color(new, line, i)) != -1)
// 			{
// 				new->next = ***obj;
// 				***obj = new;
// 				return (i);
// 			}
// 	free(new);
//   return (i);
// }
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
