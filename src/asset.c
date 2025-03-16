#include "../Includes/so_long.h"

int load_textures(t_game *game)
{
    int width;
    int height;
    int i;

    // Charger les textures du jeu
    game->textures.wall = mlx_xpm_file_to_image(game->mlx,
            "textures/backroom_wall.xpm", &width, &height);
    game->textures.floor = mlx_xpm_file_to_image(game->mlx,
            "textures/backroom_floor.xpm", &width, &height);
    game->textures.collectible = mlx_xpm_file_to_image(game->mlx,
            "textures/cheese-burger.xpm", &width, &height);
    if (!game->textures.collectible)
        ft_putstr("❌ ERREUR: Impossible de charger cheese-burger.xpm\n");
    else
        ft_putstr("✅ Texture cheese-burger.xpm chargée avec succès\n");
    game->textures.exit = mlx_xpm_file_to_image(game->mlx,
            "textures/mic.xpm", &width, &height);
    if (!game->textures.exit)
        ft_putstr("❌ ERREUR: Impossible de charger mic.xpm\n");
    else
        ft_putstr("✅ Texture mic.xpm chargée avec succès\n");

    ft_putstr("Taille texture mur : ");
    ft_putnbr(width);
    ft_putstr(" x ");
    ft_putnbr(height);
    ft_putstr("\n");

    // Chargement de plusieurs textures
    char *player_textures[] = {
        "textures/doom_1.xpm", "textures/doom_2.xpm", "textures/doom_3.xpm",
        "textures/doom_4.xpm", "textures/doom_5.xpm", "textures/doom_6.xpm",
        "textures/doom_7.xpm", "textures/doom_8.xpm", "textures/doom_9.xpm",
        "textures/doom_10.xpm"
    };
    i = 0;
    while(i < 10)
    {
        game->textures.player_frames[i] = mlx_xpm_file_to_image
            (game->mlx, player_textures[i], &width, &height);
        if (!game->textures.player_frames[i])
            ft_putstr("❌ ERREUR: Impossible de charger doom.xpm\n");
        else
            ft_putstr("✅ Texture dooom.xpm chargée avec succès\n");
        i++;
    }
    // Verifier si toutes les textures ont ete chargees
    if(!game->textures.wall || !game->textures.floor
            || !game->textures.collectible || !game->textures.exit)
    {
        ft_putstr("Impossible de charger les textures");
        return (0);
    }
    i = 0;
    while (i < 10)
    {
        if (!game->textures.player_frames[i])
        {
            ft_putstr("Impossible de charger la frame du joueur");
            ft_putnbr(i + 1);
            ft_putstr("\n");
            return(0);
        }
        i++;
    }
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
            // Dessiner le sol partout
            mlx_put_image_to_window(game->mlx
                    , game->win, game->textures.floor, x*32, y * 32);
            // Dessiner les elements specifiques
            if (game->map->grid[y][x] == '1')
                mlx_put_image_to_window(game->mlx
                    , game->win, game->textures.wall, x * 32, y * 32);
            else if (game->map->grid[y][x] == 'C')
                mlx_put_image_to_window(game->mlx
                    , game->win, game->textures.collectible, x * 32, y * 32);
            else if (game->map->grid[y][x] == 'E')
                mlx_put_image_to_window(game->mlx
                    , game->win, game->textures.exit, x * 32, y * 32);
            else if (game->map->grid[y][x] == 'P')
            {
                game->player.x = x;
                game->player.y = y;
                mlx_put_image_to_window(game->mlx
                    , game->win, game->textures.player_frames[game->current_frame], x * 32, y * 32);
            }
            x++;
        }
        y++;
    }
}

int animate_player(t_game *game)
{
    static int frame_delay;
    
    frame_delay = 0;
    game->current_frame = 0;
    // Limiter la vitesse de l'animation (change d'image toutes les 10 itérations)
    if (frame_delay++ < 10)
        return (0);
    frame_delay = 0;

    game->current_frame = (game->current_frame + 1) % 10;  // Passe à la frame suivante
    // Efface uniquement l'ancienne position du joueur et redessine
    mlx_put_image_to_window(game->mlx, game->win, game->textures.floor, game->player.x * 32, game->player.y * 32);
    mlx_put_image_to_window(game->mlx, game->win, game->textures.player_frames[game->current_frame], game->player.x * 32, game->player.y * 32);

    return (0);
}