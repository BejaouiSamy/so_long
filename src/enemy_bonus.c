/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 00:20:39 by bsamy             #+#    #+#             */
/*   Updated: 2025/04/05 00:21:14 by bsamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	update_x_position(t_game *game)
{
	int	new_x;

	new_x = game->enemy.x + game->enemy.dir;
	if (new_x >= 0 && new_x < game->map->width)
	{
		if (game->map->grid[game->enemy.y][new_x] != '1')
		{
			game->map->grid[game->enemy.y][game->enemy.x] = '0';
			game->enemy.x = new_x;
			game->map->grid[game->enemy.y][game->enemy.x] = 'X';
		}
		else
			game->enemy.dir *= -1;
	}
	else
		game->enemy.dir *= -1;
	if (game->enemy.dir == 1)
		game->textures.enemy = game->textures.enemy_right;
	else
		game->textures.enemy = game->textures.enemy_left;
	check_collision(game);
}

void	move_enemies(t_game *game)
{
	if (game->enemy_timer > 0)
	{
		game->enemy_timer--;
		return ;
	}
	game->enemy_timer = 5000;
	update_x_position(game);
	draw_map(game);
}

void	check_collision(t_game *game)
{
	if (game->enemy.x == game->player.x && game->enemy.y == game->player.y)
	{
		ft_putstr("💀 Game Over !\n");
		free_game(game);
		exit (0);
	}
}

void	add_enemy(t_game *game, int x, int y)
{
	game->enemy.x = x;
	game->enemy.y = y;
	game->enemy.dir = 1;
	game->enemy_timer = 5000;
}
