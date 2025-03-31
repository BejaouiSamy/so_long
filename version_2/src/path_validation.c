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

// Effectue le parcours en largeur pour vérifier l'accessibilité
int bfs(t_game *game, char **visited, int *c_found, int *e_found)
{
  int x;
  int y;
  t_queue *queue;

  queue = NULL;
  enqueue(&queue, game->player.x, game->player.y);
  visited[game->player.y][game->player.x] = 1;
  while (queue)
  {
    x = queue->x;
    y = queue->y;
    dequeue(&queue);
    process_node(game, visited, x, y, c_found, e_found, &queue);
  }
  return (*c_found == game->map->collectibles && *e_found);
}

// Fonction principale pour vérifier le chemin
int check_path(t_game *game)
{
    char **visited;
    int c_found;
    int e_found;
  
    c_found = 0;
    e_found = 0;
    print_game_info(game);
    visited = init_visited(game);
    if (bfs(game, visited, &c_found, &e_found))
    {
      free_visited(visited, game->map->height);
      return (1);
    }
    free_visited(visited, game->map->height);
    ft_putstr("Erreur: Chemin invalide, objets inaccessibles.\n");
    return (0);
  }
