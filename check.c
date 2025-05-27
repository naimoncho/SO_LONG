#include "so_long.h"

int		check_player(char **map, int p)
{
	int	x;
	int	y;

	y = 0;
	while (y < count_lines_fd(map))
	{
		x = 0;
		while(map[y][x] != '\0' && map[y][x] != '\n')
		{
			if (map[y][x] == 'P')
			{
				if (p == 0)
					return (x);
				if (p == 1)
					return (y);
			}
			x++;
		}
		y++;
	}
	return (p);
}

void	check_valid_moves(t_data *img)
{
	if (img->map[img->y_pos][img->x_pos] == 'C')
	{
		img = ft_new_sprite(img, "./pixels/mar.xpm");
		mlx_put_image_to_window(img->mlx, img->mlx_win, 
				img->img, img->x_pos * 64, img->y_pos * 64);
		img->collectible -= 1;
		img->map[img->y_pos][img->x_pos] = '0';
	}
	if (img->map[img->y_pos][img->x_pos] == 'E' && img->collectible == 0)
	{
		ft_printf("\nSteps = %i\n", img->steps += 1);
		ft_printf("Victory\n");
		free_game(img);
	}
	if (img->collectible == 0)
		put_exit(img->map, img);
}
