#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	tot_size;
	void	*dst;

	tot_size = size * count;
	if (!(dst = malloc(tot_size)))
		return (NULL);
	ft_memset(dst, 0, tot_size);
	return (dst);
}

/* La fonction alloue de la memoire 
pour un certain nombre d'elements et
initialise cette memoire a zero.
contrairement a malloc qui intialise
pas la memoire.*/
