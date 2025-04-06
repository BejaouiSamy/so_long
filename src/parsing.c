/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:16:10 by bsamy             #+#    #+#             */
/*   Updated: 2025/04/05 21:14:17 by bsamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	count_map_elements(t_game *game, char *line, int y)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'C'
			|| line[i] == 'T'
			|| line[i] == 'G'
			|| line[i] == 'O')
			count_collectibles(game, line[i]);
		else
			process_map_element(game, line[i], i, y);
		i++;
	}
}

int	checks_wall(t_game *game)
{
	if (!check_horizontal_walls(game))
		return (0);
	if (!check_vertical_walls(game))
		return (0);
	return (1);
}

int	parse_map(t_game *game, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error: Impossible d'ouvrir la map\n");
		return (0);
	}
	if (!init_map_structures(game))
	{
		close(fd);
		return (0);
	}
	if (!read_map_file(game, fd))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (validate_map(game));
}

int	add_line_to_map(t_game *game, char *line)
{
	int		len;
	char	**new_grid;
	int		check_result;

	new_grid = NULL;
	check_result = check_line_validity(game, line, &len);
	if (check_result != 2)
		return (check_result);
	if (!allocate_new_grid(game, line, &new_grid))
		return (0);
	if (game->map->grid)
		free(game->map->grid);
	game->map->grid = new_grid;
	game->map->height++;
	count_map_elements(game, new_grid[game->map->height - 1],
		game->map->height - 1);
	return (1);
}

int	validate_map(t_game *game)
{
	if (game->map->width == 0)
		return (handle_error("Error: La map est vide ou invalide\n", game));
	if (game->map->collectibles == 0)
		return (handle_error("Error: Pas de collectibles dans la map\n", game));
	if (game->map->exit == 0)
		return (handle_error("Error: Pas de sortie dans la map\n", game));
	if (game->map->player != 1)
		return (handle_error("Error: Il doit y avoir un joueur\n", game));
	if (!checks_wall(game))
		return (handle_error
			("Error: La map doit etre entouree de murs\n", game));
	if (!check_path(game))
		return (handle_error
			("Error: Pas de chemin valide dans la map\n", game));
	return (1);
}
