/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 00:08:04 by bsamy             #+#    #+#             */
/*   Updated: 2025/04/05 00:11:13 by bsamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	load_basic_texture_1(t_game *game, int *width, int *height)
{
	game->textures.wall = mlx_xpm_file_to_image
		(game->mlx, "textures/Purple_Brick.xpm", width, height);
	game->textures.floor = mlx_xpm_file_to_image
		(game->mlx, "textures/wood_floor.xpm", width, height);
	game->textures.player = mlx_xpm_file_to_image
		(game->mlx, "textures/wood_me.xpm", width, height);
	game->textures.gelano = mlx_xpm_file_to_image
		(game->mlx, "textures/wood_gelano.xpm", width, height);
	game->textures.popo = mlx_xpm_file_to_image
		(game->mlx, "textures/wood_popo.xpm", width, height);
	game->textures.glove = mlx_xpm_file_to_image
		(game->mlx, "textures/wood_glove.xpm", width, height);
	game->textures.enemy_right = mlx_xpm_file_to_image
		(game->mlx, "textures/wood_blob.xpm", width, height);
	game->textures.enemy_left = mlx_xpm_file_to_image
		(game->mlx, "textures/wood_blob1.xpm", width, height);
}

int	load_basic_textures(t_game *game, int *width, int *height)
{
	load_basic_texture_1(game, width, height);
	if (game->enemy.dir == 1)
		game->textures.enemy = game->textures.enemy_right;
	else
		game->textures.enemy = game->textures.enemy_left;
	if (!game->textures.wall || !game->textures.floor || !game->textures.player
		|| !game->textures.gelano || !game->textures.popo
		|| !game->textures.enemy || !game->textures.glove)
	{
		ft_putstr("Error: ❌ Impossible de charger les textures\n");
		return (0);
	}
	return (1);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			draw_map_1(game, y, x);
			x++;
		}
		y++;
	}
}

int	load_textures(t_game *game)
{
	int	width;
	int	height;

	if (!load_basic_textures(game, &width, &height))
		return (0);
	load_exit_textures(game, &width, &height);
	load_chest_textures(game, &width, &height);
	return (1);
}
