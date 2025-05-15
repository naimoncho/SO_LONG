#include "so_long.h"

void	move_right(t_data *img)
{
	if (img->map[img->y_pos][img->x_pos + 1] == '1')
		return ;
		img->x_pos = img->x_pos + 1;
	mlx_put_image_to_window(img->mlx, img->mlx_win,
						 img->img, x * 64, y * 64);
}