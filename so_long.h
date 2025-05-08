#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "printf/ft_printf.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <stdarg.h>
# include <limits.h>

int     counter_lines(char *av);
int	    bytes(char *av);
char	**sl_read(char **av);

#endif