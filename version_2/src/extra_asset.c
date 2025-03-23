#include "../Includes/so_long.h"

int load_basic_textures(t_game *game, int *width, int *height)
{
    game->textures.wall = mlx_xpm_file_to_image
        (game->mlx, "textures/Purple_Brick.xpm", width, height);
    game->textures.floor = mlx_xpm_file_to_image
        (game->mlx, "textures/wood_floor.xpm", width, height);
    game->textures.player = mlx_xpm_file_to_image
        (game->mlx, "textures/wood_me.xpm", width, height);
    game->textures.collectible = mlx_xpm_file_to_image
        (game->mlx, "textures/cheese_burger.xpm", width, height);

    if (!game->textures.wall || !game->textures.floor || !game->textures.player
        || !game->textures.collectible)
    {
        ft_putstr("❌ Impossible de charger les textures\n");
        return (0);
    }
    return (1);
}

int load_exit_textures_part1(t_game *game, int *width, int *height)
{
    int i;

    char *exit_textures[] = {
        "textures/portal/wood_portal.xpm", "textures/portal/wood_portal1.xpm",
        "textures/portal/wood_portal2.xpm", "textures/portal/wood_portal3.xpm",
        "textures/portal/wood_portal4.xpm", "textures/portal/wood_portal5.xpm"  
    };
    i = 0;
    while (i < 6)
    {
        game->textures.exit_frames[i] = mlx_xpm_file_to_image
            (game->mlx, exit_textures[i], width, height);
        if (!game->textures.exit_frames[i])
            ft_putstr("❌ Erreur: Impossible de charger portal.xpm\n");
        else
            ft_putstr("✅ Texture portal.xpm chargee avec succees\n");
        i++;
    }
    return (1);
}

