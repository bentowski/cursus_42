#include "get_next_line.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *psrc;
	char *pdst;

	psrc = (char *)src;
	pdst = (char *)dst;
	if (!src && !dst)
		return (NULL);
	while (n > 0)
	{
		pdst[n - 1] = psrc[n - 1];
		n--;
	}
	return (dst);
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
