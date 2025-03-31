#include "../Includes/so_long.h"

void free_textures(t_game *game)
{

    if (game->textures.wall)
        mlx_destroy_image(game->mlx, game->textures.wall);
    if (game->textures.floor)
        mlx_destroy_image(game->mlx, game->textures.floor);
    if (game->textures.collectible)
        mlx_destroy_image(game->mlx, game->textures.collectible);
    if (game->textures.player)
        mlx_destroy_image(game->mlx, game->textures.player);
    if (game->textures.gelano)
        mlx_destroy_image(game->mlx, game->textures.gelano);
    if (game->textures.popo)
        mlx_destroy_image(game->mlx, game->textures.popo);
    if (game->textures.glove)
        mlx_destroy_image(game->mlx, game->textures.glove);
    free_loop(game);
}

void free_loop(t_game *game)
{
    int i;

    i = 0;
    while (i < 6)
    {
        if (game->textures.exit_frames[i])
            mlx_destroy_image(game->mlx, game->textures.exit_frames[i]);
        i++;
    }
    i = 0;
    while (i < 4)
    {
        if (game->textures.chest_frames[i])
            mlx_destroy_image(game->mlx, game->textures.chest_frames[i]);
        i++;
    }
}

int free_game(t_game *game)
{
    if (!game)
        return (0);
    
    if (game->map)
        free_map(game->map);
    
    free_textures(game);

    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
    exit(0);
}

void free_map(t_map *map)
{
    int i;

    if (!map)
        return;
    i = 0;
    if (map->grid)
    {
        while(i < map->height)
        {
            free(map->grid[i]);
            i++;
        }
        free(map->grid);
    }
    free(map);
}

// Libère la mémoire du tableau de visite
void free_visited(char **visited, int height)
{
    int y;
  
    y = -1;
    while (++y < height)
      free(visited[y]);
    free(visited);
  }