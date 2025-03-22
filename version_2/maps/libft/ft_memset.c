#include "libft.h"
#include <stddef.h>

void	*ft_memset(void *dest, int c, size_t count)
{
    unsigned char	*p; 
    
    p = dest;
    while (count > 0)
    {
        *p = (unsigned char)c;
        p++;
        count--;
    }
    return (dest);
}
/*
#include <stdio.h>
int main()
{
    char str[20] = "Hello, world!";
    
    printf("Avant ft_memset : %s\n", str);
    ft_memset(str, 'A', 5);
    printf("Après ft_memset : %s\n", str);

    return 0;
}*/
/*Cette fonction permet d'initialiser ou remplir
un bloc memoire avec une valeur specifique sur une
certaine quantite d'octets. c'est une fonction
de manipulation de memoire souvent utilisee pour
initialiser des tableaux ou des buffers a une
valeur donnee.*/
