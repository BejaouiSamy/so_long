#include "../Includes/so_long.h"

int load_basic_textures(t_game *game, int *width, int *height)
{
    game->textures.wall = mlx_xpm_file_to_image
        (game->mlx, "textures/Purple_Brick.xpm", width, height);
    game->textures.floor = mlx_xpm_file_to_image
        (game->mlx, "textures/wood_floor.xpm", width, height);
    game->textures.player = mlx_xpm_file_to_image
        (game->mlx, "textures/wood_me.xpm", width, height);
    game->textures.gelano = mlx_xpm_file_to_image
        (game->mlx, "textures/wood_gelano.xpm", width, height);
    game->textures.popo = mlx_xpm_file_to_image
        (game->mlx, "textures/wood_popo.xpm", width, height);
    game->textures.glove = mlx_xpm_file_to_image
        (game->mlx, "textures/wood_glove.xpm", width, height);
    game->textures.enemy = mlx_xpm_file_to_image
        (game->mlx, "textures/wood_blob.xpm", width, height);
    
    if (!game->textures.wall || !game->textures.floor || !game->textures.player
            || !game->textures.gelano || !game->textures.popo || !game->textures.enemy)
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

int load_chest_textures(t_game *game, int *width, int *height)
{
    int i;

    char *chest_anim[] = {
        "textures/wood_chest.xpm", "textures/wood_chest1.xpm",
        "textures/wood_chest2.xpm", "textures/wood_chest3.xpm"
    };
    i = 0;
    while (i < 4)
    {
        game->textures.chest_frames[i] = mlx_xpm_file_to_image
            (game->mlx, chest_anim[i], width, height);
        if (!game->textures.chest_frames[i])
            ft_putstr("❌ Erreur: Impossible de charger wood_chest.xpm\n");
        else
            ft_putstr("✅ Texture wood_chest.xpm chargee avec succees\n");
        i++;
    }
    return (1);
}
