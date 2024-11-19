/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:51:09 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/19 01:51:20 by ktiomico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define ARGS_FAIL 1
# define WRONG_FILE 1
# define CHECK_OK 0
# define VALID_FILE 0
# define INVALID_FILE 1
# define MAP_FAIL 1
# define MLX_FAIL 1
# define CHECK_KO 1
# define SUCCESS 0
# define WIDTH 1920
# define HEIGHT 1080
# define TILE_SIZE 32

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	char	**map;
}	t_game;

void	cleanup_game(t_game *game);
int		initialize_game(t_game *game);
void	run_game(t_game *game);
int		check_file(int ac, char **av);
char	**process_map(const char *file);
int		validate_map(char **map);
void	free_map(char **map);
int		count_rows(char **map);
int		check_side_columns(char **map, int rows, int cols);
int		check_top_bottom_rows(char **map, int rows, int cols);
char	*trim_newline(char *line);
void	render_map(t_game *game);
void	render_collectible(t_game *game, int i, int j);
void	render_exit(t_game *game, int i, int j);
void	render_tile(t_game *game, char tile, int i, int j);
void	render_wall(t_game *game, int i, int j);
void	render_floor(t_game *game, int i, int j);
void	render_player(t_game *game, int i, int j);

#endif
