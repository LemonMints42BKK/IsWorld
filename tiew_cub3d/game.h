#ifndef GAME_H
# define GAME_H

# include <stdbool.h>

typedef struct s_coor //coordinate
{
	double	x;
	double	y;
}	t_coor;

typedef struct s_ray //raycasting
{
	double	ray_dist_on_cam;
	t_coor	*ray_coor;
	t_coor	*init_ray_dist;
	t_coor	*ray_dist;
}	t_ray;

typedef struct s_pos
{
	int		px;
	int		py;
	t_coor 	mapp;
}	t_pos;

typedef struct s_map
{
	int		mapx;
	int		mapy;
	int 	maps;
	int		*map;
}	t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		llen;
	int		endian;
}	t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_data	*img;
	t_data	*mini_img;
}	t_mlx;

typedef struct s_main
{
	t_mlx 	*main_mlx;
	t_map	*map;
	t_pos	*player;
	t_ray	*ray;
	int		n_ray;
	double	cur_time;
	double	old_time;
}	t_main;
# endif