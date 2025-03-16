#include "libft.h"
#include <stdlib.h>

static char	*ft_char(char *s, unsigned int number, long int len)
{
	while (number > 0)
	{
		s[len--] = 48 + (number % 10);
		number = number / 10;
	}
	return (s);
}

static long int	ft_len(int n)
{
	int	len;

	len = 0;
	if(n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	long int	len;
	unsigned int	number;
	int	sign;

	sign = 1;
	len = ft_len(n);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return NULL;
	s[len--] = '\0';
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		sign *= -1;
		number = n * -1;
		s[0] = '-';
	}
	else
		number = n;
	s = ft_char(s, number, len);
	return (s);
}
/*
#include <stdio.h>
int main()
{
    int n1 = 1234;
    int n2 = -5678;
    int n3 = 0;

    char *str1 = ft_itoa(n1);
    char *str2 = ft_itoa(n2);
    char *str3 = ft_itoa(n3);
    printf("Le nombre %d est converti en chaîne : %s\n", n1, str1);
    printf("Le nombre %d est converti en chaîne : %s\n", n2, str2);
    printf("Le nombre %d est converti en chaîne : %s\n", n3, str3);
    free(str1);
    free(str2);
    free(str3);

    return 0;
}*/
/*Cette fonction permet la conversion des
entiers en chaine de caracteres. 
Le contraire d'atoi.

La fonction  ft_len  calcule le nombre
de chiffres necessaires pour representer 
un entier n en base 10.
Elle permet,
-le calcul de la chaine necessaire.
-La gestion des negatifs et zero.
-optimiser l'allocation de memoire.

La fonction  ft_char  permet de 
remplir le tableau s avec les chiffres de
l'entier number.

La fonction  itoa  cette fonction convertit
un entier en une chaine de caracteres.*/
