/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:22:44 by ktiomico          #+#    #+#             */
/*   Updated: 2024/12/06 13:06:40 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(char **map, int rows, int cols);
int	check_boundaries(char **map, int rows, int cols);
int	validate_components(char **map, int rows, int cols);
int	count_character(char **map, int rows, int cols, char target);

int	validate_map(char **map)
{
	int	rows;
	int	cols;

	rows = count_rows(map);
	if (!map || rows <= 0)
	{
		ft_printf("\033[31mError: Invalid or empty map.\033[0m\n");
		return (CHECK_KO);
	}
	cols = ft_strlen(map[0]);
	if (is_rectangular(map, rows, cols))
		return (CHECK_KO);
	if (check_boundaries(map, rows, cols))
		return (CHECK_KO);
	if (validate_components(map, rows, cols))
		return (CHECK_KO);
	return (CHECK_OK);
}

int	is_rectangular(char **map, int rows, int cols)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		if (!map[i])
		{
			ft_printf("\033[31mError: Row %d is NULL.\033[0m\n", i);
			return (1);
		}
		if ((int)ft_strlen(map[i]) != cols)
		{
			ft_printf("\033[31mError: Map is not rectangular.\033[0m\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_boundaries(char **map, int rows, int cols)
{
	if (check_top_bottom_rows(map, rows, cols) != 0)
	{
		ft_printf(
			"\033[31mMap is not surrounded by walls (top/bottom).\033[0m\n");
		return (1);
	}
	if (check_side_columns(map, rows, cols) != 0)
	{
		ft_printf(
			"\033[31mMap is not surrounded by walls (left/right).\033[0m\n");
		return (1);
	}
}

int	validate_components(char **map, int rows, int cols)
{
	int	player;
	int	exit;
	int	collectible;

	player = count_character(map, rows, cols, 'P');
	exit = count_character(map, rows, cols, 'E');
	collectible = count_character(map, rows, cols, 'C');
	if (player != 1 || exit < 1 || collectible < 1)
	{
		ft_printf("\033[31mDoes not have the right components.\033[0m\n");
		return (1);
	}
	return (0);
}

int	count_character(char **map, int rows, int cols, char target)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < rows)
	{
		if (!map[i])
			break ;
		j = 0;
		while (j < cols)
		{
			if (map[i][j] == target)
			{
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}
