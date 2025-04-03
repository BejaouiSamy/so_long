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

void tab_texture(t_game *game)
{
    int i;

    i = 0;
    game->num_collectible_texture = 4;
    game->collectibles_tab = malloc(sizeof(void *) *game->num_collectible_texture);
    if (!game->collectibles_tab)
        handle_error("Error memory allocation \n", game);
    game->tab_texture[0] = mlx_xpm_file_to_image
        (game->mlx, "textures/glove.xpm", width, height);
    game->tab_texture[1] = mlx_xpm_file_to_image
        (game->mlx, "textures/popo.xpm", width, height);
    game->tab_texture[2] = mlx_xpm_file_to_image
        (game->mlx, "textures/gelano.xpm", width, height);
    game->tab_texture[0] = mlx_xpm_file_to_image
        (game->mlx, load_chest_textures, width, height);
    while (i < game->num_collectible_texture)
    {
        if (!game->tab_texture[i])
        {
            handle_error("Error textures collectible loading\n", game);
        }
        i++;
    }
}

    while (y < game->map->height)
    {
        while (i < game->map->width)
        {
            if (game->map[y][x] == 'C')
            {
                game->map->collectibles++;
            }
            i++;
        }
        x++;
    }

    void declar_collectibles(t_game *game)
    {
        int x;
        int y;

        game->collectibles_on_map = malloc(sizeof(t_collectible_instance) * game->collectible_count);
        if (!game->collectibles_on_map)
            exit_error("Erreur malloc instances collectibles", game);

        int current_collectible_index = 0;
        y = 0;
        while (y < game->map->height)
        {
            x = 0;
            while (x < game->map->width)
            {
                if (game->map[y][x] == 'C')
                {
                    ame->collectibles_on_map[current_collectible_index].x = x;
                    game->collectibles_on_map[current_collectible_index].y = y;
                    // Assignation de la texture (ex: cyclique)
                    game->collectibles_on_map[current_collectible_index].texture_index =
                        current_collectible_index % game->num_collectible_textures;
                    current_collectible_index++;
                }
                x++;
            }
            y++;
        }
    }