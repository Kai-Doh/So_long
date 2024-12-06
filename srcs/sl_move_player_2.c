/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move_player_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:37:39 by ktiomico          #+#    #+#             */
/*   Updated: 2024/12/06 13:01:55 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_tile_player(t_game *game, int row, int col, char tile);

void	update_tile(t_game *game, int row, int col)
{
	char	tile;

	tile = game->map[row][col];
	mlx_put_image_to_window(game->mlx, game->win, game->cache.img_floor,
		col * TILE_SIZE, row * TILE_SIZE + 12);
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->cache.img_wall,
			col * TILE_SIZE, row * TILE_SIZE + 12);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->cache.img_collectible, col * TILE_SIZE,
			row * TILE_SIZE + 12);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->cache.img_exit,
			(col * TILE_SIZE) + 20, row * TILE_SIZE + 12);
	else if (tile == 'X')
		mlx_put_image_to_window(game->mlx, game->win, game->cache.img_enemy,
			col * TILE_SIZE, row * TILE_SIZE + 12);
	update_tile_player(game, row, col, tile);
}

void	update_tile_player(t_game *game, int row, int col, char tile)
{
	if (tile == 'P')
	{
		if (game->player_direction == 0)
			mlx_put_image_to_window(game->mlx, game->win,
				game->cache.player_up, col * TILE_SIZE, row * TILE_SIZE + 12);
		else if (game->player_direction == 1)
			mlx_put_image_to_window(game->mlx, game->win,
				game->cache.player_down, col * TILE_SIZE, row * TILE_SIZE + 12);
		else if (game->player_direction == 2)
			mlx_put_image_to_window(game->mlx, game->win,
				game->cache.player_left, col * TILE_SIZE, row * TILE_SIZE + 12);
		else if (game->player_direction == 3)
			mlx_put_image_to_window(game->mlx, game->win,
				game->cache.player_right, col * TILE_SIZE,
				row * TILE_SIZE + 12);
	}
}

void	player_direction(t_game *game, int row_offset, int col_offset)
{
	if (row_offset == -1)
		game->player_direction = 0;
	else if (row_offset == 1)
		game->player_direction = 1;
	else if (col_offset == -1)
		game->player_direction = 2;
	else if (col_offset == 1)
		game->player_direction = 3;
}
