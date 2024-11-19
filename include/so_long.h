#ifndef SO_LONG_H
# define SO_LONG_H
# define ARGS_FAIL 1
# define WRONG_FILE 1
# define CHECK_OK 0
# define VALID_FILE 0
# define INVALID_FILE 1
# define CHECK_KO 1
# define WIDTH 1920
# define HEIGHT 1080

#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	int		first_render;
	int		move_count;
}	t_mlx_data;

int		check_file(int ac, char **av);
char	**process_map(const char *file);
int		validate_map(char **map);
void	free_map(char **map);
int		count_rows(char **map);
int		check_side_columns(char **map, int rows, int cols);
int		check_top_bottom_rows(char **map, int rows, int cols);
char	*trim_newline(char *line);

#endif
