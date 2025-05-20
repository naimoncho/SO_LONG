#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "printf/ft_printf.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <stdarg.h>
# include <limits.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	void	*mlx;
	void	*mlx_win;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x_size;
	int		y_size;
    int     collectible;
    int     x_pos;
    int     y_pos;
	int		steps;
	char	**map;

}				t_data;

int     counter_lines(char *av);
int	    bytes(char *av);
char	**sl_read(char **av);
void	put_floor(char **map, t_data *img);
t_data	*ft_new_sprite(t_data *img, char *path);
void	put_floor(char **map, t_data *img);
void	put_collect(char **map, t_data *img);
void	put_exit(char **map, t_data *img);
void	put_mew(char **map, t_data *img);
void	put_map(t_data *img);
void	free_game(t_data *img);
int		close_wind(t_data *img);
void	check_player(char **map, int p);
void	check_valid_moves(t_data *img);

#endif