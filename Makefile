NAME = so_long

CC = gcc

CFLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -g -I./include

RM = rm -rf

SRCS =	srcs/so_long.c\
		srcs/sl_file_check.c\
		srcs/sl_map_read.c\
		srcs/sl_map_check.c\
		srcs/sl_map_utils.c\
		srcs/sl_map_render.c\
		srcs/sl_map_render_2.c\
		srcs/sl_free.c\
		srcs/sl_game_init.c\
		srcs/sl_handle_key.c\
		srcs/sl_move_player.c\
		srcs/sl_move_player_2.c\
		srcs/sl_move_count.c\
		srcs/sl_img_cache.c\
		libft/libft.a\
		minilibx-linux/libmlx_Linux.a\
		minilibx-linux/libmlx.a

$(NAME) :
		make bonus -C libft
		gcc $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : fclean all
