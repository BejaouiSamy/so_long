#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	while (src[j] && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
/*
#include <stdio.h>
int main()
{
    char dst[20] = "Hello, ";
    char src[] = "world!";

    size_t size = 20;

    size_t result = ft_strlcat(dst, src, size);

    printf("Chaîne résultante : %s\n", dst);
    printf("Longueur attendue : %zu\n", result);

    return 0;
}*/
/*Cette fonction concatene une chaine source (src)
a une chaine destination (dst) tout en s'assurant
que la taille de la chaine resultante ne depasse
pas une limite definie (size).*/
