#include "../Includes/so_long.h"

// Fonction pour deplacer le joueur
void move_player(t_game *game, int dx, int dy)
{
    int new_x;
    int new_y;

    new_x = game->player.x + dx;
    new_y = game->player.y + dy;

    // Verifie si le mouvement est valide
    if (game->map->grid[new_y][new_x] != '1') // '1' = mur
    {
        // MAJ de la position du joueur
        game->player.x = new_x;
        game->player.y = new_y;
        //Redessiner la map
        mlx_clear_window(game->mlx, game->win);
        draw_map(game);
    }
}

// Fonction de gestion des inputs
int key_press(int keycode, t_game *game)
{
    if (keycode == 65307) // ESC pour quitter
    {
        mlx_destroy_window(game->mlx, game->win);
        mlx_destroy_display(game->mlx);
        free(game->mlx);
        free_game(game);
        exit(0);
    }
    if (keycode == 97)
        move_player(game, -1, 0); // Deplacer a gauche
    else if (keycode == 119)
        move_player(game, 0, -1); // Deplacer en haut
    else if (keycode == 115)
        move_player(game, 1, 0); // Deplacer a droite
    else if (keycode == 100)
        move_player(game, 0, 1); // Deplacer en bas
    return (0);
}

void collect_item(t_game *game)
{
    if (game->map->grid[game->player.y][game->player.x] == 'C')
    {
        game->map->collectibles--;
        game->map->grid[game->player.y][game->player.x] = '0'; // Enleve le collectible
    }
    // Si tous les collectibles sont ramasses, change l'etat de la sortie
    if (game->map->collectibles == 0)
    {
        // MAJ de la sortie pour qu'elle devienne accessible
        game->map->exit = 1;
    }
}