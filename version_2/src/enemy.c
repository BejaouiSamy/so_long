#include "../Includes/so_long.h"

void move_enemies(t_game *game)
{
    t_enemy *enemy;
    int new_x;
    
    enemy = game->enemies;
    while (enemy)
    {
        new_x = enemy->x + enemy->dir;
        
        // Vérifie si l'ennemi reste dans les limites de la map
        if (new_x >= 0 && new_x < game->map->width)
        {
            // Vérifie si l'ennemi peut avancer (évite les murs '1' et les collectibles 'C')
            if (game->map->grid[enemy->y][new_x] == '0')
            {
                // Met à jour la position dans la grille
                game->map->grid[enemy->y][enemy->x] = '0';  // Libère la case actuelle
                enemy->x = new_x;
                game->map->grid[enemy->y][enemy->x] = 'X';  // Marque la nouvelle position
                enemy->dir *= 1;
            }
            else
                // Change de direction en cas d'obstacle
                enemy->dir *= -1;
        }
        else
            // Change de direction si hors limites
            enemy->dir *= -1;
        // Vérifie la collision avec le joueur
        if (enemy->x == game->player.x && enemy->y == game->player.y)
        {
            ft_putstr("💀 Tu as été touché par un ennemi ! Game Over !\n");
            free_game(game);
            exit(0);  // Quitte le programme après le game over
        }
        
        enemy = enemy->next;
    }
}

void check_collision(t_game *game)
{
    t_enemy *enemy = game->enemies;
    while (enemy)
    {
        if (enemy->x == game->player.x && enemy->y == game->player.y)
        {
            ft_putstr("💀 Game Over !\n");
            free_game(game);
        }
        enemy = enemy->next;
    }
}

void add_enemy(t_game *game, int x, int y)
{
    t_enemy *enemy;
    
    enemy = new_enemy(x, y);
    if (!enemy)
    {
        ft_putstr("❌ Erreur d'allocation mémoire pour un ennemi\n");
        return;
    }
    enemy->next = game->enemies; // Ajoute à la liste chaînée
    game->enemies = enemy;
}

t_enemy *new_enemy(int x, int y)
{
    t_enemy *enemy;
    
    enemy = malloc(sizeof(t_enemy));
    if (!enemy)
        return (NULL);
    enemy->x = x;
    enemy->y = y;
    enemy->dir = 1; // Commence en allant à droite
    enemy->next = NULL;
    return (enemy);
}