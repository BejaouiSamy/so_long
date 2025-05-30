/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:13:02 by bsamy             #+#    #+#             */
/*   Updated: 2025/04/06 13:47:19 by bsamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	new_cell;

	new_x = game->player.x + dx;
	new_y = game->player.y + dy;
	if (game->map->grid[new_y][new_x] != '1')
	{
		new_cell = game->map->grid[new_y][new_x];
		if (check_cell(game, new_cell) == 0)
		{
			game->map->grid[game->player.y][game->player.x] = '0';
			game->steps++;
			game->player.x = new_x;
			game->player.y = new_y;
			game->map->grid[new_y][new_x] = 'P';
			mlx_clear_window(game->mlx, game->win);
			draw_map(game);
			display_steps(game);
		}
	}
}

int	handle_collectibles(t_game *game, char new_cell)
{
	if (new_cell == 'C')
	{
		game->map->collectibles--;
		return (1);
	}
	if (new_cell == 'T')
	{
		game->map->glove--;
		return (1);
	}
	if (new_cell == 'G')
	{
		game->map->gelano--;
		return (1);
	}
	if (new_cell == 'O')
	{
		game->map->popo--;
		return (1);
	}
	return (0);
}

int	check_cell(t_game *game, char new_cell)
{
	if (handle_collectibles(game, new_cell))
		return (0);
	if (new_cell == 'E')
	{
		if (game->map->collectibles > 0
			|| game->map->gelano > 0
			|| game->map->glove > 0
			|| game->map->popo > 0)
		{
			ft_putstr("❌ Vous devez ramasser tous les collectibles!\n");
			return (1);
		}
	}
	if (new_cell == 'E' && game->map->collectibles == 0
		&& game->map->gelano == 0
		&& game->map->glove == 0
		&& game->map->popo == 0)
	{
		ft_putstr("Félicitations ! Vous avez gagné !\n");
		free_game(game);
		return (0);
	}
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		free_game(game);
	if (keycode == 97)
		move_player(game, -1, 0);
	else if (keycode == 119)
		move_player(game, 0, -1);
	else if (keycode == 100)
		move_player(game, 1, 0);
	else if (keycode == 115)
		move_player(game, 0, 1);
	return (0);
}

void	display_steps(t_game *game)
{
	char	steps_str[50];
	char	*num_str;

	ft_strlcpy(steps_str, "Pas: ", sizeof(steps_str));
	num_str = ft_itoa(game->steps);
	if (num_str)
	{
		ft_strlcat(steps_str, num_str, sizeof(steps_str));
		mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, steps_str);
		free(num_str);
	}
}
