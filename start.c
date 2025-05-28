/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:08:40 by ncheniou          #+#    #+#             */
/*   Updated: 2025/05/28 13:51:08 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	**map;
	t_data	*img;

	(void)ac;
	counter_lines(av[1]);
	bytes(av[1]);
	map = sl_read(av);
	img = (t_data *)malloc(sizeof(t_data));
	img->mlx = mlx_init();
	img->y_size = count_lines_fd(map) * 64;
	img->x_size = bytes_fd(map[0]) * 64;
	img->mlx_win = mlx_new_window(img->mlx, img->x_size,
			img->y_size, "So_long");
	img->img = mlx_new_image(img->mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 64, 64);
	img->map = map;
	put_map(img);
	mlx_hook(img->mlx_win, 17, 0, close_wind, img);
	mlx_key_hook(img->mlx_win, moves, img);
	mlx_loop(img->mlx);
}

	// int i = 0;
	// if (map != NULL)
	// {
	// 	while (map[i])
	// 	{
	// 		printf("línea %d del mapa: %s\n",i + 1, map[i]);
	// 		i++;
	// 		if (map[i] == NULL) 
	// 		{
	//			printf("Se alcanzó el final del mapa.\n");
	// 		}	
	// 	}
	// }