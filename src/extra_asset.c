/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_asset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 00:23:51 by bsamy             #+#    #+#             */
/*   Updated: 2025/04/05 00:23:53 by bsamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	draw_map_1(t_game *game, int y, int x)
{
	if (game->map->grid[y][x] != '1')
		mlx_put_image_to_window(game->mlx,
			game->win, game->textures.floor, x * 64, y * 64);
	if (game->map->grid[y][x] == '1')
		mlx_put_image_to_window(game->mlx,
			game->win, game->textures.wall, x * 64, y * 64);
	if (game->map->grid[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.exit_frames[game->exit_current_frame],
			x * 64, y * 64);
	if (game->map->grid[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.player, x * 64, y * 64);
	if (game->map->grid[y][x] == 'X')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.enemy, x * 64, y * 64);
	draw_map_2(game, y, x);
}

void	draw_map_2(t_game *game, int y, int x)
{
	if (game->map->grid[y][x] == 'G')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.gelano, x * 64, y * 64);
	else if (game->map->grid[y][x] == 'O')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.popo, x * 64, y * 64);
	else if (game->map->grid[y][x] == 'T')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.glove, x * 64, y * 64);
	else if (game->map->grid[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.chest_frames[game->chest_current_frame],
			x * 64, y * 64);
}
