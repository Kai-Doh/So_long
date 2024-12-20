/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:51:09 by ktiomico          #+#    #+#             */
/*   Updated: 2024/12/12 11:22:36 by ktiomico         ###   ########.fr       */
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

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"

typedef struct s_enemy
{
	int	row;
	int	col;
}	t_enemy;

typedef struct s_flood_data
{
	int	collectibles;
	int	exit;
}	t_flood_data;

typedef struct s_begin
{
	int	x;
	int	y;
}	t_begin;

typedef struct s_cache
{
	void	*img_wall;
	void	*img_floor;
	void	*img_collectible;
	void	*img_exit;
	void	*img_enemy;
	void	*player_right;
	void	*player_left;
	void	*player_up;
	void	*player_down;
}	t_cache;

typedef struct s_pos
{
	int	player_row;
	int	player_col;
	int	new_col;
	int	new_row;
}	t_pos;

typedef struct s_game
{
	void	*black_bar;
	void	*mlx;
	void	*win;
	int		player_direction;
	int		e_tile;
	int		win_width;
	int		win_height;
	int		left_offset;
	int		collected;
	int		total_collectibles;
	int		moves;
	int		enemy_count;
	char	**map;
	t_enemy	enemies;
	t_cache	cache;
	t_pos	pos;
}	t_game;

void	player_direction(t_game *game, int row_offset, int col_offset);
void	display_moves(t_game *game);
void	cleanup_game(t_game *game);
int		close_game(void *game);
int		initialize_game(t_game *game);
void	run_game(t_game *game);
int		check_file(int ac, char **av);
char	**process_map(const char *file, t_game *game);
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
void	render_floor(t_game *game, int i, int j);
void	render_enemy(t_game *game, int i, int j);
void	render_player(t_game *game, int i, int j);
void	render_black_bar(t_game *game);
int		handle_keypress(int keycode, t_game *game);
void	move_player(t_game *game, int row_offset, int col_offset);
void	find_player(char **map, int *row, int *col);
void	update_tile(t_game *game, int row, int col);
void	load_cache(t_game *game);
void	free_cache(t_game *game);
int		validate_reachability(char **map, int rows, int cols);
int		count_character(char **map, int rows, int cols, char target);
void	render_wall(t_game *game, int i, int j);
#endif
