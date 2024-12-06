/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 02:05:29 by ktiomico          #+#    #+#             */
/*   Updated: 2024/12/06 13:20:26 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		is_valid_move(t_game *game, int new_row, int new_col);
void	update_map(t_game *game);
void	handle_interactions(t_game *game, int row, int col);
int		all_collectibles_collected(t_game *game);

void	move_player(t_game *game, int row_offset, int col_offset)
{
	find_player(game->map, &game->pos.player_row, &game->pos.player_col);
	game->pos.new_row = game->pos.player_row + row_offset;
	game->pos.new_col = game->pos.player_col + col_offset;
	player_direction(game, row_offset, col_offset);
	if (is_valid_move(game, game->pos.new_row, game->pos.new_col))
	{
		game->moves++;
		handle_interactions(game, game->pos.new_row, game->pos.new_col);
		update_map(game);
		update_tile(game, game->pos.player_row, game->pos.player_col);
		update_tile(game, game->pos.new_row, game->pos.new_col);
		render_black_bar(game);
	}
}

int	is_valid_move(t_game *game, int new_row, int new_col)
{
	char	tile;

	tile = game->map[new_row][new_col];
	return (tile != '1');
}

void	update_map(t_game *game)
{
	if (game->map[game->pos.player_row][game->pos.player_col] == 'P'
			&& game->e_tile == 1)
	{
		game->map[game->pos.player_row][game->pos.player_col] = 'E';
		game->e_tile = 0;
	}
	else if (game->map[game->pos.player_row][game->pos.player_col] == 'P'
			&& game->map[game->pos.new_row][game->pos.new_col] == 'E')
	{
		game->map[game->pos.player_row][game->pos.player_col] = '0';
		game->e_tile = 1;
	}
	else
		game->map[game->pos.player_row][game->pos.player_col] = '0';
	game->map[game->pos.new_row][game->pos.new_col] = 'P';
}

void	handle_interactions(t_game *game, int row, int col)
{
	char	tile;

	tile = game->map[row][col];
	if (tile == 'C')
	{
		game->collected++;
		game->map[row][col] = '0';
	}
	else if (tile == 'E')
	{
		if (all_collectibles_collected(game))
		{
			ft_printf(
				"\033[32m[✔] Congratulations! You've won the game.\033[0m\n");
			cleanup_game(game);
		}
		else
			ft_printf("\033[31mCollect all items before exiting!\033[0m\n");
	}
	else if (tile == 'X')
	{
		ft_printf("\033[31mGame Over! you got ran into an enemy!\033[0m\n");
		cleanup_game(game);
	}
}

int	all_collectibles_collected(t_game *game)
{
	return (game->collected == game->total_collectibles);
}
