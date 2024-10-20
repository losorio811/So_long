NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
SRC = gnl/get_next_line_utils.c gnl/get_next_line.c srcs/main.c srcs/check_map.c \
		srcs/utils.c srcs/libft_utils.c srcs/split.c srcs/flood_fill.c srcs/check_map_2.c
OBJ_DIR = obj
INCLUDE_FOLDER = include
INCLUDES = -I $(INCLUDE_FOLDER)
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) -Imlx -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(CFLAGS) $(INCLUDES) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re