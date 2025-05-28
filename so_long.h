/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:43:48 by ncheniou          #+#    #+#             */
/*   Updated: 2025/05/28 18:42:31 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "printf/ft_printf.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <stdarg.h>
# include <limits.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	void	*mlx;
	void	*mlx_win;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x_size;
	int		y_size;
	int		collectible;
	int		x_pos;
	int		y_pos;
	int		steps;
	char	**map;
}				t_data;

// CREATIONS OF SPRITE
t_data	*ft_new_sprite(t_data *img, char *path);
// MAP READ TOOLS
int		counter_lines(char *av);
int		bytes(char *av);
int		count_lines_fd(char **map);
int		bytes_fd(char *map);
char	**sl_read(char **av);
// PUT SPRITES ON MAP 
void	put_floor(char **map, t_data *img);
void	put_floor(char **map, t_data *img);
void	put_collect(char **map, t_data *img);
void	put_exit(char **map, t_data *img);
void	put_mew(char **map, t_data *img);
void	put_map(t_data *img);
// PARSING KEY
void	free_game(t_data *img);
int		close_wind(t_data *img);
int		check_player(char **map, int p);
void	check_valid_moves(t_data *img);
// MOVEMENTS
int		moves(int key, t_data *img);
void	move_right(t_data *img);
void	move_up(t_data *img);
void	move_up(t_data *img);
void	move_down(t_data *img);
// PARSING
void	fill(char **tmap, char target, int y, int x);
int		check_wall(char **map);
int		check_collectible(int x, int y, char **map);
int		check_exit(int x, int y, char **map);
int		check_fill(char **fill_map);
int		check_extension_av(char *s);
char	**change_map(char **av);
int		parse_map(char **map, char **av);

#endif