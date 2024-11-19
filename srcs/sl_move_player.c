/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 02:05:29 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/19 23:13:06 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_move(t_game *game, int new_row, int new_col);
void	update_map(char **map, int old_row, int old_col,
	int new_row, int new_col, int *e_tile);
void	handle_interactions(t_game *game, int row, int col);
int	all_collectibles_collected(t_game *game);

void	move_player(t_game *game, int row_offset, int col_offset)
{
	int	player_row;
	int	player_col;
	int	new_col;
	int	new_row;

	find_player(game->map, &player_row, &player_col);
	new_row = player_row + row_offset;
	new_col = player_col + col_offset;
	player_direction(game, row_offset, col_offset);
	if (is_valid_move(game, new_row, new_col))
	{
		game->moves++;
		handle_interactions(game, new_row, new_col);
		update_map(game->map, player_row, player_col, new_row,
				new_col, &game->e_tile);
		update_tile(game, player_row, player_col);
		update_tile(game, new_row, new_col);
		render_black_bar(game);
	}
}

int	is_valid_move(t_game *game, int new_row, int new_col)
{
	char	tile;

	tile = game->map[new_row][new_col];
	return (tile != '1');
}

void	update_map(char **map, int old_row, int old_col,
	int new_row, int new_col, int *e_tile)
{
	if (map[old_row][old_col] == 'P' && *e_tile == 1)
	{
		map[old_row][old_col] = 'E';
		*e_tile = 0;
	}
	else if (map[old_row][old_col] == 'P' && map[new_row][new_col] == 'E')
	{
		map[old_row][old_col] = '0';
		*e_tile = 1;
	}
	else
		map[old_row][old_col] = '0';
	map[new_row][new_col] = 'P';
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
			close_game(game);
		}
		else
			ft_printf("\033[31mCollect all items before exiting!\033[0m\n");
	}
}

int	all_collectibles_collected(t_game *game)
{
	return (game->collected == game->total_collectibles);
}
