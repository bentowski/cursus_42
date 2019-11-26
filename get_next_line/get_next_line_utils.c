#include "get_next_line.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *psrc;
	char *pdst;
	size_t x;

	x = 1;
	psrc = (char *)src;
	pdst = (char *)dst;
	if (!src && !dst)
		return (NULL);
	while (n > x)
	{
		pdst[x - 1] = psrc[x];
		x++;
	}
	pdst[x - 1] = '\0';
	return (dst);
}

char **first_tab(int fd)
{
	char **first_tab;

	if (!(first_tab = (char **)malloc(2)))
		return (NULL);
	if (!(first_tab[0] = (char *)malloc(2)))
		return (NULL);
	first_tab[0][0] = fd;
	first_tab[0][1] = '\0';
	first_tab[1] = NULL;
	return (first_tab);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*cpy;

	len = 0;
	while (s1[len])
		len++;
	if (!(cpy = (char *)malloc(len + 1)))
		return (NULL);
	ft_memcpy(cpy, s1, len);
	return (cpy);
}
