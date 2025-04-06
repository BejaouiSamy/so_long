/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:29:54 by bsamy             #+#    #+#             */
/*   Updated: 2025/04/06 13:31:39 by bsamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_itoa_reverse(int n, char *reverse)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		reverse[len++] = (n % 10) + '0';
		n = n / 10;
	}
	reverse[len] = '\0';
}

void	ft_itoa_simple(int n, char *str)
{
	int		i;
	int		temp;
	int		len;
	char	reverse[20];

	len = 0;
	i = 0;
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return ;
	}
	if (n < 0)
	{
		str[i++] = '-';
		n *= -1;
	}
	temp = len - 1;
	while (temp >= 0)
	{
		str[i++] = reverse[temp--];
	}
	ft_itoa_reverse(n, reverse);
	str[i] = '\0';
}
