/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:44:01 by bsamy             #+#    #+#             */
/*   Updated: 2025/01/06 16:26:50 by bsamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}
/*
#include <stdio.h>
int main()
{
    char *str1 = "Hello, ";
    char *str2 = "world!";
    char *result = ft_strjoin(str1, str2);

    if (result)
    {
        printf("Résultat de la concaténation: %s\n", result);
        free(result);
    }
    else
    {
        printf("Erreur de concaténation\n");
    }
    return 0;
}*/
/*Cette fonction concatene deux chaines de caracteres
s1 et s2, et retourne une nouvelle chaine qui contient
la combinaison des deux.*/
