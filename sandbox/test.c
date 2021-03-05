#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_cams
{
  double fov;
  struct s_cams *next;
  struct s_cams *previous;
}               t_cams;

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

void ft_new(t_cams **cams, double fov)
{
  t_cams *ptr;
  t_cams *new;

  new = *cams;
  if (!(ptr = ft_calloc(1, sizeof(t_cams))))
    return ;
  ptr->next = *cams;
  ptr->fov = fov;
  ptr->previous = NULL;
  new->previous = ptr;
  *cams = ptr;
}

int main()
{
  t_cams *cams;

  if (!(cams = ft_calloc(1, sizeof(t_cams))))
    return (-1);
  cams->fov = 0;
  cams->next = NULL;
  cams->previous = NULL;
  ft_new(&cams, 2);
  cams = cams->next;
  cams = cams->previous;
  printf("%f\n", cams->fov);
  return (1);
}
