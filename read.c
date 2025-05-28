/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:02:37 by ncheniou          #+#    #+#             */
/*   Updated: 2025/05/28 13:33:32 by ncheniou         ###   ########.fr       */
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
	printf("%d\n", line);
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
	printf("%d\n", byte);
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
	map = (char **)malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (free(map), NULL);
	while (lines > 0)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
			break ;
		i++;
		lines--;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
