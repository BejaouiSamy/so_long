#include <unistd.h>
#include <string.h>

int *chest_anim[] = {
    "textures/wood_chest.xpm", "textures/wood_chest.xpm",
    "textures/wood_chest.xpm"
}

int load_chest_textures(t_game *game, int *width, int *height)
{
    int i;

    char *chest_anim[] = {
        "textures/wood_chest.xpm", "textures/wood_chest.xpm",
        "textures/wood_chest.xpm"
    };
    i = 0;
    while (i < 3)
    {
        game->textures.chest_frames[i] = mlx_xpm_file_to_image
            (game->mlx, exit_textures[i], width, height);
        if (!game->textures.chest_frames[i])
            ft_putstr("❌ Erreur: Impossible de charger wood_chest.xpm\n");
        else
            ft_putstr("✅ Texture wood_chest.xpm chargee avec succees\n");
        i++;
    }
    return (1);
}

#include <time.h>
int animate_chest(t_game *game)
{
    static clock_t last_time = 0;
    clock_t current_time = clock();
    int x;
    int y;
    // Changer de frame toutes les 500 millisecondes (0.5 secondes)
    if ((current_time - last_time) < (CLOCKS_PER_SEC / 20))
        return (0);
    last_time = current_time;
    // Trouver les coordonnées de la sortie dans la map
    y = 0;
    while (y < game->map->height)
    {
        x = 0;
        while (x < game->map->width)
        {
            if (game->map->grid[y][x] == 'C')
            {
                game->exit_current_frame = (game->chest_current_frame + 1) % 3;
                // Redessiner uniquement la sortie
                mlx_put_image_to_window(game->mlx, game->win, game->textures.collectible, x * 64, y * 64);
                mlx_put_image_to_window(game->mlx, game->win,
                game->textures.chest_frames[game->echest_current_frame],
                x * 64, y * 64);
                return (0);
            }
            x++;
        }
        y++;
    }
    return (0);
}

int ft_strcmp(char *s1, char *s2)
{
    while (*s1 == *s2 && *s1)
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
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

int main(int ac, char **av)
{
    if (ac == 2)
    {   
        if (check_file_extension(av[1]))
            write(1, "everything is good", 18);
        else
            write(1, "Error", 5);
    }
}