#include "mlx.h"
#include <fcntl.h>
#include "minirt.h"
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = (char *)s;
	while (n > 0)
	{
		p[n - 1] = 0;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	int		lenght;

	lenght = count * size;
	if (!(ptr = malloc(lenght)))
		return (NULL);
	ft_bzero(ptr, lenght);
	return (ptr);
}

int init_sphere(char *line, int i, t_list ***obj)
{
  t_list *new;
  double tmp;

  if (!(new = ft_calloc(1, sizeof(t_list))))
    return (-1);
  tmp = .0;
  i= i + 2;
  new->name = "sp";
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR sphere space", i);
    free(new);
    return (-1);
  }
  printf("%s\n", "test");
  if ((i = ft_coordonnees(new, line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR sphere coordonnees", i);
    free(new);
    return (-1);
  }
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR sphere space", i);
    free(new);
    return (-1);
  }
  if ((i = ft_dimensions(new, line, i, 1)) == -1)
  {
    printf("%s : %d\n", "ERREUR sphere dimensions", i);
    free(new);
    return (-1);
  }
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR sphere space", i);
    free(new);
    return (-1);
  }
  if ((i = ft_color(new, line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR sphere color", i);
    free(new);
    return (-1);
  }
  // new->next = **obj; //en activant cette ligne, erreurs malloc
  **obj = new; // oui oui celle-ci aussi
  printf("sp : %lf,%lf,%lf %lf, %d, %d, %d\n", new->x, new->y, new->z, new->diameter, new->color1, new->color2, new->color3);
  free(new);
  return (i);
}

int init_square(char *line, int i, t_list ***obj)
{
  t_list *new;
  double tmp;

  if (!(new = ft_calloc(1, sizeof(t_list))))
    return (-1);
  tmp = .0;
  i = i + 2;
  new->name = "sq";
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR square space", i);
    free(new);
    return (-1);
  }
  if ((i = ft_coordonnees(new, line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR square coordonnees", i);
    free(new);
    return (-1);
  }
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR square space", i);
    free(new);
    return (-1);
  }
  if ((i = ft_dimensions(new, line, i, 3)) == -1)
  {
    printf("%s : %d\n", "ERREUR square dimensions", i);
    free(new);
    return (-1);
  }
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR square space", i);
    free(new);
    return (-1);
  }
  if ((i = ft_dimensions(new, line, i, 1)) == -1)
  {
    printf("%s : %d\n", "ERREUR square dimensions 2", i);
    free(new);
    return (-1);
  }
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR square space", i);
    free(new);
    return (-1);
  }
  if ((i = ft_color(new, line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR square color", i);
    free(new);
    return (-1);
  }
  new->next = **obj;
  **obj = new;
  printf("sq : %lf,%lf,%lf %lf,%lf,%lf %lf %d, %d, %d\n", new->x, new->y, new->z, new->vx, new->vy, new->vz, new->height, new->color1, new->color2, new->color3);
  free(new);
  return (i);
}

int init_plane(char *line, int i, t_list ***obj)
{
  t_list *new;
  double tmp;

  if (!(new = ft_calloc(1, sizeof(t_list))))
    return (-1);
  tmp = .0;
  i = i + 2;
  new->name = "pl";
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR plane space 3", i);
    free(new);
    return (-1);
  }
  if ((i = ft_coordonnees(new, line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR plane coordonnees", i);
    free(new);
    return (-1);
  }
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR plane space 2", i);
    free(new);
    return (-1);
  }
  if ((i = ft_dimensions(new, line, i, 3)) == -1)
  {
    printf("%s : %d\n", "ERREUR plane dimensions", i);
    free(new);
    return (-1);
  }
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR plane space 1", i);
    free(new);
    return (-1);
  }
  if ((i = ft_color(new, line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR plane color", i);
    free(new);
    return (-1);
  }
  new->next = **obj;
  **obj = new;
  printf("pl : %lf,%lf,%lf %lf,%lf,%lf %d, %d, %d\n", new->x, new->y, new->z, new->vx, new->vy, new->vz, new->color1, new->color2, new->color3);
  free(new);
  return (i);
}

int init_cylinder(char *line, int i, t_list ***obj)
{
  t_list *new;
  double tmp;

  if (!(new = ft_calloc(1, sizeof(t_list))))
    return (-1);
  tmp = .0;
  i = i + 2;
  new->name = "cy";
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR cylinder space", i);
    free(new);
    return (-1);
  }
  if ((i = ft_coordonnees(new, line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR cylinder coordonnees", i);
    free(new);
    return (-1);
  }
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR cylinder space", i);
    free(new);
    return (-1);
  }
  if ((i = ft_dimensions(new, line, i, 3)) == -1)
  {
    printf("%s : %d\n", "ERREUR cylinder dimensions 1", i);
    free(new);
    return (-1);
  }
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR cylinder space", i);
    free(new);
    return (-1);
  }
  if ((i = ft_dimensions(new, line, i, 2)) == -1)
  {
    printf("%s : %d\n", "ERREUR cylinder dimensions 2", i);
    free(new);
    return (-1);
  }
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR cylinder space", i);
    free(new);
    return (-1);
  }
  if ((i = ft_dimensions(new, line, i, 1)) == -1)
  {
    printf("%s : %d\n", "ERREUR cylinder dimensions 1", i);
    free(new);
    return (-1);
  }
  if ((i = ft_space(line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR cylinder space", i);
    free(new);
    return (-1);
  }
  if ((i = ft_color(new, line, i)) == -1)
  {
    printf("%s : %d\n", "ERREUR cylinder color", i);
    free(new);
    return (-1);
  }
  new->next = **obj;
  **obj = new;
  printf("cy : %lf,%lf,%lf %lf,%lf,%lf %lf %lf %d, %d, %d\n", new->x, new->y, new->z, new->vx, new->vy, new->vz, new->diameter, new->height, new->color1, new->color2, new->color3);
  free(new);
  return (i);
}
