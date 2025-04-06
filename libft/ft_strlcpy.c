/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:31:50 by bsamy             #+#    #+#             */
/*   Updated: 2025/01/06 16:04:43 by bsamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src [i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
#include <stdio.h>
int main()
{
    char src[] = "Hello, world!";
    char dest[20];
    size_t size = 10;
    size_t result = ft_strlcpy(dest, src, size);
    printf("Chaîne copiée : %s\n", dest);
    printf("Longueur de la chaîne source : %zu\n", result);

    return 0;
}*/
/*Cette fonction copie une chaine de caracteres d'une source
(src) vers une destination (dest) tout en garantissant
que la taille de la chaine resultante ne depasse pas
la taille maximale specifiee (size).*/
