#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!str && !len)
		return (0);
	if (to_find[0] == '\0' || to_find == str)
		return ((char *)str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j] && (i + j) < len)
		{
			if (str[i + j] == '\0' && to_find[j] == '\0')
				return ((char *)&str[i]);
			j++;
		}
		if (to_find[j] == '\0')
			return ((char *)(str + i));
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int main()
{
    const char *str = "Hello, world! Welcome to the world of C programming.";
    const char *to_find = "world";
    size_t len = 20;

    char *result = ft_strnstr(str, to_find, len);

    if (result != NULL)
        printf("Sous-chaîne trouvée : %s\n", result);
    else
        printf("Sous-chaîne non trouvée.\n");

    return 0;
}*/
/*Cette fonction permet de rechercher une sous-chaine
(ou mot) to_find dans une chaine principale str, mais
une limite de caracteres a examiner, specifie par le
parametre len.*/