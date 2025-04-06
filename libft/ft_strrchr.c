/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:34:26 by bsamy             #+#    #+#             */
/*   Updated: 2025/01/05 17:34:28 by bsamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (0);
}
/*
#include <stdio.h>
int main()
{
    const char *str = "Hello, World!";
    char ch = 'o';
    
    char *result = ft_strrchr(str, ch); 
    if (result)
        printf("Dernière occurrence de '%c': %s\n", ch, result);
    else
        printf("Caractère '%c' non trouvé.\n", ch);
    
    return 0;
}*/
/*Cette fonction permet de trouver la derniere occurence
d'un caractere dans une chaine de caracteres.*/
