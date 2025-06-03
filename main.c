/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:08:40 by ncheniou          #+#    #+#             */
/*   Updated: 2025/06/03 14:05:36 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_map_av(char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nNot compatible argument\n");
		exit(1);
	}
}

static void	init_struct(t_data **img, char **map)
{
	*img = (t_data *)malloc(sizeof(t_data));
	if (!img)
		exit(1);
	(*img)->mlx = mlx_init();
	(*img)->y_size = count_lines_fd(map) * 64;
	(*img)->x_size = bytes_fd(map[0]) * 64;
	(*img)->mlx_win = mlx_new_window((*img)->mlx, (*img)->x_size,
			(*img)->y_size, "So_long");
	(*img)->steps = 0;
	(*img)->map = map;
	(*img)->img = NULL;
}

int	main(int ac, char **av)
{
	char	**map;
	t_data	*img;

	if (ac != 2 || !check_extension_av(av[1]))
		return (ft_printf("Error\nNot compatible argument\n"), 1);
	check_map_av(av);
	map = sl_read(av);
	if (!map)
		return (ft_printf("Error\nNot compatible map\n"), 1);
	if (!parse_map(map, av))
		return (ft_free_all(map), ft_printf("Error\nNot compatible map\n"));
	init_struct(&img, map);
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