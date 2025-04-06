/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation_extra.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:30:11 by bsamy             #+#    #+#             */
/*   Updated: 2025/04/06 10:27:55 by bsamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

int	is_valid_position(t_map *map, int x, int y, int **visited)
{
	return (x >= 0 && x < map->width && y >= 0 && y < map->height
		&& map->grid[y][x] != '1' && visited[y][x] == 0);
}

void	process_node_check(t_game *game, t_coords coords, t_counters *counters)
{
	if (game->map->grid[coords.y][coords.x] == 'C')
		counters->c_found++;
	if (game->map->grid[coords.y][coords.x] == 'E')
		counters->e_found = 1;
}

// Traite un nœud de la file d'attente lors du parcours BFS
void	process_node_neighbors(t_game *game, int **visited
		, t_coords coords, t_queue **queue)
{
	int			i;
	const int	dx[] = {1, -1, 0, 0};
	const int	dy[] = {0, 0, 1, -1};
	int			nx;
	int			ny;

	i = -1;
	while (++i < 4)
	{
		nx = coords.x + dx[i];
		ny = coords.y + dy[i];
		if (is_valid_position(game->map, nx, ny, visited))
		{
			enqueue(queue, nx, ny);
			visited[ny][nx] = 1;
		}
	}
}

// Initialise le tableau de visite
int	**init_visited(t_game *game)
{
	int		x;
	int		y;
	int		**visited;

	visited = malloc(sizeof(int *) * game->map->height);
	if (!visited)
		return (NULL);
	y = 0;
	while (y < game->map->height)
	{
		visited[y] = malloc(game->map->width * sizeof(int));
		if (!visited[y])
			free (visited[--y]);
		x = 0;
		while (x < game->map->width)
		{
			visited[y][x] = 0;
			x++;
		}
		y++;
	}
	return (visited);
}
