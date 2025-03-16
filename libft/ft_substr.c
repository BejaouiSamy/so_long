#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (str == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
/*
#include <stdio.h>
int main()
{
    char *str = "Hello, World!";
    unsigned int start = 7;
    size_t len = 5;

    char *substr = ft_substr(str, start, len);
    if (substr)
    {
        printf("Sous-chaîne extraite : '%s'\n", substr);
        free(substr);
    }
    else
    {
        printf("Erreur d'allocation mémoire\n");
    }

    return 0;
}*/
/*La fonction permet d'extraire une sous-chaine
d'une chaine de caracteres a partir d'une position donnee
et sur une longueur specifiee.*/