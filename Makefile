NAME = so_long

MY_SOURCES = start.c read.c image_map.c close.c utils.c move.c check.c

MY_OBJECTS =  $(MY_SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fPIE  -g3 -fsanitize=address
MLXFLAGS = -lX11 -lXext -lm
$(NAME): $(MY_OBJECTS)
	@${MAKE} -C ./libft
	@${MAKE} -C ./printf
	@${MAKE} -C ./get_next_line
	@${CC} ${CFLAGS} ${MY_OBJECTS} -L./minilibx-linux -lmlx -lXext -lX11 -lm ./libft/libft.a ./printf/libftprintf.a ./get_next_line/libftgetnextline.a -o $(NAME)


all: ${NAME}

%.o: %.c
	$(CC) -c $< -o $@

clean:
	@${MAKE} -C ./libft fclean
	@${MAKE} -C ./printf fclean
	@${MAKE} -C ./get_next_line fclean
	@rm -f $(MY_OBJECTS) $(NAME)


fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re