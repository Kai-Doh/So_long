/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 00:34:06 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/19 01:50:48 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_rows(char **map)
{
	int	rows;

	rows = 0;
	if (!map)
		return (0);
	while (map[rows])
	{
		rows++;
	}
	return (rows);
}

int	check_top_bottom_rows(char **map, int rows, int cols)
{
	int	i;

	i = 0;
	while (i < cols)
	{
		if (map[0][i] != '1' || map[rows - 1][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_side_columns(char **map, int rows, int cols)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

char	*trim_newline(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}
