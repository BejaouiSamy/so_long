#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int main()
{
    char str1[] = "Hello, world!";
    char str2[] = "Hello, world!";
    char str3[] = "Hello, C!";

    int result1 = ft_memcmp(str1, str2, sizeof(str1));
    int result2 = ft_memcmp(str1, str3, sizeof(str1));

    if (result1 == 0)
        printf("Les deux chaînes sont identiques (str1 et str2)\n");
    else
        printf("Les chaînes sont différentes (str1 et str2)\n");

    if (result2 == 0)
        printf("Les deux chaînes sont identiques (str1 et str3)\n");
    else
        printf("Les chaînes sont différentes (str1 et str3)\n");

    return 0;
}*/
/*Cette fonction est utilisee pour comparer deux blocs
de memoire byte par byte sur une taille donnee.*/
