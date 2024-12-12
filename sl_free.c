/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:35:15 by ktiomico          #+#    #+#             */
/*   Updated: 2024/12/06 13:02:58 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_game_end(t_game *game)
{
	if (game->black_bar)
		mlx_destroy_image(game->mlx, game->black_bar);
	if (game->cache.img_floor)
		mlx_destroy_image(game->mlx, game->cache.img_floor);
	if (game->cache.img_wall)
		mlx_destroy_image(game->mlx, game->cache.img_wall);
	if (game->cache.player_up)
		mlx_destroy_image(game->mlx, game->cache.player_up);
	if (game->cache.player_down)
		mlx_destroy_image(game->mlx, game->cache.player_down);
	if (game->cache.player_left)
		mlx_destroy_image(game->mlx, game->cache.player_left);
	if (game->cache.player_right)
		mlx_destroy_image(game->mlx, game->cache.player_right);
	if (game->cache.img_collectible)
		mlx_destroy_image(game->mlx, game->cache.img_collectible);
	if (game->cache.img_exit)
		mlx_destroy_image(game->mlx, game->cache.img_exit);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->map)
		free_map(game->map);
	exit(EXIT_SUCCESS);
}

void	cleanup_game(t_game *game)
{
	close_game_end(game);
	if (game->mlx)
	{
		mlx_loop_end(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
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
