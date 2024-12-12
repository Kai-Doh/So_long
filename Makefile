RESET = \033[0m
GREEN = \033[32m
BLUE = \033[34m
YELLOW = \033[33m
RED = \033[31m

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -I./include -Lminilibx-linux -lX11 -lXext -lmlx_Linux -lm -lbsd

RM = rm -rf

SRCS =  so_long.c \
        sl_file_check.c \
        sl_map_read.c \
        sl_map_check.c \
        sl_map_utils.c \
        sl_map_render.c \
        sl_map_render_2.c \
        sl_free.c \
        sl_game_init.c \
        sl_handle_key.c \
        sl_move_player.c \
        sl_move_player_2.c \
        sl_move_count.c \
        sl_img_cache.c \
		sl_map_path.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@make --no-print-directory -C minilibx-linux
	@make --no-print-directory bonus -C libft
	@echo "$$(echo -e '$(YELLOW)Linking $(NAME)...$(RESET)')"
	@$(CC) $(OBJS) libft/libft.a minilibx-linux/libmlx_Linux.a $(CFLAGS) -o $(NAME)

%.o: %.c
	@echo "$$(echo -e '$(BLUE)Compiling $<...$(RESET)')"
	@$(CC) -c $< -o $@ $(CFLAGS)

all: $(NAME)

clean:
	@echo "$$(echo -e '$(RED)Cleaning object files...$(RESET)')"
	@$(RM) $(OBJS)
	@echo "$$(echo -e '$(GREEN)✔ Object files removed.$(RESET)')"
	@make clean --no-print-directory -C libft
	@make clean --no-print-directory -C minilibx-linux

fclean: clean
	@echo "$$(echo -e '$(RED)Removing library $(NAME)...$(RESET)')"
	@$(RM) $(NAME)
	@echo "$$(echo -e '$(GREEN)✔ Library $(NAME) removed.$(RESET)')"
	@make fclean --no-print-directory -C libft

re: fclean all
