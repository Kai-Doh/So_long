/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 02:59:53 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/19 16:34:29 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_moves(t_game *game)
{
	char	*move;

	move = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xE2D5C4, "Moves: ");
	mlx_string_put(game->mlx, game->win, 80, 10, 0xE2D5C4, move);
	free(move);
}
