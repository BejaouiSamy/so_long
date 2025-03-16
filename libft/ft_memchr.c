#include "libft.h"
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char*)s)[i] == (unsigned char)c)
			return ((void*)(s + i));
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int main()
{
    char str[] = "Hello, world!";
    char *result;

    result = ft_memchr(str, 'd', sizeof(str));
    if (result != NULL)
    {
        printf("Le caractère a été trouvé à l'adresse: %p\n", result);
        printf("Le caractère trouvé est: %c\n", *result);
    }
    else
        printf("Le caractère n'a pas été trouvé.\n");

    return 0;
}*/
/*Cette fonction est utilisee pour chercher
un caractere dans un zone memoire donnee,
sur une taille determinee.*/
