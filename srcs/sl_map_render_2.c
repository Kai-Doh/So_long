/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_render_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:45:57 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/19 01:50:10 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_collectible(t_game *game, int i, int j)
{
	mlx_string_put(game->mlx, game->win, j * TILE_SIZE, i * TILE_SIZE,
		0x0000FFFF, "C");
}

void	render_exit(t_game *game, int i, int j)
{
	mlx_string_put(game->mlx, game->win, j * TILE_SIZE, i * TILE_SIZE,
		0x00FFFF00, "E");
}
