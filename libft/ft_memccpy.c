#include "libft.h"
#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		if ((unsigned char)c == ((unsigned char *)src)[i])
			return (dst + i + 1);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int main()
{
    char src[] = "Hello, world!";
    char dst[20];

    ft_memccpy(dst, src, ',', sizeof(src));
    printf("Destination après copie : %s\n", dst);

    return 0;
}*/
/*Cette fonction de copie de memoire qui
copie un nombre d'octet depuis une source
vers une destination mais la copie s'arrete
des qu'un certain caractere (c) est rencontre.
Si il est trouve, un pointeur vers l'emplacement
suivant est renvoye.*/
