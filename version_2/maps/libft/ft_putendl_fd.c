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