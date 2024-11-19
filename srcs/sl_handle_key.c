/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_handle_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 02:01:17 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/19 02:05:01 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_game(game);
	else if (keycode == 'w' || keycode == 'W')
		move_player(game, -1, 0);
	else if (keycode == 's' || keycode == 'S')
		move_player(game, 1, 0);
	else if (keycode == 'a' || keycode == 'A')
		move_player(game, 0, -1);
	else if (keycode == 'd' || keycode == 'D')
		move_player(game, 0, 1);
	return (0);
}

void find_player(char **map, int *row, int *col)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j]) {
			if (map[i][j] == 'P')
			{
				*row = i;
				*col = j;
				return;
			}
			j++;
		}
		i++;
	}
}
