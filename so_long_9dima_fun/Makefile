CC = cc

FLAGS = -Wall -Werror -Wextra

NAME = so_long



LIB_PATH =	libft

SRC_PATH =	src

OBJ_PATH =	obj



LIB_NAME =	libft.a

SRC_NAME =	game_init.c main.c map_parser.c render.c input.c utils.c validate_map.c

OBJ_NAME = $(SRC_NAME:.c=.o)



INC =	libft/include/libft.h 			\
		libft/include/get_next_line.h	\
		libft/include/ft_printf.h

SRC =	$(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ =	$(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

LIB =	$(addprefix $(LIB_PATH)/, $(LIB_NAME))

INC_FLAGS =	-Iinclude -Ilibft/include/ -I/usr/include/minilibx-linux/



all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIB_PATH)
	$(CC) $(OBJ) $(LIB) -o $@ -L/usr/include/minilibx-linux/ -lmlx -lX11 -lXext -lm -lz 

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(dir $(OBJ))
	@$(CC) $(FLAGS) -o $@ -c $< $(INC_FLAGS)
	@echo $<
	
clean:
	$(MAKE) -C $(LIB_PATH) fclean
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
