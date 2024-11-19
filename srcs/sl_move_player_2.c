/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move_player_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:37:39 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/19 12:40:31 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_tile(t_game *game, int row, int col)
{
	char	tile;

	tile = game->map[row][col];

	if (tile == '1')
		render_wall(game, row, col);
	else if (tile == '0')
		render_floor(game, row, col);
	else if (tile == 'C')
		render_collectible(game, row, col);
	else if (tile == 'E')
		render_exit(game, row, col);
	else if (tile == 'P')
		render_player(game, row, col);
}
