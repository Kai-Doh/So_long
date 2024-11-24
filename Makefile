RESET = \033[0m
GREEN = \033[32m
BLUE = \033[34m
YELLOW = \033[33m
RED = \033[31m

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
	@make --no-print-directory -C minilibx-linux
	@make --no-print-directory bonus -C libft
	@echo "$$(echo -e '$(YELLOW)Compiling $<...$(RESET)')"
	@gcc $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	@echo "$$(echo -e '$(RED)Removing library $(NAME)...$(RESET)')"
	@$(RM) $(NAME)
	@echo "$$(echo -e '$(GREEN)✔ Library $(NAME) and object files removed.$(RESET)')"
	@make fclean --no-print-directory -C libft

clean :
	@echo "$$(echo -e '$(RED)Cleaning object files...$(RESET)')"
	@$(RM) $(NAME)
	@echo "$$(echo -e '$(GREEN)✔ Object files removed.$(RESET)')"
	@make clean --no-print-directory -C libft
	@make clean --no-print-directory -C minilibx-linux

re : fclean all
