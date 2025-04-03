#include "../Includes/so_long.h"

int	check_file_extension(char *str)
{
	int	i;

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

int	game_loop(t_game *game)
{
	move_enemies(game);
	animate_chest(game, &g_chest_counter);
	animate_exit(game, &g_exit_counter);
	display_steps(game);
	return (0);
}

int	initialize_game(t_game *game, char *map_path)
{
	ft_memset(game, 0, sizeof(t_game));
	game->mlx = mlx_init();
	if (!game->mlx)
		return (handle_error("Impossible d'initialiser mlx\n", game));
	if (!parse_map(game, map_path) || !load_textures(game))
		return (handle_error("Erreur de parsing ou de textures\n", game));
	game->win = mlx_new_window(game->mlx, game->map->width * 64, game->map->height * 64, "so_long");
	if (!game->win)
		return (handle_error("Impossible de créer la fenêtre\n", game));
	return (0);
}

int	handle_error(char *msg, t_game *game)
{
	ft_putstr(msg);
	if (game)
		free_game(game);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (handle_error("Usage: ./so_long map.ber\n", NULL));
	if (!check_file_extension(av[1]))
		return (handle_error("Le fichier doit avoir l'extension .ber\n", NULL));
	if (initialize_game(&game, av[1]))
		return (1);
	draw_map(&game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 17, 0, free_game, &game);
	mlx_loop(game.mlx);
	free_game(&game);
	return (0);
}
