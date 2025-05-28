/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:35:40 by ncheniou          #+#    #+#             */
/*   Updated: 2025/05/28 19:24:20 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall(char **map)
{
	int	x;
	int	y;
	int	lines;
	int	byte;

	y = 0;
	lines = count_lines_fd(map);
	byte = bytes_fd(map[0]);
	if ((lines - 1) < 2 || (byte - 1) < 2)
		return (0);
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0' && map[y][x] != '\n')
		{
			if (map[0][x] != '1' || map[lines - 1][x] != '1'
					|| map[y][0] != '1' || map[y][byte - 1] != '1')
				return (0);
			x++;
		}
		if (byte != bytes_fd(map[y]))
			return (0);
		y++;
	}
	return (1);
}

int	check_collectible(int x, int y, char **map)
{
	int	player;
	int	exit;
	int	collectible;

	player = 0;
	exit = 0;
	collectible = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0' && map[y][x] != '\n')
		{
			if (map[y][x] == 'P')
				player ++;
			if (map[y][x] == 'C')
				collectible ++;
			if (map[y][x] == 'E')
				exit ++;
			x++;
		}
		y++;
	}
	if (player != 1 || exit != 1 || collectible < 0)
		return (0);
	return (1);
}

int	check_exit(int x, int y, char **map)
{
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0' && map[y][x] != '\n')
		{
			if (map[y][x] == 'C')
				return (0);
			if (map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_fill(char **fill_map)
{
	fill(fill_map, '1', check_player(fill_map, 1), check_player(fill_map, 0));
	if (!check_exit(0, 0, fill_map))
		return (0);
	return (1);
}
