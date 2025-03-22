#include "libft.h"
#include <stddef.h> 

void	*ft_memcpy(void *dest, const void *src, size_t n)
{

	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
int main()
{
    char src[] = "Hello, world!";
    char dest[20];

    ft_memcpy(dest, src, 10);
    printf("La chaîne copiée est : %s\n", dest);

    return 0;
}*/
/*Cette fonction est utilisee pour copier un certain nombre
d'octet d'une zone memoire a une autre. Cette fonction est
essentielle pour copier des donnees de maniere efficace
dans des buffers ou bloc de memoire.*/
