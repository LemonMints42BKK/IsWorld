/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01drawing_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:27:31 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/13 20:57:21 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/game_setup.h"

//Fountion to convert RGB values to a hexadecimal integer
int     color3f(int r, int g, int b)
{
    return (r << 16 | g << 8 | b);
}

//a function that will mimic the behaviour of mlx_pixel_put but will simply be many times faster
void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;
    
	dst = data->addr + (y * data->llen + x * (data->bpp/ 8));
	*(unsigned int*)dst = color;
}

void	set_point(t_point *p,int x, int y, int s)
{
	(*p).x = x;
	(*p).y = y;
	(*p).s = s;
}

void	print_player_charater(t_data *img, t_point p, unsigned int color)
{
	int i;
	int j;
	int s;

	i = 0;
	j = 0;
	s = p.s;
	if (color == 0)
		color = 0x0059515E;
	if (s < 1)
		s = 1;
	while (j < s)
	{
		i = 0;
		while (i < s)
		{
			if (j < ((s * 2) / 3) && i >= (s / 3) && i < ((s * 2) / 3))
				my_mlx_pixel_put(img, p.x + i, p.y + j, color);
			if (j >= ((s * 2) / 3))
				my_mlx_pixel_put(img, p.x + i, p.y + j, color);
			i++;
		}
		j++;
	}
}

void	print_square_point(t_data *img, t_point p, unsigned int color)
{
	int i;
	int j;
	int s;

	i = 0;
	j = 0;
	s = p.s;
	if (color == 0)
		color = 0x0059515E;
	if (s < 1)
		s = 1;
	while (j++ < s)
	{
		i = 0;
		while (i < s)
			my_mlx_pixel_put(img, p.x + i++, p.y + j, color);
	}
}

void    print_bg(t_data *img, t_point begin, t_point end, unsigned int color)
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