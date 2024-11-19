/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:50:01 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/19 13:54:38 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	game.map = NULL;
	if (check_file(ac, av) == 1)
		return (ARGS_FAIL);
	game.map = process_map(av[1]);
	if (!game.map)
		return (MAP_FAIL);
	if (initialize_game(&game) != 0)
		return (MLX_FAIL);
	run_game(&game);
	cleanup_game(&game);
	return (0);
}
