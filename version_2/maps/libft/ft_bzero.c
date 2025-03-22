#include "libft.h"
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
        unsigned char *ptr = (unsigned char *)s;

    while (n-- > 0)
        *ptr++ = 0;

}
/*
#include <stdio.h>
#include <string.h>
int main()
{
    char buffer[10] = "Hello123";
    int i;

    printf("Avant ft_bzero: '%s'\n", buffer);
    ft_bzero(buffer, sizeof(buffer));
    printf("Après ft_bzero: '");
    i = 0;
    while(i < sizeof(buffer))
    { 
        printf("%d ", buffer[i]);
        i++;
    }
    printf("'\n");

    return 0;
}*/
/* Cette fonction permet de remplir 
une zone memoire avec des zeros octet
par octet. Principalement pour initialiser
pour de la gestion de data ou la preparation
de structure de donnees par exemple.
*/
