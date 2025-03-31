#include "../Includes/so_long.h"

int g_chest_counter = 0;
int g_exit_counter = 0;

int animate_exit(t_game *game, int *exit_counter)
{
    // Changer de frame tous les 20 appels de la fonction
    if (*exit_counter % 4500 != 0)
    {
        *exit_counter += 1;
        return (0);
    }
    *exit_counter += 1;

    game->exit_current_frame = (game->exit_current_frame + 1) % 6;
    draw_map(game);

    return (0);
}

int animate_chest(t_game *game, int *frame_counter)
{
    // Changer de frame tous les 20 appels de la fonction
    if (*frame_counter % 10000 != 0)
    {
        *frame_counter += 1;
        return (0);
    }
    *frame_counter += 1;

    game->chest_current_frame = (game->chest_current_frame + 1) % 4;
    draw_map(game);

    return (0);
}

int load_exit_textures(t_game *game, int *width, int *height)
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