/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_img_cache.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:10:57 by ktiomico          #+#    #+#             */
/*   Updated: 2024/12/06 12:58:21 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_player(t_game *game);

void	load_cache(t_game *game)
{
	int	img_width;
	int	img_height;

	game->cache.img_wall = mlx_xpm_file_to_image(game->mlx,
			"assets/wall.xpm", &img_width, &img_height);
	game->cache.img_floor = mlx_xpm_file_to_image(game->mlx,
			"assets/floor.xpm", &img_width, &img_height);
	game->cache.img_collectible = mlx_xpm_file_to_image(game->mlx,
			"assets/collectible.xpm", &img_width, &img_height);
	game->cache.img_exit = mlx_xpm_file_to_image(game->mlx,
			"assets/exit.xpm", &img_width, &img_height);
	game->cache.img_enemy = mlx_xpm_file_to_image(game->mlx,
			"assets/enemy.xpm", &img_width, &img_height);
	game->cache.player_right = mlx_xpm_file_to_image(game->mlx,
			"assets/player_right.xpm", &img_width, &img_height);
	if (!game->cache.img_wall || !game->cache.img_floor
		|| !game->cache.img_collectible || !game->cache.img_exit
		|| !game->cache.player_right)
	{
		ft_printf("\033[31mError: Failed to load images.\033[0m\n");
		exit(EXIT_FAILURE);
	}
	load_player(game);
}

void	load_player(t_game *game)
{
	int	img_width;
	int	img_height;

	game->cache.player_left = mlx_xpm_file_to_image(game->mlx,
			"assets/player_left.xpm", &img_width, &img_height);
	game->cache.player_up = mlx_xpm_file_to_image(game->mlx,
			"assets/player_up.xpm", &img_width, &img_height);
	game->cache.player_down = mlx_xpm_file_to_image(game->mlx,
			"assets/player_down.xpm", &img_width, &img_height);
}

void	free_cache(t_game *game)
{
	if (game->cache.img_wall)
		mlx_destroy_image(game->mlx, game->cache.img_wall);
	if (game->cache.img_floor)
		mlx_destroy_image(game->mlx, game->cache.img_floor);
	if (game->cache.img_collectible)
		mlx_destroy_image(game->mlx, game->cache.img_collectible);
	if (game->cache.img_exit)
		mlx_destroy_image(game->mlx, game->cache.img_exit);
	if (game->cache.player_right)
		mlx_destroy_image(game->mlx, game->cache.player_right);
	if (game->cache.player_up)
		mlx_destroy_image(game->mlx, game->cache.player_up);
	if (game->cache.player_down)
		mlx_destroy_image(game->mlx, game->cache.player_down);
	if (game->cache.player_left)
		mlx_destroy_image(game->mlx, game->cache.player_left);
	if (game->cache.img_enemy)
		mlx_destroy_image(game->mlx, game->cache.img_enemy);
}
