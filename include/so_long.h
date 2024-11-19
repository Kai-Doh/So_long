/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiomico <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:51:09 by ktiomico          #+#    #+#             */
/*   Updated: 2024/11/19 14:45:25 by ktiomico         ###   ########.fr       */
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

typedef struct s_cache
{
	void	*img_wall;
	void	*img_floor;
	void	*img_collectible;
	void	*img_exit;
	void	*player_right;
	void	*player_left;
	void	*player_up;
	void	*player_down;
}	t_cache;

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
	char	**map;
	t_cache	cache;
}	t_game;

void	display_moves(t_game *game);
void	cleanup_game(t_game *game);
int		close_game(void *game);
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
int		handle_keypress(int keycode, t_game *game);
void	move_player(t_game *game, int row_offset, int col_offset);
void 	find_player(char **map, int *row, int *col);
void	update_tile(t_game *game, int row, int col);
void	load_cache(t_game *game);
void	free_cache(t_game *game);

#endif
