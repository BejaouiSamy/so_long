#include "../Includes/so_long.h"

// Ajouter un élément à la file d'attente
void enqueue(t_queue **queue, int x, int y)
{
    t_queue *new = malloc(sizeof(t_queue));
    t_queue *temp;

    if (!new)
        return;
    new->x = x;
    new->y = y;
    new->next = NULL;

    if (!*queue)
        *queue = new;
    else
    {
        temp = *queue;
        while (temp->next)
            temp = temp->next;
        temp->next = new;
    }
}

// Retirer un élément de la file d'attente
void dequeue(t_queue **queue)
{
    t_queue *temp;

    if (!*queue)
        return;
    temp = *queue;
    *queue = (*queue)->next;
    free(temp);
}

// Vérifier si une position est valide
int is_valid_position(t_map *map, int x, int y, char **visited)
{
    return (x >= 0 && x < map->width && y >= 0 && y < map->height &&
            map->grid[y][x] != '1' && visited[y][x] == 0);
}

// Vérifier si tous les collectibles et la sortie sont accessibles
int check_path(t_game *game)
{
    int x;
    int y;
    int collectibles_found;
    int exit_found;
    char **visited;
    int i;

    collectibles_found = 0;
    exit_found = 0;

    printf("Dimensions de la carte: %d x %d\n", game->map->width, game->map->height);
    printf("Position du joueur: (%d, %d)\n", game->player.x, game->player.y);
    printf("Nombre de collectibles attendus: %d\n", game->map->collectibles);
    printf("Nombre de sorties attendus: %d\n", game->map->exit);

    // Au début de check_path
    /*if (game->player.x == 0 && game->player.y == 0)
    {
        // Si ces valeurs sont 0, c'est peut-être qu'elles n'ont jamais été initialisées
        printf("ATTENTION: Position du joueur non initialisée ou à l'origine (0,0)\n");
        // Parcourir la carte pour trouver le joueur
        find_player_position(game);
    }*/
    t_queue *queue = NULL;

    // Allouer et initialiser le tableau de cases visitées
    visited = malloc(sizeof(char *) * game->map->height);
    y = 0;
    while (y < game->map->height)
    {
        visited[y] = malloc(sizeof(char) * game->map->width);
        x = 0;
        while (x < game->map->width)
        {
            visited[y][x] = 0;
            x++;
        }
        y++;
    }

    // Ajouter le joueur à la file d'attente
    enqueue(&queue, game->player.x, game->player.y);
    visited[game->player.y][game->player.x] = 1;

    // Déplacements possibles : droite, gauche, bas, haut
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (queue)
    {
        x = queue->x;
        y = queue->y;
        dequeue(&queue);

        // Vérifier si c'est un collectible
        if (game->map->grid[y][x] == 'C')
            collectibles_found++;

        // Vérifier si c'est la sortie
        if (game->map->grid[y][x] == 'E')
            exit_found = 1;

        // Explorer les 4 directions
        i = 0;
        while (i < 4)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (is_valid_position(game->map, new_x, new_y, visited))
            {
                enqueue(&queue, new_x, new_y);
                visited[new_y][new_x] = 1;
            }
            i++;
        }
    }
    // Libérer la mémoire du tableau de visite
    y = 0;
    while (y < game->map->height)
    {
        free(visited[y]);
        y++;
    }
    free(visited);

    // Vérifier si tous les collectibles et la sortie sont accessibles
    if (collectibles_found == game->map->collectibles && exit_found)
        return (1);

    ft_putstr("Erreur: Chemin invalide, certains objets sont inaccessibles.\n");
    return (0);
}