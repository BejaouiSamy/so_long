#include "libft.h"
#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	if (!dst && !src)
		return (0);
	i = 0;
	if ((size_t)dst - (size_t)src < len)
	{
		i = len - 1;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	else
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}
/*
#include <stdio.h>
int main() {
    char str[] = "Hello, world!";
    
    ft_memmove(str + 7, str, 5);
    printf("Après ft_memmove : %s\n", str);
    
    return 0;
}*/
/*Cette fonction est une variante de memcpy, mais
elle est utilisee pour gerer correctement les cas
ou les zones de memoire (src) et destinantion (dst)
se chevauchent. Celle ci prend des precautions
pour garantir que la copie des donnees se fait
correctement, meme si les zones se chevauchent.*/
