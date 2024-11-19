/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_file_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:16:29 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/19 00:15:25 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_file_extension(char *file);

int	check_file(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("\033[31mPlease provide a single file.\033[0m\n");
		return (ARGS_FAIL);
	}
	if (check_file_extension(av[1]) == WRONG_FILE)
	{
		ft_printf("\033[31mPlease provide a \".ber\" file.\033[0m\n");
		return (WRONG_FILE);
	}
	ft_printf("\033[32m[✔] Args and file are valid.\033[0m\n");
	return (CHECK_OK);
}

static int	check_file_extension(char *file)
{
	const char	*extension;

	extension = ft_strrchr(file, '.');
	if (extension && ft_strncmp(extension, ".ber", 4) == 0)
		return (VALID_FILE);
	return (INVALID_FILE);
}
