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
        if (line[i] == 'X')
            add_enemy(game, i, y);
        i++;
    }
}

int checks_wall(t_game *game)
{
    if (!check_horizontal_walls(game))
        return (0);
    
    if (!check_vertical_walls(game))
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
    if (!init_map_structures(game))
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
    int len;
    char **new_grid;
    int check_result;

    new_grid = NULL;
    check_result = check_line_validity(game, line, &len);
    if (check_result != 2)
        return (check_result);
    if (!allocate_new_grid(game, line, &new_grid))
        return (0);
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