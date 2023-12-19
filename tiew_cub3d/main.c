#include "game.h"
#include "cub3d.h"

void	init_main_struct(t_main *main_struc)
{
	t_mlx	*main_mlx = malloc(sizeof(t_mlx));
	t_data	*main_img = malloc(sizeof(t_data));	
	t_data	*mini_img = malloc(sizeof(t_data));
	t_map	*map = malloc(sizeof(t_map));
	// t_pos	player;
	// t_ray	ray;
	main_mlx->main_img = main_img;
	main_mlx->mini_img = mini_img;
	main_struc->map = map;
	main_struc->main_mlx = main_mlx;

	main_mlx->mlx = mlx_init();
	main_mlx->win = mlx_new_window(main_mlx, 1440, 810, "cub3D");
	//main veiwpoint
	main_img->img = mlx_new_image(main_mlx, 1440, 810);
	main_img->addr = mlx_get_data_addr(main_img, &main_img->bpp, &main_img->llen, &main_img->endian);
	//minimap
	mini_img = mlx_new_image(main_struc->main_mlx, 60, 60);
	mini_img->addr = mlx_get_data_addr(mini_img, &mini_img->bpp, &mini_img->llen, &mini_img->endian);

	map->mapx = 5;
	map->mapy = 5;
	map->maps = 25;
	map->map[16] = 
	{
		1,1,1,1,1
		1,0,0,0,1
		1,0,N,0,1
		1,0,0,0,1
		1,1,1,1,1
	};


}
void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;
    
	dst = data->addr + (y * data->llen + x * (data->bpp/ 8));
	*(unsigned int*)dst = color;
}

int	display(t_main *main_struc)
{
	mlx_put_image_to_window(main_struc->main_mlx->mlx, main_struc->main_mlx->win, main_struc->main_mlx->main_img->img, 0, 0);
	return (EXIT_SUCCESS);
}

int	cub3d_exit(t_main *main_struc)
{
	mlx_destroy_image(main_struc->main_mlx->mlx, main_struc->main_mlx->main_img->img);
	mlx_destroy_image(main_struc->main_mlx->mlx, main_struc->main_mlx->mini_img->img);
	mlx_destroy_window(main_struc->main_mlx->mlx, main_struc->main_mlx->win);
	free(main_struc->main_mlx);
	free(main_struc->map);
	exit(0);
	return (EXIT_SUCCESS);
}

int	reycaster_loop(t_main *main_struc)
{
	mlx_hook(main_struc->main_mlx->win, 17, 0, cub3d_exit, main_struc);
	mlx_loop_hook(main_struc->main_mlx->mlx, display, main_struc);
	mlx_loop(main_struc->main_mlx->mlx);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_main	main_struc;
	
	(void)argc;
	(void)argv;	
	init_main_struct(&main_struc);
	// if(is_invalid_input(argv[1], &main_struc))
	// 	return (cub3d_exit(&main_struc), EXIT_FAILURE);
	if (reycaster_loop(&main_struc))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}