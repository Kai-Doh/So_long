/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:41:18 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/24 10:31:11 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tile(t_game *game, char tile, int i, int j);
void	render_wall(t_game *game, int i, int j);
void	render_floor(t_game *game, int i, int j);
void	render_player(t_game *game, int i, int j);

void	render_map(t_game *game)
{
	int	i;
	int	j;

	mlx_put_image_to_window(game->mlx, game->win, game->black_bar, 0, 0);
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			render_tile(game, game->map[i][j], i, j);
			j++;
		}
		i++;
	}
	display_moves(game);
}

void	render_tile(t_game *game, char tile, int i, int j)
{
	render_floor(game, i, j);
	if (tile == '1')
		render_wall(game, i, j);
	else if (tile == 'P')
		render_player(game, i, j);
	else if (tile == 'C')
		render_collectible(game, i, j);
	else if (tile == 'E')
		render_exit(game, i, j);
	else if (tile == 'X')
		render_enemy(game, i, j);
}

void	render_wall(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->cache.img_wall, j * TILE_SIZE, i * TILE_SIZE + 12);
}

void	render_floor(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->cache.img_floor, j * TILE_SIZE, i * TILE_SIZE + 12);
}

void	render_player(t_game *game, int i, int j)
{
	if (game->player_direction == 0)
		mlx_put_image_to_window(game->mlx, game->win,
		game->cache.player_up, j * TILE_SIZE, i * TILE_SIZE + 12);
	else if (game->player_direction == 1)
		mlx_put_image_to_window(game->mlx, game->win,
		game->cache.player_down, j * TILE_SIZE, i * TILE_SIZE + 12);
	else if (game->player_direction == 2)
		mlx_put_image_to_window(game->mlx, game->win,
		game->cache.player_left, j * TILE_SIZE, i * TILE_SIZE + 12);
	else if (game->player_direction == 3)
		mlx_put_image_to_window(game->mlx, game->win,
		game->cache.player_right, j * TILE_SIZE, i * TILE_SIZE + 12);
	else
		mlx_put_image_to_window(game->mlx, game->win,
		game->cache.player_right, j * TILE_SIZE, i * TILE_SIZE + 12);
}
