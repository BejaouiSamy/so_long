#include "../Includes/so_long.h"

void quit_game(t_game *game)
{
    mlx_destroy_window(game->mlx, game->win);
    mlx_destroy_display(game->mlx);
    free(game->mlx);
    free_game(game);
    exit(0);
}

// Fonction pour deplacer le joueur
void move_player(t_game *game, int dx, int dy)
{
    int new_x;
    int new_y;
    char new_cell;

    new_x = game->player.x + dx;
    new_y = game->player.y + dy;

    // Verifie si le mouvement est valide
    if (game->map->grid[new_y][new_x] != '1')
    {
        new_cell = game->map->grid[new_y][new_x];
        // Efface l'ancienne position du joueur dans la grille
        game->map->grid[game->player.y][game->player.x] = '0';
        // MAJ de la position du joueur
        game->player.x = new_x;
        game->player.y = new_y;
        // Si la nouvelle case est un collectible
        if (new_cell == 'C')
        {
            game->map->collectibles--;
            new_cell = '0'; // Le collectible est collecté
        }
        // Vérifier si le joueur a atteint la sortie
        if (new_cell == 'E' && game->map->collectibles == 0)
        {
            ft_putstr("Félicitations ! Vous avez gagné !\n");
            quit_game(game);
        }
        // MAJ de la position du joueur dans la grille
        game->map->grid[new_y][new_x] = 'P';
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
    else if (keycode == 100)
        move_player(game, 1, 0); // Deplacer a droite
    else if (keycode == 115)
        move_player(game, 0, 1); // Deplacer en bas
    return (0);
}