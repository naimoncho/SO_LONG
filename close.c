#include "so_long.h"

void	free_game(t_data *img)
{
	mlx_destroy_window(img->mlx, img->mlx_win);
	free(img->map);
	free(img);
	exit(EXIT_SUCCESS);
}

int	close_wind(t_data *img)
{
	ft_printf("termine\n");
	free_game(img);
	return (0);
}