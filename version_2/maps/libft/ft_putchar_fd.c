#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*Cette fonction permet d'ecrire un caractere
a un emplacement specifie, que ce soit sortie
standard, un fichier ou autre flux de sortie.*/
