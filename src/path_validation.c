/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:19:26 by bsamy             #+#    #+#             */
/*   Updated: 2025/04/05 23:23:00 by bsamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

// Ajouter un élément à la file d'attente
void	enqueue(t_queue **queue, int x, int y)
{
	t_queue	*new;
	t_queue	*temp;

	new = malloc(sizeof(t_queue));
	if (!new)
		return ;
	new->x = x;
	new->y = y;
	new->next = NULL;
	if (!*queue)
		*queue = new;
	else
	{
		temp = *queue;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

// Retirer un élément de la file d'attente
void	dequeue(t_queue **queue)
{
	t_queue	*temp;

	if (!*queue)
		return ;
	temp = *queue;
	*queue = (*queue)->next;
	free(temp);
}

int	bfs(t_game *game, int **visited
		, t_counters *counters, int *total_collectibles)
{
	t_queue		*queue;
	t_coords	coords;

	*total_collectibles = game->map->collectibles;
	queue = NULL;
	coords.x = game->player.x;
	coords.y = game->player.y;
	enqueue(&queue, coords.x, coords.y);
	visited[coords.y][coords.x] = 1;
	while (queue)
	{
		coords.x = queue->x;
		coords.y = queue->y;
		dequeue(&queue);
		if (game->map->grid[coords.y][coords.x] == 'E')
			counters->e_found++;
		else
		{
			process_node_check(game, coords, counters);
			process_node_neighbors(game, visited, coords, &queue);
		}
	}
	return (counters->c_found == *total_collectibles && counters->e_found > 0);
}

// Fonction principale pour vérifier le chemin
int	check_path(t_game *game)
{
	int			**visited;
	t_counters	counters;
	int			total_collectibles;

	counters.c_found = 0;
	counters.e_found = 0;
	total_collectibles = game->map->collectibles;
	print_game_info(game);
	visited = init_visited(game);
	if (!visited)
		return (0);
	if (bfs(game, visited, &counters, &total_collectibles))
	{
		free_visited(visited, game->map->height);
		return (1);
	}
	print_path_error(game, &counters, total_collectibles, visited);
	free_visited(visited, game->map->height);
	return (0);
}

// Fonction pour vérifier si des collectibles sont inaccessibles
void	check_unreachable_collectibles(t_game *game, int **visited)
{
	int	x;
	int	y;
	int	unreachable_count;

	unreachable_count = 0;
	y = -1;
	while (++y < game->map->height)
	{
		x = -1;
		while (++x < game->map->width)
		{
			if (game->map->grid[y][x] == 'C' && visited[y][x] == 0)
			{
				print_error_collectibles(y, x);
				unreachable_count++;
			}
		}
	}
	if (unreachable_count > 0)
	{
		ft_putstr("Total de ");
		ft_putnbr(unreachable_count);
		ft_putstr("collectibles inaccessibles.\n");
	}
}
