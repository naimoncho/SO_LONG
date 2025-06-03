/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:58:33 by ncheniou          #+#    #+#             */
/*   Updated: 2025/06/03 13:43:04 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_data *img)
{
	if (img->img)
		mlx_destroy_image(img->mlx, img->img);
	mlx_clear_window(img->mlx, img->mlx_win);
	mlx_destroy_window(img->mlx, img->mlx_win);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	ft_free_all(img->map);
	free(img);
	exit(EXIT_SUCCESS);
}

int	close_wind(t_data *img)
{
	ft_printf("termine\n");
	free_game(img);
	return (0);
}
