/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move_player_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:37:39 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/19 14:51:36 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_tile(t_game *game, int row, int col)
{
	char	tile;

	tile = game->map[row][col];
	mlx_put_image_to_window(game->mlx, game->win, game->cache.img_floor,
			col * TILE_SIZE, row * TILE_SIZE);
	if (tile == 'P')
	{
		if (game->player_direction == 0)
			mlx_put_image_to_window(game->mlx, game->win, game->cache.player_up, col * TILE_SIZE, row * TILE_SIZE);
		else if (game->player_direction == 1)
			mlx_put_image_to_window(game->mlx, game->win, game->cache.player_down, col * TILE_SIZE, row * TILE_SIZE);
		else if (game->player_direction == 2)
			mlx_put_image_to_window(game->mlx, game->win, game->cache.player_left, col * TILE_SIZE, row * TILE_SIZE);
		else if (game->player_direction == 3)
			mlx_put_image_to_window(game->mlx, game->win, game->cache.player_right, col * TILE_SIZE, row * TILE_SIZE);
	}
}
