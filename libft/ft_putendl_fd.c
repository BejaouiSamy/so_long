/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:27:55 by bsamy             #+#    #+#             */
/*   Updated: 2025/01/05 17:28:03 by bsamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/*Cette fonction est un mix de :
ft_putstr_fd et ft_putchar_fd. Elle
permet d'ecrire une chaine de caracteres 
dans un flux de sortie et d'ajouter ('\n')
a la fin.*/
