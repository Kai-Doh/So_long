/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:50:01 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/19 17:17:54 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (check_file(ac, av) == 1)
		return (ARGS_FAIL);
	game.map = process_map(av[1], &game);
	if (!game.map)
	{
		cleanup_game(&game);
		return (MAP_FAIL);
	}
	if (initialize_game(&game) != 0)
	{
		cleanup_game(&game);
		return (MLX_FAIL);
	}
	run_game(&game);
	cleanup_game(&game);
	return (0);
}
