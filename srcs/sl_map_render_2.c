/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_render_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:45:57 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/19 23:51:14 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_collectible(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->cache.img_collectible, (j * TILE_SIZE) + 9, i * TILE_SIZE + 12);
}

void	render_exit(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->cache.img_exit, (j * TILE_SIZE) + 20, i * TILE_SIZE + 12);
}

void	render_black_bar(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->black_bar, 0, 0);
	ft_printf("\033[34mMoves:\033[0m \033[35m%d\033[0m\n", game->moves);
	display_moves(game);
}
