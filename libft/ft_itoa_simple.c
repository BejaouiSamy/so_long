#include "libft.h"

void	ft_itoa_simple(int n, char *str)
{
	int	i;
	int	temp;
	int	len = 0;
	char	reverse[20];

	i = 0;
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return;
	}
	if (n < 0)
	{
		str[i++] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		reverse[len++] = (n % 10) + '0';
		n = n / 10;
	}
	temp = len - 1;
	while (temp >= 0)
	{
		str[i++] = reverse[temp--];
	}
	str[i] = '\0';
}
