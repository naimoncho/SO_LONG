/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naimcheniounigomez <naimcheniounigomez@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:51:12 by ncheniou          #+#    #+#             */
/*   Updated: 2025/05/28 16:44:27 by naimcheniou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*ft_new_sprite(t_data *img, char *path)
{
	img->img = mlx_xpm_file_to_image(img->mlx, path,
			&img->x_size, &img->y_size);
	if (img->img == NULL)
		perror("Error\nImage failed to push to window");
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (img);
}

char	**change_map(char **av)
{
	char	**map;
	
	map = sl_read(av);
	return(map);
}

int	parse_map(char **map, char **av)
{
	char	**map_fill;

	if (!check_wall(map) || !check_collectible(0, 0, map))
		return (0);
	map_fill = change_map(av);
	if (!check_fill(map_fill))
	{
		ft_free_all(map_fill);
		return (0);
	}
	ft_free_all(map_fill);
	return (1);
}