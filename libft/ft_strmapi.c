#include "libft.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return len;
}

char	to_upper(unsigned int index, char c)
{
	(void)index; // L'index n'est pas utilisé ici, mais il est passé à la fonction
	if (c >= 'a' && c <= 'z')
		return c - 'a' + 'A'; // Convertit une lettre minuscule en majuscule
	return c;
}

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	unsigned int i;
	unsigned int length;
	char *res;

	if (!s)
		return NULL;
	length = ft_strlen(s);
	res = malloc(length * sizeof(char) + 1);
	if (!res)
		return NULL;
	i = 0;
	while(i < length)
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return(res);
}
/*
#include <stdio.h>
int main()
{
    char str[] = "hello, world!";
    char *new_str = ft_strmapi(str, to_upper);

    if (new_str)
    {
        printf("Original string: %s\n", str);
        printf("Transformed string: %s\n", new_str);
        free(new_str); // Libère la mémoire allouée
    }
    else
    {
        printf("Memory allocation failed!\n");
    }

    return 0;
}*/
/*Mettre ces fonctions pour tester.
int ft_strlen(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}

char to_upper(unsigned int index, char c)
{
    (void)index; // L'index n'est pas utilisé ici, mais il est passé à la fonction
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 'A'; // Convertit une lettre minuscule en majuscule
    return c;
}*/
/*Cette fonction prend une chaine de caractere s et
une fonction f en argument. Elle applique cette fonction
a chaque caractere de la chaine en utilisant son index,
et retourne une nouvelle chaine ou chaque caractere a 
ete transforme par la fonction.*/
