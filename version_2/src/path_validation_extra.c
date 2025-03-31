#include "../Includes/so_long.h"

// Vérifier si une position est valide
int is_valid_position(t_map *map, int x, int y, char **visited)
{
    return (x >= 0 && x < map->width && y >= 0 && y < map->height &&
            map->grid[y][x] != '1' && visited[y][x] == 0);
}

void print_game_info(t_game *game)
{
    ft_putstr("Dimensions de la carte: ");
    ft_putnbr(game->map->width);
    ft_putstr(" x ");
    ft_putnbr(game->map->height);
    ft_putstr("\n");
    ft_putstr("Position du joueur: (");
    ft_putnbr(game->player.x);
    ft_putstr(", ");
    ft_putnbr(game->player.y);
    ft_putstr(")\n");
    ft_putstr("Nombre de sorties attendus: ");
    ft_putnbr(game->map->exit);
    ft_putstr("\n");
}

// Traite un nœud de la file d'attente lors du parcours BFS
void process_node(t_game *game, char **visited, int x, int y, int *c_found, int *e_found, t_queue **queue)
{
  int i;
  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};

  if (game->map->grid[y][x] == 'C')
    (*c_found)++;
  if (game->map->grid[y][x] == 'E')
    (*e_found) = 1;
  i = -1;
  while (++i < 4)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (is_valid_position(game->map, nx, ny, visited))
    {
      enqueue(queue, nx, ny);
      visited[ny][nx] = 1;
    }
  }
}


// Initialise le tableau de visite
char **init_visited(t_game *game)
{
    int x;
    int y;
    char **visited;
  
    visited = malloc(sizeof(char *) * game->map->height);
    y = -1;
    while (++y < game->map->height)
    {
      visited[y] = malloc(game->map->width);
      x = -1;
      while (++x < game->map->width)
        visited[y][x] = 0;
    }
    return (visited);
}