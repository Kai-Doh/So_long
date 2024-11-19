/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:30:17 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/19 01:50:34 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initialize_game(t_game *game)
{
	game->win_height = count_rows(game->map) * TILE_SIZE;
	game->win_width = ft_strlen(game->map[0]) * TILE_SIZE;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (MLX_FAIL);
	game->win = mlx_new_window(game->mlx, game->win_width, game->win_height,
			"so_long");
	if (!game->win)
		return (MLX_FAIL);
	return (SUCCESS);
}

void	run_game(t_game *game)
{
	render_map(game);
	mlx_loop(game->mlx);
}
