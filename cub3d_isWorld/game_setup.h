/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:31:21 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/15 22:03:28 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_SETUP_H
# define GAME_SETUP_H

# include "libft/libft.h"
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

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		llen;
	int		endian;
}	t_data;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_point
{
	int	x;
	int	y;
	int s;
}	t_point;

typedef struct s_pos
{
	t_point *pos;
	t_point	*p_pos;
	bool	one_player;
	char	dir;
	int		ms;
}	t_pos;

typedef struct s_map
{
	t_list	*iden;
	bool	map_begin;
	int		line_map_begin;
	char	**map_original;
	int		mapx;
	int		mapy;
	int 	maps;
	int		**map;
}	t_map;

typedef struct s_frame
{
	int				w;//width
	int				h;//height
	unsigned int	bgc; //backgound color
	t_pos			*p;//player position
	t_map			*map;
}	t_frame; 

typedef struct t_var
{
	void	*mlx; //main_mlx
	void	*win; //main_window
	t_data	*bgimg; //main_image
	t_data	*mini_img;
	t_frame *scene;
}	t_var;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_data	*img;
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
#endif
