#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			(*f)(i, s + i);
			i++;
		}
	}
}

/*
** Applique la fonction f à chaque caractère de la chaine de caractères
** passée en paramètre en précisant son index en premier argument.
** Chaque caractère est passé par adresse à la fonction f afin de
** pouvoir être modifié si nécéssaire.
** Param. #1
** La chaine de caractères sur laquelle itérer.
** Param. #2
** La fonction à appeler sur chaque caractère de s et son index.
** Retour
** Rien.
*/
