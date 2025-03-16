#include "../Includes/so_long.h"


void count_map_elements(t_game *game, char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] == 'C') // Collectible
            game->map->collectibles++;
        else if (line[i] == 'E') // Exit
            game->map->exit++;
        else if (line[i] == 'P') // Player
            game->map->player++;
        i++;
    }
}

int checks_wall(t_game *game)
{
    int x;
    int y;

    x = 0;
    // Vérifier la première et la dernière ligne
    while (x < game->map->width)
    {
        if (game->map->grid[0][x] != '1')  // Vérifie la première ligne
        {
            ft_putstr("Erreur: La carte n'est pas entourée de murs (ligne 1, position ");
            ft_putnbr(x + 1);  // Afficher la position exacte
            ft_putstr(")\n");
            return (0);
        }
        if (game->map->grid[game->map->height - 1][x] != '1')  // Vérifie la dernière ligne
        {
            ft_putstr("Erreur: La carte n'est pas entourée de murs (dernière ligne, position ");
            ft_putnbr(x + 1);
            ft_putstr(")\n");
            return (0);
        }
        x++;
    }

    y = 0;
    // Vérifier les bords gauche et droit
    while (y < game->map->height)
    {
        if (game->map->grid[y][0] != '1')  // Vérifie la première colonne
        {
            ft_putstr("Erreur: La carte n'est pas entourée de murs (colonne gauche, ligne ");
            ft_putnbr(y + 1);
            ft_putstr(")\n");
            return (0);
        }
        if (game->map->grid[y][game->map->width - 1] != '1')  // Vérifie la dernière colonne
        {
            ft_putstr("Erreur: La carte n'est pas entourée de murs (colonne droite, ligne ");
            ft_putnbr(y + 1);
            ft_putstr(")\n");
            return (0);
        }
        y++;
    }

    return (1); // La carte est bien entourée de murs
}




int parse_map(t_game *game, char *filename)
{
    int fd;
    char *line;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        ft_putstr("Impossible d'ouvrir la map\n");
        return (0);
    }

    // Allouer la structure de map dans game
    game->map = malloc(sizeof(t_map));
    if(!game->map)
    {
        ft_putstr("Erreur d'allocation memoire");
        close(fd);
        return(0);
    }

    // Initialiser les variables de map
    game->map->width = 0;
    game->map->height = 0;
    game->map->collectibles = 0;
    game->map->exit = 0;
    game->map->player = 0;
    game->map->grid = NULL;

    // Lire le fichier ligne par ligne
    while((line = get_next_line(fd)) != NULL)
    {
        if (!add_line_to_map(game, line))
        {
            free(line);
            close(fd);
            free_map(game->map);
            return (0);
        }
        free(line);
    }
    close(fd);
    return(validate_map(game));
}

int add_line_to_map(t_game *game, char *line)
{
    int i;
    char **new_grid;

    // Ignorer les lignes vides a la fin du fichier
    if (line[0] == '\0' || line[0] == '\n')
        return (1);

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
        return (0);
    }
    // Alloueur une nouvelle grille pour ajouter la ligne
    new_grid = malloc(sizeof(char *) * (game->map->height + 2));
    if (!new_grid)
    {
        ft_putstr("Erreur d'allocation memoire");
        return (0);
    }

    // Copier les anciennes lignes
    i = 0;
    while (i < game->map->height)
    {
        *new_grid = game->map->grid[i];
        i++;
    }

    // Ajouter la nouvelle ligne
    new_grid[game->map->height] = ft_strdup(line);
    new_grid[game->map->height + 1] = NULL;

    // Liberer l'ancienne grille et mettre a jour
    free(game->map->grid);
    game->map->grid = new_grid;
    game->map->height++;

    // Compter les elements importants
    count_map_elements(game, new_grid[game->map->height - 1]);
    return (1);
}

int validate_map(t_game *game)
{
    // Verifier les elements obligatoires
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
    // Verifier les murs
    if (!checks_wall(game))
    {
        ft_putstr("La map doit etre entouree de murs");
        return (0);
    }
    // Verifier si le joueur peut atteindre tous les collectibles et la sortie
    if (!check_path(game))
    {
        ft_putstr("Pas de chemin valide dans la map");
        return (0);
    }
    return (1);
}

// Fonction pour libérer la mémoire de la map
void free_map(t_map *map)
{
    int i;

    if (!map)
        return;

    if (map->grid)
    {
        for (i = 0; i < map->height; i++)
            free(map->grid[i]);
        free(map->grid);
    }
    free(map);
}