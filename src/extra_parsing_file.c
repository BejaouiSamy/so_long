#include "../Includes/so_long.h"

int	check_horizontal_walls(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->map->width)
	{
		if (game->map->grid[0][x] != '1')
		{
			ft_putstr("Erreur: La carte n'est pas entourée de murs (ligne 1, position ");
			ft_putnbr(x + 1);
			ft_putstr(")\n");
			return (0);
		}
		if (game->map->grid[game->map->height - 1][x] != '1')
		{
			ft_putstr("Erreur: La carte n'est pas entourée de murs (dernière ligne, position ");
			ft_putnbr(x + 1);
			ft_putstr(")\n");
			return (0);
		}
		x++;
	}
	return (1);
}

int	check_vertical_walls(t_game *game)
{
	int	y;

	y = 0;

	while (y < game->map->height)
	{
		if (game->map->grid[y][0] != '1')
		{
			ft_putstr("Erreur: La carte n'est pas entourée de murs (colonne gauche, ligne ");
			ft_putnbr(y + 1);
			ft_putstr(")\n");
			return (0);
		}
		if (game->map->grid[y][game->map->width - 1] != '1')
		{
			ft_putstr("Erreur: La carte n'est pas entourée de murs (colonne droite, ligne ");
			ft_putnbr(y + 1);
			ft_putstr(")\n");
			return (0);
		}
		y++;
	}
	return (1);
}

int	read_map_file(t_game *game, int fd)
{
	char	*line;

	while ((line = get_next_line(fd)) != NULL)
	{
		if (!add_line_to_map(game, line))
		{
			free(line);
			free_map(game->map);
			return (0);
		}
		free(line);
	}
	return (1);
}

int	init_map_structures(t_game *game)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map)
	{
		ft_putstr("Erreur d'allocation memoire");
		return(0);
	}
	game->map->width = 0;
	game->map->height = 0;
	game->map->collectibles = 0;
	game->map->gelano = 0;
	game->map->glove = 0;
	game->map->popo = 0;
	game->map->exit = 0;
	game->map->player = 0;
	game->map->grid = NULL;
	game->steps = 0;
	return (1);
}
