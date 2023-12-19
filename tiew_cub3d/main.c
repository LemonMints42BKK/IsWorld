#include "game.h"
#include "cub3d.h"

void	init_main_struct(t_main *main_struc)
{
	t_mlx	*main_mlx = malloc(sizeof(t_mlx));
	t_data	*main_img = malloc(sizeof(t_data));
	t_data	*mini_img = malloc(sizeof(t_data));


	t_map	*viewmap = malloc(sizeof(t_map));
	int		**mmap = malloc(sizeof(int *) * 5);
	t_pos	*player = malloc(sizeof(t_pos));
	t_ray	*ray = malloc(sizeof(t_ray));

	//main veiwpoint
	main_mlx->mlx = mlx_init();
	main_mlx->win = mlx_new_window(main_mlx, 1440, 810, "cub3D");
	main_img->img = mlx_new_image(main_mlx, 1440, 810);
	main_img->addr = mlx_get_data_addr(main_img->img, &main_img->bpp, &main_img->llen, &main_img->endian);
	main_mlx->img = main_img;
	//minimap viewpoint
	mini_img->img = mlx_new_image(main_mlx, 60, 60);
	mini_img->addr = mlx_get_data_addr(mini_img->img, &mini_img->bpp, &mini_img->llen, &mini_img->endian);
	main_mlx->mini_img = mini_img;

	main_struc->main_mlx = main_mlx;

	//map
	viewmap->mapx = 5;
	viewmap->mapy = 5;
	viewmap->maps = 12;
	int map[5][5] = {{1,1,1,1,1}, {1,0,0,0,1}, {1,0,0,0,1}, {1,0,0,0,1}, {1,1,1,1,1}};
	mmap = (int **)map;
	viewmap->map = mmap;
	main_struc->map = viewmap;

	//player
	player->px = 2;
	player->py = 2;
	player->mapp.x =(viewmap->maps / 2) * (player->px + 1);
	player->mapp.y =(viewmap->maps / 2) * (player->px + 1);
	main_struc->player = player;

	//ray return to lowdev page fot info
	ray->ray_dist_on_cam = 0;
	ray->ray_coor = malloc(sizeof(t_coor));
	ray->ray_coor->x = 0;
	ray->ray_coor->y = 0;
	ray->init_ray_dist = malloc(sizeof(t_coor));
	ray->init_ray_dist->x = 0;
	ray->init_ray_dist->y = 0;
	ray->ray_dist = malloc(sizeof(t_coor));
	ray->ray_dist->x = 0;
	ray->ray_dist->y = 0;

	//noidea about get time functions
	main_struc->n_ray = 1440;
	main_struc->cur_time = 0;
	main_struc->old_time = 0;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;
    
	dst = data->addr + (y * data->llen + x * (data->bpp/ 8));
	*(unsigned int*)dst = color;
}

void    print_bg(t_data *img, t_coor begin, t_coor end, unsigned int color)
{
    int i;
    int j;

    i = begin.x;
    j = begin.y;
    while (j < end.y)
    {
        i = begin.x;
        while (i < end.x)
        {    my_mlx_pixel_put(img, i++, j, color);}
        j++;
    }
}

void	set_point(t_coor *p,double x, double y)
{
	(*p).x = x;
	(*p).y = y;
}

// void	draw_minimap(t_main *main_struc, unsigned int color)
// {
// 	t_mlx	*main_mlx = main_struc->main_mlx;
// 	t_data	*mini_img = main_mlx->mini_img;
// 	t_map	*viewmap = main_struc->map;
// 	t_pos	*player = main_struc->player;
// 	t_coor begin;
// 	t_coor end;
// 	int x;
// 	int y;
// 	int xo;
// 	int yo;
// 	(void)color;
// 	(void)player;

// 	x = 0;
// 	y = 0;
// 	while (y < viewmap->mapy)
// 	{
// 		x = 0;
// 		while (x < viewmap->mapx)
// 		{
// 			xo = x * viewmap->maps;
// 			yo = y * viewmap->maps;
// 			set_point(&begin, xo +1 , yo + 1);
// 			set_point(&end, xo + viewmap->maps -1 , yo + viewmap->maps -1);
// 			if (viewmap->map[y][x] == 1)
// 				print_bg(mini_img, begin, end, 0x66FFFFFF);
// 			else if (viewmap->map[y][x] == 0)
// 				print_bg(mini_img, begin, end, 0x66000000);
// 			else if (viewmap->map[y][x] == -1)
// 				print_bg(mini_img, begin, end, 0x66AEB6BF );
// 			x++;
// 		}
// 		y++;
// 	}

// 	mlx_put_image_to_window(main_mlx->mlx, main_mlx->win, mini_img->img, 10, 10);
// }

void	draw_background(t_main *main_struc, int color)
{
	t_mlx	*main_mlx = main_struc->main_mlx;
	t_data	*main_img = main_mlx->img;
	t_coor	begin;
	t_coor	end;

	set_point(&begin, 0, 0);
	set_point(&end, 1440, 810);
	print_bg(main_img, begin, end, color);
//	mlx_put_image_to_window(main_mlx->mlx, main_mlx->win, main_img->img, 0, 0);
}

int	display(t_main *main_struc)
{
//	draw_minimap(main_struc, 0xCCBFC9CA);
	draw_background(main_struc, 0x0034495E);
	
	return (EXIT_SUCCESS);
}

int	cub3d_main_exit(t_mlx *main_mlx)
{
	mlx_destroy_image(main_mlx->mlx, main_mlx->img->img);
	mlx_destroy_image(main_mlx->mlx, main_mlx->mini_img->img);
	mlx_destroy_window(main_mlx->mlx, main_mlx->win);
	free(main_mlx);
	exit(0);
	return (EXIT_SUCCESS);
}

int	cub3d_exit(t_main *main_struc)
{
	t_mlx	*main_mlx = main_struc->main_mlx;
	mlx_destroy_image(main_mlx->mlx, main_mlx->img->img);
	mlx_destroy_image(main_mlx->mlx, main_mlx->mini_img->img);
	mlx_destroy_window(main_mlx->mlx, main_mlx->win);
	free(main_mlx);
	free(main_struc->map);
	free(main_struc->player);
	free(main_struc->ray->ray_coor);
	free(main_struc->ray->init_ray_dist);
	free(main_struc->ray->ray_dist);
	free(main_struc->ray);
	exit(0);
	return (EXIT_SUCCESS);
}

int	reycaster_loop(t_main *main_struc)
{
	mlx_hook(main_struc->main_mlx->win, 17, 0, cub3d_main_exit, main_struc->main_mlx);
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
		return (cub3d_exit(&main_struc), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}