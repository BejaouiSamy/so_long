#include "libft.h"
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < n) && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (((unsigned char)s1[i] - (unsigned char)s2[i]));
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int main()
{
    const char *str1 = "Hello, world!";
    const char *str2 = "Hello, everyone!";
    
    printf("5 caractères: %d\n", ft_strncmp(str1, str2, 5));
    printf("10 caractères: %d\n", ft_strncmp(str1, str2, 10));
    return 0;
}*/
/*Cette fonction compare deux chaines (s1 et s2) jusqu'a
un certain nombre de caractere specifie par n. si une
difference est trouvee avant d'atteindre n caractere ou
si les deux chaines sont egales sur n, la fonction renvoie
une valeur indiquant la difference.*/