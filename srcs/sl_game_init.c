/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:30:17 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/19 02:46:13 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(void *game);
int	count_collectibles(char **map);

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
	game->collected = 0;
	game->total_collectibles = count_collectibles(game->map);
	game->e_tile = 0;
	return (SUCCESS);
}

int	count_collectibles(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	run_game(t_game *game)
{
	render_map(game);
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop(game->mlx);
}

int	close_game(void *param)
{
	t_game *game;

	game = (t_game *)param;
	cleanup_game(game);
	exit (0);
	return (0);
}
