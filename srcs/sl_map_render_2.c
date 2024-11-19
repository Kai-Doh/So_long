/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_render_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:45:57 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/19 16:28:47 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_collectible(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->cache.img_collectible, (j * TILE_SIZE) + 4, i * TILE_SIZE + 12);
}

void	render_exit(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->cache.img_exit, (j * TILE_SIZE) + 20, i * TILE_SIZE + 12);
}

void	render_black_bar(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->black_bar, 0, 0);
}
