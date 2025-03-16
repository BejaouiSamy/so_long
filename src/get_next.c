#include "../Includes/so_long.h"
#include <string.h>

#define BUFFER_SIZE 42

// Determine la longueur jusqu'a un caractere spe
int ft_strlen_until(char *str, char c)
{
    int i;

    i = 0;
    if(!str)
        return (0);
    while (str[i] && str[i] != c)
        i++;
    return (i);
}
// Copie memoire securisee
void ft_smemcpy(char *dest, char *src, int n)
{
    int i = 0;
    while (i < n)
    {
        dest[i] = src[i];
        i++;
    }
}
// Duplique une chaîne (remplace strdup)
char *ft_sstrdup(char *s)
{
    int len = ft_strlen_until(s, '\0');
    char *dup = malloc(len + 1);
    if (!dup)
        return (NULL);
    ft_memcpy(dup, s, len);
    dup[len] = '\0';
    return (dup);
}
// Pour allouer et copier une nouvelle ligne
char *ft_append_buffer(char *line, char *buffer, int line_len, int buffer_len)
{
    char *new_line;
    int i, j;

    new_line = malloc(line_len + buffer_len + 1);
    if (!new_line)
        return (NULL);

    i = 0;
    if (line)  // Copier l'ancienne ligne si elle existe
    {
        while (i < line_len)
        {
            new_line[i] = line[i];
            i++;
        }
        free(line);
    }

    j = 0;
    while (j < buffer_len)
    {
        new_line[i + j] = buffer[j];
        j++;
    }
    new_line[i + j] = '\0';
    return (new_line);
}
// Fonction pour vérifier si un caractère est présent dans une chaîne
int has_char(char *str, char c)
{
    int i;
    
    if (!str)
        return (0);
    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}
// Extrait la ligne du stash et met à jour le stash
char *extract_line(char **stash)
{
    char *line;
    char *new_stash;
    int line_len;

    if (!*stash || !**stash)
        return (NULL);

    line_len = ft_strlen_until(*stash, '\n');
    if ((*stash)[line_len] == '\n')
        line_len++;

    line = malloc(line_len + 1);
    if (!line)
        return (NULL);
    ft_smemcpy(line, *stash, line_len);
    line[line_len] = '\0';

    // Gestion du reste du stash
    if ((*stash)[line_len] == '\0')  // Fin du buffer, plus rien à lire
    {
        free(*stash);
        *stash = NULL;
    }
    else  // Il reste des données
    {
        new_stash = ft_sstrdup(*stash + line_len);
        free(*stash);
        *stash = new_stash;
    }

    return (line);
}
// Fonction principale pour obtenir la ligne suivante
char *get_next_line(int fd)
{
    static char *stash = NULL;
    char buffer[BUFFER_SIZE + 1];
    int bytes_read;
    char *temp;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    // Lire le fichier jusqu'à trouver un '\n' ou EOF
    while (!has_char(stash, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
            break;
        buffer[bytes_read] = '\0';

        temp = ft_append_buffer(stash, buffer, ft_strlen_until(stash, '\0'), bytes_read);
        if (!temp)
            return (NULL);
        stash = temp;
    }

    // Gérer EOF ou erreur de lecture
    if (bytes_read < 0)
    {
        free(stash);
        stash = NULL;
        return (NULL);
    }

    // Si on est à EOF et qu'il n'y a plus rien à lire
    if (bytes_read == 0 && (!stash || !*stash))
        return (NULL);

    return (extract_line(&stash));
}
