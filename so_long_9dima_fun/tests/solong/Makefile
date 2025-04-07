NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx
MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = $(MLX_LIB) -L$(MLX_DIR) -lXext -lX11 -lm -lbsd

SRCS = main.c render_map.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

