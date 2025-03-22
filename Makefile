CC = cc

FLAGS = -Wall -Werror -Wextra

NAME = so_long

LIB_PATH =	libft
SRC_PATH =	src
OBJ_PATH =	obj
MLX_PATH =	mlx

LIB_NAME =	libft.a
SRC_NAME =	game_init.c main.c map_parser.c render.c input.c utils.c validate_map.c check_path.c
OBJ_NAME = $(SRC_NAME:.c=.o)

INC =	libft/include/libft.h 			\
		libft/include/get_next_line.h	\
		libft/include/ft_printf.h

SRC =	$(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ =	$(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
LIB =	$(addprefix $(LIB_PATH)/, $(LIB_NAME))

INC_FLAGS =	-Iinclude -Ilibft/include/ -Imlx

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIB_PATH)
	$(MAKE) -C $(MLX_PATH)  # Compile MiniLibX
	$(CC) $(OBJ) $(LIB) -o $@ -Lmlx -lmlx -lX11 -lXext -lm -lz
	@echo "✅ Compilation successful!"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -o $@ -c $< $(INC_FLAGS)
	@echo "Compiled: $<"

clean:
	$(MAKE) -C $(LIB_PATH) fclean
	$(MAKE) -C $(MLX_PATH) clean  # Clean MiniLibX
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

