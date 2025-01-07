# Variables
NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude -Iminilibx-linux
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a
SRC_DIR = src
SRC_FILES = events.c ft_putstr_fd.c ft_strcmp.c ft_strlen.c init_fractal.c main.c math_utils.c render.c
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ_DIR = obj
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIBS = -L$(MLX_DIR) -lmlx -lm -lXext -lX11

# Reglas
all: $(NAME)

$(NAME): $(OBJ) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(MLX):
	@make -C $(MLX_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

