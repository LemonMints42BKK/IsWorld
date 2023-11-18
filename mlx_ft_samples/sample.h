/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:09:34 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/17 12:36:52 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_H
# define SAMPLE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <OpenGL/gl3.h>
# include "mlx/mlx.h"

typedef struct s_color
{
	int t; //transparency
	int	r; //red
	int	g; //green
	int	b; //blue
}	t_color;

typedef struct s_point
{
	int	x; //x coordinate
	int	y; //y coordinate
	int	s; //size
}	t_point;

typedef struct s_line
{
	t_point	*s; //start
	t_point	*e; //end
	int	t; //thickness
}	t_line;

typedef struct s_circle
{
	t_point	*center;
	int		radius;
	int		c;
}	t_circle;

typedef struct s_triangle
{
	t_point	*up;
	t_point	*left;
	t_point	*right;
	int		c;
}	t_triangle;

typedef struct s_rectangle
{
	t_point	*up_l;
	t_point	*low_r;
	int		c;
}	t_rectangle;

typedef struct s_map
{
	int	mapX; //horizontal size of map
	int	mapY; //vertical size of map
	int	mapS; //map square size
//	char	*map;
}	t_map;

typedef struct s_frame
{
	// t_vars	*vars;
	int		width;
	int		height;
	int		bg_color;
	t_map	plan;
	t_point p;
	t_point mini;
}	t_frame;

typedef struct s_data {
	void	*img; // send to mlx_new_image()
	char	*addr; // get value from mlx_get_data_addr()
	int		bits_per_pixel; // set value by mix_get_data_addr()
	int		line_length; // set value by mlx_get_data_addr()
	int		endian; // set value by mlx_get_data_addr()
}	t_data;

typedef struct t_vars
{
	void	*mlx; //mlx_init()
	void	*win; //mlx_new_window()
	t_data	*img; //mlx_new_image()
	t_frame *scene;
}	t_vars;

#endif
