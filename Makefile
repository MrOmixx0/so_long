NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = src/main.c
OBJS = $(SRCS:.c=.o)
LIBS = -lmlx -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
