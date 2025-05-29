/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:51:12 by ncheniou          #+#    #+#             */
/*   Updated: 2025/05/29 14:05:04 by ncheniou         ###   ########.fr       */
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
	return (map);
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

int	check_extension_av(char *s)
{
	char	*ext;
	int		i;

	i = ft_strlen(s) - 4;
	ext = ft_substr(s, i, 4);
	if (ft_strnstr(ext, ".ber", 4))
		return (free(ext), 1);
	return (free(ext), 0);
}
