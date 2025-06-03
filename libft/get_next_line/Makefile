NAME = libftgetnextline.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -fPIE
SRCS =	get_next_line_utils.c \
		get_next_line.c \

OBJS = $(SRCS:.c=.o)
AR = ar
ARFLAGS = rcs

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re