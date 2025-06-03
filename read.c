/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:02:37 by ncheniou          #+#    #+#             */
/*   Updated: 2025/06/03 17:11:13 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	counter_lines(char *av)
{
	int		fd;
	int		line;
	int		byte;
	char	character[1];

	fd = open(av, O_RDONLY);
	line = 1;
	byte = 1;
	while (byte != 0)
	{
		byte = read(fd, character, 1);
		if (character[0] == '\n')
			line ++;
	}
	close(fd);
	return (line - 1);
}

int	bytes(char *av)
{
	int		fd;
	int		byte_read;
	int		byte;
	char	character[1];

	fd = open(av, O_RDONLY);
	byte = 0;
	byte_read = 1;
	while (byte_read != 0 && character[0] != '\n')
	{
		byte_read = read(fd, character, 1);
		if (character[0] != '\n')
			byte ++;
	}
	close(fd);
	return (byte);
}

char	**sl_read(char **av)
{
	int		i;
	int		fd;
	char	**map;
	int		lines;

	i = 0;
	lines = counter_lines(av[1]) + 1;
	map = (char **)ft_calloc(sizeof(char *), (lines + 1));
	if (!map)
		return (NULL);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (free(map), NULL);
	while (lines > 0)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
			return (ft_printf("Error\n"), exit(1), NULL);
		i++;
		lines--;
	}
	i--;
	if (map[i] && map[i][ft_strlen(map[i]) - 1] == '\n')
		return (ft_free_all(map), NULL);
	return (close(fd), map);
}
