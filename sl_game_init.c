/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:30:17 by ktiomico          #+#    #+#             */
/*   Updated: 2024/12/06 12:57:09 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		close_game(void *game);
int		count_collectibles(char **map);
void	create_black_bar(t_game *game);

int	initialize_game(t_game *game)
{
	game->win_height = (count_rows(game->map) * TILE_SIZE) + 12;
	game->win_width = (ft_strlen(game->map[0]) * TILE_SIZE);
	game->left_offset = (game->win_width
			- (ft_strlen(game->map[0]) * TILE_SIZE)) / 2;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (MLX_FAIL);
	game->win = mlx_new_window(game->mlx, game->win_width, game->win_height,
			"so_long");
	if (!game->win)
		return (MLX_FAIL);
	create_black_bar(game);
	render_black_bar(game);
	game->collected = 0;
	game->total_collectibles = count_collectibles(game->map);
	game->e_tile = 0;
	game->moves = 0;
	load_cache(game);
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
	t_game	*game;

	game = (t_game *)param;
	cleanup_game(game);
	free_cache(game);
	exit (0);
	return (0);
}

void	create_black_bar(t_game *game)
{
	int		bar_height;
	int		total_pixels;
	int		i;
	int		j;
	char	*data;

	bar_height = 12;
	total_pixels = game->win_width * bar_height;
	game->black_bar = mlx_new_image(game->mlx, game->win_width, bar_height);
	data = mlx_get_data_addr(game->black_bar, &i, &j, &i);
	i = 0;
	while (i < total_pixels * 4)
	{
		data[i] = 88;
		data[i + 1] = 77;
		data[i + 2] = 47;
		data[i + 3] = 255;
		i += 4;
	}
}
