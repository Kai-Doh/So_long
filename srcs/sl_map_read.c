/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:02:10 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/19 01:04:14 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(const char *file);
char	**store_map(int fd);
char	**store_line(char **map, char *line, int rows);

char	**process_map(const char *file)
{
	char	**map;

	map = read_map(file);
	if (!map)
	{
		ft_printf("\033[31mError: Failed to read map from file.\033[0m\n");
		return (NULL);
	}
	ft_printf("\033[32m[✔] Map was read and stored correctly.\033[0m\n");
	if (validate_map(map))
	{
		ft_printf("\033[31mError: Invalid map.\033[0m\n");
		free_map(map);
		return (NULL);
	}
	ft_printf("\033[32m[✔] Map structure is valid.\033[0m\n");
	return (map);
}

char	**read_map(const char *file)
{
	int		fd;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("\033[31mError: Could not open file '%s'.\033[0m\n", file);
		return (NULL);
	}
	map = store_map(fd);
	if (!map)
		ft_printf("\033[31mError: Failed to store map from file.\\033[0m\\n");
	close (fd);
	return (map);
}

char	**store_map(int fd)
{
	char	**map;
	char	*line;
	int		rows;

	map = NULL;
	rows = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map = store_line(map, line, rows);
		if (!map)
		{
			ft_printf("\033[31mError: Memory allocation failed.\033[0m\n");
			free (line);
			free_map(map);
			return (NULL);
		}
		rows++;
		line = get_next_line(fd);
	}
	return (map);
}

char	**store_line(char **map, char *line, int rows)
{
	char	**new_map;
	int		i;

	line = trim_newline(line);
	new_map = malloc((rows + 1) * sizeof(char *));
	if (!new_map)
	{
		free (line);
		free_map(map);
		return (NULL);
	}
	i = 0;
	while (i < rows)
	{
		new_map[i] = map [i];
		i++;
	}
	new_map[i] = line;
	free(map);
	return (new_map);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
