/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:37:10 by ktiomico          #+#    #+#             */
/*   Updated: 2024/12/12 11:25:12 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **map, int x, int y, t_flood_data *data)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
		data->collectibles++;
	if (map[y][x] == 'E')
		data->exit++;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, data);
	flood_fill(map, x - 1, y, data);
	flood_fill(map, x, y + 1, data);
	flood_fill(map, x, y - 1, data);
}

static char	**copy_map(char **map, int rows)
{
	char	**temp_map;
	int		i;

	temp_map = malloc(sizeof(char *) * rows);
	if (!temp_map)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		temp_map[i] = ft_strdup(map[i]);
		if (!temp_map[i])
		{
			while (--i >= 0)
				free(temp_map[i]);
			free(temp_map);
			return (NULL);
		}
		i++;
	}
	return (temp_map);
}

static int	find_player_position(char **map, int rows, int cols, t_begin *pos)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (map[i][j] == 'P')
			{
				pos->x = j;
				pos->y = i;
				return (0);
			}
			j++;
		}
		i++;
	}
	pos->x = -1;
	pos->y = -1;
	return (-1);
}

static int	validate_flood_results(t_flood_data *data, int total_collectibles)
{
	if (data->collectibles != total_collectibles)
	{
		ft_printf("\033[31mError: Not all collectibles reachable.\033[0m\n");
		return (CHECK_KO);
	}
	if (data->exit == 0)
	{
		ft_printf("\033[31mError: Exit is not reachable.\033[0m\n");
		return (CHECK_KO);
	}
	return (CHECK_OK);
}

int	validate_reachability(char **map, int rows, int cols)
{
	char			**temp_map;
	t_flood_data	data;
	t_begin			player_pos;
	int				total_collectibles;

	temp_map = copy_map(map, rows);
	if (!temp_map)
	{
		ft_printf("\033[31mError: Failed to copy map.\033[0m\n");
		return (CHECK_KO);
	}
	data.collectibles = 0;
	data.exit = 0;
	if (find_player_position(map, rows, cols, &player_pos) == -1)
	{
		free_map(temp_map);
		ft_printf("\033[31mError: Player not found.\033[0m\n");
		return (CHECK_KO);
	}
	total_collectibles = count_character(map, rows, cols, 'C');
	flood_fill(temp_map, player_pos.x, player_pos.y, &data);
	free_map(temp_map);
	return (validate_flood_results(&data, total_collectibles));
}
