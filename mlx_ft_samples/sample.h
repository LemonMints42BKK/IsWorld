/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:09:34 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/15 22:24:46 by pnopjira         ###   ########.fr       */
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

typedef struct t_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_map
{
	const int		mapX;
	const int		mapY;
	const int		mapS;
//	char	*map;
}	t_map;

typedef struct s_color
{
	int		t;
	int		r;
	int		g;
	int		b;
}	t_color;

typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

typedef struct s_line
{
	t_point	*start;
	t_point	*end;
}	t_line;

typedef struct s_square
{
	t_point	*upper_left;
	t_point	*lower_right;
}	t_square;

#endif
