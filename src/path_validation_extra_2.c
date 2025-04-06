/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation_extra_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 10:31:29 by bsamy             #+#    #+#             */
/*   Updated: 2025/04/06 10:31:30 by bsamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	print_error_collectibles(int y, int x)
{
	ft_putstr("Error: Collectible inaccessible à [");
	ft_putnbr(x);
	ft_putstr(", ");
	ft_putnbr(y);
	ft_putstr("]\n");
}

void	print_game_info(t_game *game)
{
	ft_putstr("Dimensions de la carte: ");
	ft_putnbr(game->map->width);
	ft_putstr(" x ");
	ft_putnbr(game->map->height);
	ft_putstr("\n");
	ft_putstr("Position du joueur: (");
	ft_putnbr(game->player.x);
	ft_putstr(", ");
	ft_putnbr(game->player.y);
	ft_putstr(")\n");
	ft_putstr("Nombre de sorties attendus: ");
	ft_putnbr(game->map->exit);
	ft_putstr("\n");
}

// Affiche les messages d'erreur pour le chemin invalide
void	print_path_error(t_game *game, t_counters *counters
		, int total_collectibles, int **visited)
{
	check_unreachable_collectibles(game, visited);
	ft_putstr("Error: Chemin invalide, ");
	if (counters->e_found == 0)
		ft_putstr("la sortie est inaccessible.\n");
	else if (counters->c_found < total_collectibles)
		ft_putstr("certains collectibles sont inaccessibles.\n");
	else
		ft_putstr("parcours impossible.\n");
}
