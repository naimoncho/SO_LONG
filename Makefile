NAME = so_long

MY_SOURCES = main.c read.c image_map.c close.c utils.c move.c check.c check_map.c  utils_map.c

MY_OBJECTS =  $(MY_SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIE  -g3 #-fsanitize=address
MLXFLAGS = -lX11 -lXext -lm
$(NAME): $(MY_OBJECTS)
	@${MAKE} -C ./libft
	@${MAKE} -C ./libft/printf
	@${MAKE} -C ./libft/get_next_line
	@${CC} ${CFLAGS} ${MY_OBJECTS} -L./minilibx-linux -lmlx -lXext -lX11 -lm ./libft/libft.a ./libft/printf/libftprintf.a ./libft/get_next_line/libftgetnextline.a -o $(NAME)


all: ${NAME}

%.o: %.c
	$(CC) -c $< -o $@

clean:
	@${MAKE} -C ./libft fclean
	@${MAKE} -C ./libft/printf fclean
	@${MAKE} -C ./libft/get_next_line fclean
	@rm -f $(MY_OBJECTS) $(NAME)


fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re