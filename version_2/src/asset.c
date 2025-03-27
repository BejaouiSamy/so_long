#include "../Includes/so_long.h"

int load_textures(t_game *game)
{
    int width;
    int height;

    if (!load_basic_textures(game, &width, &height))
        return (0);
    load_exit_textures_part1(game, &width, &height);
    load_chest_textures(game, &width, &height);
    return (1);
}

void draw_map(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (y < game->map->height)
    {
        x = 0;
        while (x < game->map->width)
        {
            if (game->map->grid[y][x] != '1')
                mlx_put_image_to_window(game->mlx, game->win, game->textures.floor, x * 64, y * 64);
            if (game->map->grid[y][x] == '1') // Mur
                mlx_put_image_to_window(game->mlx, game->win, game->textures.wall, x * 64, y * 64);
            else if (game->map->grid[y][x] == 'C') // Collectible
                mlx_put_image_to_window(game->mlx, game->win, game->textures.chest_frames[game->chest_current_frame], x * 64, y * 64);
            else if (game->map->grid[y][x] == 'E') // Sortie
                mlx_put_image_to_window(game->mlx, game->win, game->textures.exit_frames[game->exit_current_frame], x * 64, y * 64);  // Première frame de l'animation de la sortie
            else if (game->map->grid[y][x] == 'P') // Joueur
                mlx_put_image_to_window(game->mlx, game->win, game->textures.player, x * 64, y * 64);
            else if (game->map->grid[y][x] == 'G') // gelano
                mlx_put_image_to_window(game->mlx, game->win, game->textures.gelano, x * 64, y * 64);
            else if (game->map->grid[y][x] == 'O') // popo 
                mlx_put_image_to_window(game->mlx, game->win, game->textures.popo, x * 64, y * 64);
            else if (game->map->grid[y][x] == 'T') // glove
                mlx_put_image_to_window(game->mlx, game->win, game->textures.glove, x * 64, y * 64);
            else if (game->map->grid[y][x] == 'X')
                mlx_put_image_to_window(game->mlx, game->win, game->textures.enemy, x * 64, y * 64);
            x++;
        }
        y++;
    }
}

#include <time.h>
int animate_exit(t_game *game)
{
    static clock_t last_time = 0;
    clock_t current_time = clock();
    int x;
    int y;
    // Changer de frame toutes les 500 millisecondes (0.5 secondes)
    if ((current_time - last_time) < (CLOCKS_PER_SEC / 20))
        return (0);
    last_time = current_time;
    // Trouver les coordonnées de la sortie dans la map
    y = 0;
    while (y < game->map->height)
    {
        x = 0;
        while (x < game->map->width)
        {
            if (game->map->grid[y][x] == 'E')
            {
                game->exit_current_frame = (game->exit_current_frame + 1) % 6;
                // Redessiner uniquement la sortie
                mlx_put_image_to_window(game->mlx, game->win, game->textures.floor, x * 64, y * 64);
                mlx_put_image_to_window(game->mlx, game->win,
                game->textures.exit_frames[game->exit_current_frame],
                x * 64, y * 64);
                return (0);
            }
            x++;
        }
        y++;
    }
    return (0);
}

int animate_chest(t_game *game)
{
    static clock_t last_time = 0;
    clock_t current_time = clock();
    int x;
    int y;

    // Changer de frame toutes les 500 millisecondes (0.5 secondes)
    if ((current_time - last_time) < (CLOCKS_PER_SEC / 10))
        return (0);
    last_time = current_time;
    // Trouver les coordonnées de la sortie dans la map
    y = 0;
    while (y < game->map->height)
    {
        x = 0;
        while (x < game->map->width)
        {
            if (game->map->grid[y][x] == 'C')
            {
                game->chest_current_frame = (game->chest_current_frame + 1) % 4;
                // Redessiner uniquement la sortie
                mlx_put_image_to_window(game->mlx, game->win, game->textures.floor, x * 64, y * 64);
                mlx_put_image_to_window(game->mlx, game->win,
                game->textures.chest_frames[game->chest_current_frame],
                x * 64, y * 64);
                return (0);
            }
            x++;
        }
        y++;
    }
    return (0);
}