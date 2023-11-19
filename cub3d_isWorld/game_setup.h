/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:31:21 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/19 18:30:18 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_SETUP_H
# define GAME_SETUP_H

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
	int s; //size
}	t_point;

typedef struct s_pos
{
	t_point	*mapp;
	t_point *pos;
	int		ms;
}	t_pos;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		llen;
	int		endian;
}	t_data;

typedef struct s_map
{
	int	mapx;
	int	mapy;
	int maps;
	int	*map;
}	t_map;

typedef struct s_frame
{
	int	w;//width
	int	h;//height
	t_pos	*p;//player position
	unsigned int	bgc; //backgound color
	t_map	*map;
}	t_frame; 

typedef struct t_var
{
	void	*mlx; //mlx_init()
	void	*win; //mlx_new_window()
	t_data	*bgimg; //mlx_new_image()
	t_data	*mini_img;
	t_frame *scene;
}	t_var;

#endif
