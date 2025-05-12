#include "so_long.h"

t_data	*ft_new_sprite(t_data *img, char *path)
{
	img->img = mlx_xpm_file_to_image(img->mlx, path,
			&img->x_size, &img->y_size);
	// if (img->img == NULL)
	// 	perror("Error\nImage failed to push to window");
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (img);
}

int	main(int ac, char **av)
{
	(void)ac;
	char	**map;
	t_data	*img;
	int i = 0;

	counter_lines(av[1]);
	bytes(av[1]);
	img = malloc(sizeof(t_data));
	map = sl_read(av);
	if (map != NULL)
	{
		while (map[i])
		{
			printf("línea %d del mapa: %s\n",i + 1, map[i]);
			i++;
			if (map[i] == NULL) 
			{
        		printf("Se alcanzó el final del mapa.\n");
			}	
		}
	}
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, 1920, 1080, "Hello world!");
	img->img = mlx_new_image(img->mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								&img->endian);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 64, 64);
	put_map(img);
	mlx_loop(img->mlx);
}