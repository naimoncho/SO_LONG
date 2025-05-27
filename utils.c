#include "so_long.h"

int	bytes_fd(char *map)
{
	int	y;

	y = 0;
	while(map[y] != '\0' && map[y] != '\n')
		y ++;
	return (y);
}
int	count_lines_fd(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while(map[y][x] != '\0' && map[y][x] != '\n')
			x++;
		y++;
	}
	return (y);
}

void fill(char **tmap, int y, int x, char target) 
{
	if (y < 0 || y < 0 || y >= count_lines_fd(tmap) || x >= bytes_fd(tmap[0]))
		return ;
	if (tmap[y][x] == 'F' || tmap[y][x] == target)
		return ;
	tmap[y][x] = 'F';
	fill(tmap, target, y - 1, x);
	fill(tmap, target, y + 1, x);
	fill(tmap, target, y, x - 1);
	fill(tmap, target, y, x + 1);
}
