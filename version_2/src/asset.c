#include "../Includes/so_long.h"

int load_textures(t_game *game)
{
    int width;
    int height;
    //int i;
    int j;

    // Charger les textures du jeu
    game->textures.wall = mlx_xpm_file_to_image(game->mlx,
            "textures/Purple_Brick.xpm", &width, &height);
    game->textures.player = mlx_xpm_file_to_image(game->mlx,
            "textures/wood_me.xpm", &width, &height);
    game->textures.collectible = mlx_xpm_file_to_image(game->mlx,
            "textures/cheese_burger.xpm", &width, &height);
    game->textures.floor = mlx_xpm_file_to_image(game->mlx,
            "textures/wood_floor.xpm", &width, &height);
    if (!game->textures.collectible)
        ft_putstr("❌ ERREUR: Impossible de charger cheese-burger.xpm\n");
    else
        ft_putstr("✅ Texture cheese-burger.xpm chargée avec succès\n");

    char *exit_textures[] = {
        "textures/portal/wood_portal.xpm", "textures/portal/wood_portal1.xpm",
        "textures/portal/wood_portal2.xpm", "textures/portal/wood_portal3.xpm",
        "textures/portal/wood_portal4.xpm", "textures/portal/wood_portal5.xpm"
    };
    // chargement plusieurs textures de sortie
    j = 0;
    while(j < 6)
    {
        game->textures.exit_frames[j] = mlx_xpm_file_to_image
            (game->mlx, exit_textures[j], &width, &height);
        if (!game->textures.exit_frames[j])
            ft_putstr("❌ ERREUR: Impossible de charger portal.xpm\n");
        else
            ft_putstr("✅ Texture portal.xpm chargée avec succès\n");
        j++;
    }

    // Verifier si toutes les textures ont ete chargees
    if(!game->textures.wall || !game->textures.floor
            || !game->textures.collectible || !game->textures.player)
    {
        ft_putstr("Impossible de charger les textures");
        return (0);
    }

    // Vérification des textures de sortie
    j = 0;
    while (j < 6)
    {
        if (!game->textures.exit_frames[j])
        {
            ft_putstr("Impossible de charger la texture de sortie ");
            ft_putnbr(j + 1);
            ft_putstr("\n");
            return (0);
        }
        j++;
    }
    return (1);
}

void draw_map(t_game *game)
{
    int x, y;

    y = 0;
    while (y < game->map->height)
    {
        x = 0;
        while (x < game->map->width)
        {
            // Dessiner le sol partout
            if (game->map->grid[y][x] != '1')
                mlx_put_image_to_window(game->mlx, game->win, game->textures.floor, x * 64, y * 64);
            // Dessiner les éléments spécifiques
            if (game->map->grid[y][x] == '1') // Mur
                mlx_put_image_to_window(game->mlx, game->win, game->textures.wall, x * 64, y * 64);
            else if (game->map->grid[y][x] == 'C') // Collectible
                mlx_put_image_to_window(game->mlx, game->win, game->textures.collectible, x * 64, y * 64);
            else if (game->map->grid[y][x] == 'E') // Sortie
                mlx_put_image_to_window(game->mlx, game->win, game->textures.exit_frames[game->exit_current_frame], x * 64, y * 64);  // Première frame de l'animation de la sortie
            else if (game->map->grid[y][x] == 'P') // Joueur
                mlx_put_image_to_window(game->mlx, game->win, game->textures.player, x * 64, y * 64);
            x++;
        }
        y++;
    }
}

#include <time.h>
int animate_exit(t_game *game)
{
    static clock_t last_time = 0;
    clock_t current_time = clock();
    int x, y;
    
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
            if (game->map->grid[y][x] == 'E')
            {
                game->exit_current_frame = (game->exit_current_frame + 1) % 6;
                // Redessiner uniquement la sortie
                mlx_put_image_to_window(game->mlx, game->win, game->textures.floor, x * 64, y * 64);
                mlx_put_image_to_window(game->mlx, game->win,
                game->textures.exit_frames[game->exit_current_frame],
                x * 64, y * 64);
                return (0);
            }
            x++;
        }
        y++;
    }
    return (0);
}