#include "so_long.h"

void	close_w(t_data *img)
{
	mlx_destroy_window(img->mlx, img->mlx_win);
	free(img->map);
	free(img);
	exit(EXIT_SUCCESS);
}

int	close_wind(t_data *img)
{
	ft_printf("termine\n");
	close_w(img);
	return (0);
}