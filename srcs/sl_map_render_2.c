/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_render_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:45:57 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/19 16:01:41 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_collectible(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->cache.img_collectible, (j * TILE_SIZE) + 4, i * TILE_SIZE);
}

void	render_exit(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->cache.img_exit, (j * TILE_SIZE) + 20, i * TILE_SIZE);
}
