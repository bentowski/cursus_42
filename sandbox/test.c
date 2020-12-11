#include "../miniRT/minirt.h"

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

void test(t_cams **cams, int x)
{
  t_cams *new;
  t_cams *ptr;

  ptr = *cams;
  while (ptr->next)
    ptr = ptr->next;
  if (!(new = ft_calloc(1, sizeof(t_cams))))
  {
    printf("%s\n", "error malloc");
    return ;
  }
  new->fov = x * x;
  new->next = NULL;
  ptr->next = new;
  // *cams = ptr;
}

void testeur(t_map ***map)
{
	int x;
	t_map *new;

	x = 0;
	new = **map;
	while (x < 3)
  {
    test(&new->cams, x);
    printf("%s : %lf\n", "first", new->cams->fov);
    x++;
  }
}

void testing(t_map **map)
{
	testeur(&map);
}

int main(int argc, char **argv)
{
  t_map *map;
  t_cams *ptr;

  if (!(map = ft_calloc(1, sizeof(t_map))))
    return (-1);
  if (!(map->cams = ft_calloc(1, sizeof(t_cams))))
    return (-1);
  map->cams->fov = 12;
  map->cams->next = NULL;
	testing(&map);
  ptr = map->cams;
  while (ptr)
  {
    printf("%s : %lf\n", "fov", ptr->fov);
    ptr = ptr->next;
  }
}
