/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:01:26 by ncheniou          #+#    #+#             */
/*   Updated: 2025/05/28 12:01:41 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_data *img)
{
	if (img->map[img->y_pos][img->x_pos + 1] == '1')
		return ;
	img->x_pos = img->x_pos + 1;
	check_valid_moves(img);
	img = ft_new_sprite(img, "./pixels/mew.xpm");
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->img, img->x_pos * 64, img->y_pos * 64);
	if (img->map[img->y_pos][img->x_pos - 1] != 'E' || img->collectible != 0)
	{
		img = ft_new_sprite(img, "./pixels/mar.xpm");
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->img, (img->x_pos - 1) * 64, img->y_pos * 64);
	}
	ft_printf("\nSteps: %i\n", img->steps += 1);
}

void	move_up(t_data *img)
{
	if (img->map[img->y_pos - 1][img->x_pos] == '1')
		return ;
	img->y_pos = img->y_pos - 1;
	check_valid_moves(img);
	img = ft_new_sprite(img, "./pixels/mew.xpm");
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->img, img->x_pos * 64, img->y_pos * 64);
	if (img->map[img->y_pos + 1][img->x_pos] != 'E' || img->collectible != 0)
	{
		img = ft_new_sprite(img, "./pixels/mar.xpm");
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->img, img->x_pos * 64, (img->y_pos + 1) * 64);
	}
	ft_printf("\nSteps: %i\n", img->steps += 1);
}

void	move_left(t_data *img)
{
	if (img->map[img->y_pos][img->x_pos - 1] == '1')
		return ;
	img->x_pos = img->x_pos - 1;
	check_valid_moves(img);
	img = ft_new_sprite(img, "./pixels/mew.xpm");
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->img, img->x_pos * 64, img->y_pos * 64);
	if (img->map[img->y_pos][img->x_pos + 1] != 'E' || img->collectible != 0)
	{
		img = ft_new_sprite(img, "./pixels/mar.xpm");
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->img, (img->x_pos + 1) * 64, img->y_pos * 64);
	}
	ft_printf("\nSteps: %i\n", img->steps += 1);
}

void	move_down(t_data *img)
{
	if (img->map[img->y_pos + 1][img->x_pos] == '1')
		return ;
	img->y_pos = img->y_pos + 1;
	check_valid_moves(img);
	img = ft_new_sprite(img, "./pixels/mew.xpm");
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->img, img->x_pos * 64, img->y_pos * 64);
	if (img->map[img->y_pos - 1][img->x_pos] != 'E' || img->collectible != 0)
	{
		img = ft_new_sprite(img, "./pixels/mar.xpm");
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->img, img->x_pos * 64, (img->y_pos - 1) * 64);
	}
	ft_printf("\nSteps: %i\n", img->steps += 1);
}

int	moves(int key, t_data *img)
{
	if (key == 119)
		move_up(img);
	if (key == 97)
		move_left(img);
	if (key == 115)
		move_down(img);
	if (key == 100)
		move_right(img);
	if (key == 65307)
	{
		ft_printf("GAME OVER\n");
		free_game(img);
	}
	return (0);
}
