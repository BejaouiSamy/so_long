/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:34:54 by bsamy             #+#    #+#             */
/*   Updated: 2025/01/06 19:04:15 by bsamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	slen;
	size_t	finish;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	finish = 0;
	if (start < slen)
		finish = slen - start;
	if (finish > len)
		finish = len;
	new = (char *)malloc(sizeof(char) * (finish + 1));
	if (!new)
		return (0);
	ft_strlcpy(new, s + start, finish + 1);
	return (new);
}
/*
#include <stdio.h>
int main()
{
    char *str = "Hello, World!";
    unsigned int start = 7;
    size_t len = 5;

    char *substr = ft_substr(str, start, len);
    if (substr)
    {
        printf("Sous-chaîne extraite : '%s'\n", substr);
        free(substr);
    }
    else
    {
        printf("Erreur d'allocation mémoire\n");
    }

    return 0;
}*/
/*La fonction permet d'extraire une sous-chaine
d'une chaine de caracteres a partir d'une position donnee
et sur une longueur specifiee.*/
