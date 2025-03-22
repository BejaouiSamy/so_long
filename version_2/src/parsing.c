#include "../Includes/so_long.h"


void count_map_elements(t_game *game, char *line, int y)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] == 'C') // Collectible
            game->map->collectibles++;
        else if (line[i] == 'E') // Exit
        {
            game->map->exit++;
            game->map->exit_count++;
            game->exit.x = i;
            game->exit.y = y;
            printf("✅ Sortie trouvée en (%d, %d)\n", i, y);
        }
        else if (line[i] == 'P') // Player
        {
            game->map->player++;
            game->player.x = i;
            game->player.y = y;
        }
        i++;
    }
}

int checks_wall(t_game *game)
{
    if (!checks_horizontal_walls(game))
        return (0);
    
    if (!checks_vertical_walls(game))
        return (0);
    
    return (1);
}

int parse_map(t_game *game, char *filename)
{
    int fd;
    
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        ft_putstr("Impossible d'ouvrir la map\n");
        return (0);
    }
    if (!init_map_structure(game))
    {
        close(fd);
        return (0);
    }
    if (!read_map_file(game, fd))
    {
        close(fd);
        return (0);
    }
    close(fd);
    return (validate_map(game));
}

int add_line_to_map(t_game *game, char *line)
{
    int i;
    char **new_grid;
    char *clean_line;

    // Ignorer les lignes vides a la fin du fichier
    if (line[0] == '\0' || line[0] == '\n')
        return (1);

    clean_line = ft_strdup(line);
    if (!clean_line)
        return (0);

    // Remplacer '\n' par '\0'
    i = 0;
    while(line[i] && line[i] != '\n')
        i++;
    line[i] = '\0';

    // Verifier la largeur de la map
    if (game->map->width == 0)
        game->map->width = i;
    else if (game->map->width != i)
    {
        ft_putstr("La map n'est pas rectangulaire");
        free(clean_line);
        return (0);
    }
    // Allouer une nouvelle grille pour ajouter la ligne
    new_grid = malloc(sizeof(char *) * (game->map->height + 2));
    if (!new_grid)
    {
        ft_putstr("Erreur d'allocation memoire");
        free(clean_line);
        return (0);
    }

    // Copier les anciennes lignes
    i = 0;
    while (i < game->map->height)
    {
        new_grid[i] = game->map->grid[i];
        i++;
    }

    // Ajouter la nouvelle ligne
    new_grid[game->map->height] = ft_strdup(line);
    new_grid[game->map->height + 1] = NULL;

    // Liberer l'ancienne grille et mettre a jour
    if (game->map->grid)
        free(game->map->grid);
    game->map->grid = new_grid;
    game->map->height++;

    // Compter les elements importants
    count_map_elements(game, new_grid[game->map->height - 1], game->map->height - 1);
    return (1);
}

int validate_map(t_game *game)
{
    if (game->map->width == 0)
    {
        ft_putstr("Erreur: La map est vide ou invalide\n");
        return (0);
    }
    if (game->map->collectibles == 0)
    {
        ft_putstr("Pas de collectibles dans la map");
        return (0);
    }
    if (game->map->exit == 0)
    {
        ft_putstr("Pas de sortie dans la map");
        return (0);
    }
    if (game->map->player != 1)
    {
        ft_putstr("Il doit y avoir un joueur");
        return (0);
    }
    if (!checks_wall(game))
    {
        ft_putstr("La map doit etre entouree de murs");
        return (0);
    }
    if (!check_path(game))
    {
        ft_putstr("Pas de chemin valide dans la map");
        return (0);
    }
    return (1);
}