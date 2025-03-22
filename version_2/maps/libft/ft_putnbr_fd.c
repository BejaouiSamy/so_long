#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n % 10 + '0', fd);
}
//Exemple d'utilisation
/*
int main()
{
    ft_putnbr_fd(12345, STDOUT_FILENO);  // Affichera "12345"
    ft_putchar_fd('\n', STDOUT_FILENO);  // Ajoute un saut de ligne

    ft_putnbr_fd(-6789, STDOUT_FILENO);  // Affichera "-6789"
    ft_putchar_fd('\n', STDOUT_FILENO);

    ft_putnbr_fd(-2147483648, STDOUT_FILENO);  // Affichera "-2147483648"
    ft_putchar_fd('\n', STDOUT_FILENO);

    // 4. Écrire un nombre dans un fichier
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        write(STDERR_FILENO, "Erreur lors de l'ouverture du fichier.\n", 39);
        return 1;
    }
    ft_putnbr_fd(98765, fd);
    close(fd);

    return 0;
}*/
/*Cette fonction permet d'ecrire un entier dans
un flux de sortie en gerant les cas particuliers
comme un putnbr classique.*/