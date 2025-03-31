#include "../Includes/so_long.h"

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
        check_cell(game, new_cell);
        // Efface l'ancienne position du joueur dans la grille
        game->map->grid[game->player.y][game->player.x] = '0';
        // Incrementer le compteur de bas
        game->steps++;
        // MAJ de la position du joueur
        game->player.x = new_x;
        game->player.y = new_y;
        game->map->grid[new_y][new_x] = 'P';
        // MAJ de la position du joueur dans la grille
        game->map->grid[new_y][new_x] = 'P';
        //Redessiner la map
        mlx_clear_window(game->mlx, game->win);
        draw_map(game);
        display_steps(game);
    }
}

void check_cell(t_game *game, char new_cell)
{
    if (new_cell == 'E' && game->map->collectibles > 0)
    {
        ft_putstr("❌ Vous devez ramasser tous les collectibles avant de sortir !\n");
        return; // Bloque le mouvement
    }
    if (new_cell == 'C')
    {
        game->map->collectibles--;
        new_cell = '0'; // Le collectible est collecté
    }
    // Vérifier si le joueur a atteint la sortie
    if (new_cell == 'E' && game->map->collectibles == 0)
    {
        ft_putstr("Félicitations ! Vous avez gagné !\n");
        free_game(game);
    }
}

// Fonction de gestion des inputs
int key_press(int keycode, t_game *game)
{
    if (keycode == 65307) // ESC pour quitter
      free_game(game);
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

void display_steps(t_game *game)
{
    char steps_str[50];
    char num_str[20];

    steps_str[0] = 'P';
    steps_str[1] = 'a';
    steps_str[2] = 's';
    steps_str[3] = ':';
    steps_str[4] = ' ';
    steps_str[5] = '\0';
    // Convertir le nombre de pas en chaîne
    ft_itoa_simple(game->steps, num_str);
    // Concaténer les deux chaînes
    ft_strcat(steps_str, num_str);
    // Afficher le nouveau nombre de pas
    mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, steps_str);
}