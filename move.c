#include "so_long.h"

void	move_right(t_data *img)
{
	if (img->map[img->y_pos][img->x_pos + 1] == '1')
		return ;
	img->x_pos = img->x_pos + 1;
	check_valid_moves(img);
	img = ft_new_sprite(img, "./pixels/mew.xpm")
	mlx_put_image_to_window(img->mlx, img->mlx_win,
				img->img, x * 64, y * 64);
	if (img->map[img->y_pos][img->x_pos - 1] != 'E' || img->objects != 0)
	{
		img = ft_new_sprite(img, "./pixels/mar.xpm")
		mlx_put_image_to_window(img->mlx, img->mlx_win,
				img->img, x * 64, y * 64);
	}
	ft_printf("\nSteps: %i\n", img->steps += 1);
}

void	move_up(t_data *img)
{
	if (img->map[img->y_pos - 1][img->x_pos] == '1')
		return ;
	img->y_pos = img->y_pos - 1;
	check_valid_moves(img);
	img = ft_new_sprite(img, "./pixels/mew.xpm")
	mlx_put_image_to_window(img->mlx, img->mlx_win,
				img->img, x * 64, y * 64);
	if (img->map[img->y_pos][img->x_pos - 1] != 'E' || img->objects != 0)
	{
		img = ft_new_sprite(img, "./pixels/mar.xpm")
		mlx_put_image_to_window(img->mlx, img->mlx_win,
				img->img, x * 64, y * 64);
	}
	ft_printf("\nSteps: %i\n", img->steps += 1);
}

void	move_left(t_data *img)
{
	if (img->map[img->y_pos][img->x_pos - 1] == '1')
		return ;
	img->x_pos = img->x_pos - 1;
	check_valid_moves(img);
	img = ft_new_sprite(img, "./pixels/mew.xpm")
	mlx_put_image_to_window(img->mlx, img->mlx_win,
				img->img, x * 64, y * 64);
	if (img->map[img->y_pos][img->x_pos - 1] != 'E' || img->objects != 0)
	{
		img = ft_new_sprite(img, "./pixels/mar.xpm")
		mlx_put_image_to_window(img->mlx, img->mlx_win,
				img->img, x * 64, y * 64);
	}
	ft_printf("\nSteps: %i\n", img->steps += 1);
}

void	move_down(t_data *img)
{
	if (img->map[img->y_pos + 1][img->x_pos] == '1')
		return ;
	img->y_pos = img->y_pos + 1;
	check_valid_moves(img);
	img = ft_new_sprite(img, "./pixels/mew.xpm")
	mlx_put_image_to_window(img->mlx, img->mlx_win,
				img->img, x * 64, y * 64);
	if (img->map[img->y_pos][img->x_pos - 1] != 'E' || img->objects != 0)
	{
		img = ft_new_sprite(img, "./pixels/mar.xpm")
		mlx_put_image_to_window(img->mlx, img->mlx_win,
				img->img, x * 64, y * 64);
	}
	ft_printf("\nSteps: %i\n", img->steps += 1);
}