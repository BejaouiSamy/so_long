#include "libft.h"

int	ft_atoi(char *str)
{
    int	res;
    int	sign;

    res = 0;
    sign = 1;
    while (*str == 32 || (*str >= 9 && *str <= 13))
        str++;
    while (*str == '-' || *str == '+')
    {   
        if (*str == '-')
            res *= -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        res = res * 10 + (*str - '0');
        str++;
    }
    return (res * sign);   
}
/*
#include <stdio.h>
int main(void)
{
    printf("%d\n", ft_atoi("123456"));
    printf("%d\n", ft_atoi("        1234abc56"));
    printf("%d\n", ft_atoi("-----123456"));
    printf("%d\n", ft_atoi("-123456"));
}*/
