/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:50:01 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/19 00:37:16 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	**map;

	map = NULL;
	if (check_file(ac, av) == 1)
		return (ARGS_FAIL);
	map = process_map(av[1]);
	free_map(map);
	return (0);
}
