/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:00:21 by ncheniou          #+#    #+#             */
/*   Updated: 2025/05/28 12:00:22 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_floor(char **map, t_data *img)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0' && map[y][x] != '\n')
		{
			if (map[y][x] == '1')
			{
				img = ft_new_sprite(img, "./pixels/roca1.xpm");
				mlx_put_image_to_window(img->mlx, img->mlx_win,
					img->img, x * 64, y * 64);
			}
			else
			{
				img = ft_new_sprite(img, "./pixels/mar.xpm");
				mlx_put_image_to_window(img->mlx, img->mlx_win,
					img->img, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
}

void	put_collect(char **map, t_data *img)
{
	int	x;
	int	y;

	y = 0;
	img->collectible = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0' && map[y][x] != '\n')
		{
			if (map[y][x] == 'C')
			{
				img = ft_new_sprite(img, "./pixels/heal_ball.xpm");
				img->collectible += 1;
				mlx_put_image_to_window(img->mlx, img->mlx_win,
					img->img, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
}

void	put_exit(char **map, t_data *img)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0' && map[y][x] != '\n')
		{
			if (map[y][x] == 'E')
			{
				img = ft_new_sprite(img, "./pixels/exit.xpm");
				mlx_put_image_to_window(img->mlx, img->mlx_win,
					img->img, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
}

void	put_mew(char **map, t_data *img)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0' && map[y][x] != '\n')
		{
			if (map[y][x] == 'P')
			{
				img = ft_new_sprite(img, "./pixels/mew.xpm");
				img->x_pos = x;
				img->y_pos = y;
				mlx_put_image_to_window(img->mlx, img->mlx_win,
					img->img, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
}

void	put_map(t_data *img)
{
	put_floor(img->map, img);
	put_collect(img->map, img);
	put_mew(img->map, img);
}
