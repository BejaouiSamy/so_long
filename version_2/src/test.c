#include <unistd.h>
#include <string.h>

int ft_strcmp(char *s1, char *s2)
{
    while (*s1 == *s2 && *s1)
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}
int check_file_extension(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    while (i >= 0 && str[i] != '.')
        i--;
    if (i <= 0)
        return (0);
    if (ft_strcmp(str + i, ".ber") == 0)
        return (1);
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {   
        if (check_file_extension(av[1]))
            write(1, "everything is good", 18);
        else
            write(1, "Error", 5);
    }
}