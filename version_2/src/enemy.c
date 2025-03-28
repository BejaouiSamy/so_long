#include "../Includes/so_long.h"

void move_enemies(t_game *game)
{
    int new_x;

    // Décrémente le timer et ne bouge l'ennemi que lorsqu'il atteint 0
    if (game->enemy_timer > 0)
    {
        game->enemy_timer--;
        return;
    }
    
    // Réinitialise le timer après chaque mouvement (ajuste la valeur pour changer la vitesse)
    game->enemy_timer = 3500; // Par exemple, l'ennemi bouge toutes les 10 frames

    new_x = game->enemy.x + game->enemy.dir;
    // Vérifie si l'ennemi reste dans les limites de la map
    if (new_x >= 0 && new_x < game->map->width)
    {
        // Vérifie si l'ennemi peut avancer (évite les murs '1' et les collectibles 'C')
        if (game->map->grid[game->enemy.y][new_x] != '1')
        {
            // Met à jour la position dans la grille
            game->map->grid[game->enemy.y][game->enemy.x] = '0';  // Libère la case actuelle
            game->enemy.x = new_x;
            game->map->grid[game->enemy.y][game->enemy.x] = 'X';  // Marque la nouvelle position
        }
        else
            // Change de direction en cas d'obstacle
            game->enemy.dir *= -1;
    }
    else
        // Change de direction si hors limites
        game->enemy.dir *= -1;
    // Vérifie la collision avec le joueur
    check_collision(game);
    draw_map(game);
}

void check_collision(t_game *game)
{
    if (game->enemy.x == game->player.x && game->enemy.y == game->player.y)
    {
        ft_putstr("💀 Game Over !\n");
        free_game(game);
    }
}

void add_enemy(t_game *game, int x, int y)
{
    game->enemy.x = x;
    game->enemy.y = y;
    game->enemy.dir = 1; // Commence en allant à droite
    game->enemy_timer = 3500;
}