#include "../Includes/so_long.h"

void free_textures(t_game *game)
{
    int i;

    if (game->textures.wall)
        mlx_destroy_image(game->mlx, game->textures.wall);
    if (game->textures.floor)
        mlx_destroy_image(game->mlx, game->textures.floor);
    if (game->textures.collectible)
        mlx_destroy_image(game->mlx, game->textures.collectible);
    if (game->textures.player)
        mlx_destroy_image(game->mlx, game->textures.player);

    // Libérer les frames de l'animation de sortie

    i = 0;
    while (i < 6) // 6 frames pour l'animation de la sortie
    {
        if (game->textures.exit_frames[i])
            mlx_destroy_image(game->mlx, game->textures.exit_frames[i]);
        i++;
    }
}

int close_window(t_game *game)
{
    free_game(game);
    exit(0);
}

/*int game_loop(t_game *game)
{
    // Appeler les différentes animations
    //animate_player(game);
    animate_exit(game);
    
    return (0);
}*/


#include "../Includes/so_long.h"

int main(int argc, char **argv)
{
    t_game game;
    
    // Vérifier les arguments
    if (argc != 2)
    {
        ft_putstr("Usage: ./so_long map.ber\n");
        return (1);
    }
    
    // Vérifier l'extension du fichier
    //if (!check_file_extension(argv[1], ".ber"))
    //{
    //    ft_putstr("Le fichier doit avoir l'extension .ber\n");
    //    return (1);
    //}
    
    // Initialiser la structure de jeu
    ft_memset(&game, 0, sizeof(t_game));
    
    // Initialiser la connexion mlx
    game.mlx = mlx_init();
    if (!game.mlx)
    { 
        ft_putstr("Impossible d'initialiser mlx\n");
        return (1);
    }
    
    // Parser la map
    if (!parse_map(&game, argv[1]))
    {
        free_game(&game);
        return (1);
    }
    
    // Créer la fenêtre
    game.win = mlx_new_window(game.mlx, game.map->width * 64, game.map->height * 64, "so_long");
    if (!game.win)
    {
        ft_putstr("Impossible de créer la fenêtre\n");
        free_game(&game);
        return (1);
    }
    
    // Charger les textures
    if (!load_textures(&game))
    {
        free_game(&game);
        return (1);
    }
    // Dessiner la map initiale
    draw_map(&game);
    
    // Définir les hooks pour gérer les événements
    mlx_loop_hook(game.mlx, animate_exit, &game);
    mlx_hook(game.win, 2, 1L<<0, key_press, &game); // Gestion des touches
    mlx_hook(game.win, 17, 0, close_window, &game); // Fermeture de la fenêtre
    
    // Lancer la boucle d'événements
    mlx_loop(game.mlx);

    // Libérer la mémoire après la boucle (optionnel si free_game est déjà appelé par close_window)
    free_game(&game);
    
    return (0);
}
