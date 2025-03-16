#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char *s1, char *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = 0;
	if (s1 != 0 && set != 0)
	{
		i = 0;
		j = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > i)
			j--;
		str = (char *)malloc(sizeof(char) * (j - i + 1));
		if (str)
			ft_strlcpy(str, &s1[i], j - i + 1);
	}
	return (str);
}
/*
#include <stdio.h>
int main()
{
    char *str = "   **Hello, World!**   ";
    char *set = " *";
    char *result = ft_strtrim(str, set);

    if (result)
    {
        printf("Trimmed string: '%s'\n", result);
        free(result);
    }
    else
    {
        printf("Error: Memory allocation failed or invalid input.\n");
    }

    return 0;
}*/
/*Cette fonction permet de supprimer les caracteres
specifies (contenue dans set) au debut et a la fin de s1.
C'est une operation courante, par exemple pour enlever
les espaces, tabulations ou autre symboles.*/