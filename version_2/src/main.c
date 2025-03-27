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
    if (game->textures.gelano)
        mlx_destroy_image(game->mlx, game->textures.gelano);
    if (game->textures.popo)
        mlx_destroy_image(game->mlx, game->textures.popo);
    if (game->textures.glove)
        mlx_destroy_image(game->mlx, game->textures.glove);
    // Libérer les frames de l'animation de sortie
    i = 0;
    while (i < 6) // 6 frames pour l'animation de la sortie
    {
        if (game->textures.exit_frames[i])
            mlx_destroy_image(game->mlx, game->textures.exit_frames[i]);
        i++;
    }
    i = 0;
    while (i < 4) // 4 frames pour l'animation des collectibles
    {
        if (game->textures.chest_frames[i])
            mlx_destroy_image(game->mlx, game->textures.chest_frames[i]);
        i++;
    }
}

int check_file_extension(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    while (i >= 0 && str[i] != '.')
        i--;
    if (i <= 0)
        return (0);
    if (ft_strcmp(str + i, ".ber") == 0)
        return (1);
    return (0);
}

int game_loop(t_game *game)
{
    animate_chest(game);
    animate_exit(game);
    move_enemies(game);
    return (0);
}

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
    if (!check_file_extension(argv[1]))
    {
        ft_putstr("Le fichier doit avoir l'extension .ber\n");
        return (1);
    }
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
        free_game(&game);
    // Créer la fenêtre
    game.win = mlx_new_window(game.mlx, game.map->width * 64, game.map->height * 64, "so_long");
    if (!game.win)
    {
        ft_putstr("Impossible de créer la fenêtre\n");
        free_game(&game);
    }
    // Charger les textures
    if (!load_textures(&game))
        free_game(&game);
    // Dessiner la map initiale
    draw_map(&game);
    // Définir les hooks pour gérer les événements
    mlx_loop_hook(game.mlx, game_loop, &game);
    mlx_hook(game.win, 2, 1L<<0, key_press, &game); // Gestion des touches
    mlx_hook(game.win, 17, 0, free_game, &game); // Fermeture de la fenêtre
    // Lancer la boucle d'événements
    mlx_loop(game.mlx);
    // Libérer la mémoire après la boucle
    free_game(&game);
    return (0);
}
