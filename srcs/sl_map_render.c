/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:41:18 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/19 13:57:36 by ktiomico         ###   ########.fr       */
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
	if (tile == '1')
		render_wall(game, i, j);
	else if (tile == '0')
		render_floor(game, i, j);
	else if (tile == 'P')
		render_player(game, i, j);
	else if (tile == 'C')
		render_collectible(game, i, j);
	else if (tile == 'E')
		render_exit(game, i, j);
}

void	render_wall(t_game *game, int i, int j)
{
	mlx_string_put(game->mlx, game->win, j * TILE_SIZE + game->left_offset, (i * TILE_SIZE) + 40,
		0x00FF0000, "1");
}

void	render_floor(t_game *game, int i, int j)
{
	mlx_string_put(game->mlx, game->win, j * TILE_SIZE + game->left_offset, (i * TILE_SIZE) + 40,
		0x00FFFFFF, "0");
}

void	render_player(t_game *game, int i, int j)
{
	mlx_string_put(game->mlx, game->win, j * TILE_SIZE + game->left_offset, (i * TILE_SIZE) + 40,
		0x0000FF00, "P");
}
