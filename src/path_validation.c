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
    int x, y, collectibles_found = 0, exit_found = 0;
    char **visited;
    t_queue *queue = NULL;

    // Allouer et initialiser le tableau de cases visitées
    visited = malloc(sizeof(char *) * game->map->height);
    for (y = 0; y < game->map->height; y++)
    {
        visited[y] = malloc(sizeof(char) * game->map->width);
        for (x = 0; x < game->map->width; x++)
            visited[y][x] = 0;
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
        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (is_valid_position(game->map, new_x, new_y, visited))
            {
                enqueue(&queue, new_x, new_y);
                visited[new_y][new_x] = 1;
            }
        }
    }

    // Libérer la mémoire du tableau de visite
    for (y = 0; y < game->map->height; y++)
        free(visited[y]);
    free(visited);

    // Vérifier si tous les collectibles et la sortie sont accessibles
    if (collectibles_found == game->map->collectibles && exit_found)
        return (1);

    ft_putstr("Erreur: Chemin invalide, certains objets sont inaccessibles.\n");
    return (0);
}
