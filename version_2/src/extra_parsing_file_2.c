#include "../Includes/so_long.h"

int check_line_validity(t_game *game, char *line, int *len)
{
    int i;

    i = 0;
    // Ignorer les lignes vides du fichier
    if (line[0] == '\0' || line[0] == '\n')
        return (1);
    // Calculer la longueur de la ligne sans le retour a la ligne
    while(line[i] && line[i] != '\n')
        i++;
    line[i] = '\0';
    *len = i;
    // Verifier la largeur de la map
    if (game->map->width == 0)
        game->map->width = i;
    else if (game->map->width != i)
    {
        ft_putstr("La map n'est pas rectangulaire");
        return (0);
    }
    return (2); // 2 indique qu'il faut continuer le traitement
}

int allocate_new_grid(t_game *game, char *line, char ***new_grid)
{
    int i;

    *new_grid = malloc(sizeof(char *) * (game->map->height + 2));
    if (!*new_grid)
    {
        ft_putstr("Erreur d'allocation memoire");
        return (0);
    }
    i = 0;
    while(i < game->map->height)
    {
        (*new_grid)[i] = game->map->grid[i];
        i++;
    }
    (*new_grid)[game->map->height] = ft_strdup(line);
    (*new_grid)[game->map->height + 1] = NULL;
    return (1);
}

void count_collectibles(t_game *game, char element)
{
    if (element == 'C')
        game->map->collectibles++;
    else if (element == 'T')
        game->map->glove++;
    else if (element == 'G')
        game->map->gelano++;
    else if (element == 'O')
        game->map->popo++;
}

void process_map_element(t_game *game, char element, int x, int y)
{
    if (element == 'E')
    {
        game->map->exit++;
        game->exit.x = x;
        game->exit.y = y;
        ft_putstr("✅ Sortie trouvée en (");
        ft_putnbr(x);
        ft_putstr(", ");
        ft_putnbr(y);
        ft_putstr(")\n");    }
    else if (element == 'P')
    {
        game->map->player++;
        game->player.x = x;
        game->player.y = y;
    }
    else if (element == 'X')
        add_enemy(game, x, y);
}
