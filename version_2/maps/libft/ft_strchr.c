#include "libft.h"

char	*ft_strchr(const char *str, int search_str)
{
    while (*str != '\0')
    {
        if (search_str == *str)
            return ((char *)str);
        str++;
    }
        return 0;
}
/*Cette fonction recherche la premiere occurence
d'un caractere donnee dans une chaine. Si celui ci
est trouve, elle retourne un pointeur vers son emplacement.*/
