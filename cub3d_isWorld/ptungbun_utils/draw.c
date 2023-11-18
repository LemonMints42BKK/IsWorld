/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:26:11 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/18 20:16:14 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
# include "../game_setup.h"

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

void	print_solid_square(t_data *img, t_point p, unsigned int color)
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
		{
			my_mlx_pixel_put(img, p.x + i++, p.y + j, color);
		}
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


void	background(t_var *vars, unsigned int color)
{
    t_point upper_left;
    t_point lower_right;
    
    set_point(&upper_left, 0, 0, 0);
    set_point(&lower_right, (*vars).scene->w, (*vars).scene->h, 0);
    print_bg((*vars).bgimg, upper_left, lower_right, color);
	mlx_put_image_to_window((*vars).mlx, (*vars).win, (*vars).bgimg->img, 0, 0);
}

void    minimap(t_var *vars, unsigned int color)
{   
    int w;
    int h;
    int x;
    int y;
    
    int xo;
    int yo;
    int mapx;
    int mapy;
    int maps;
    t_point upper_left;
    t_point lower_right;
    t_point begin;
    t_point end;

    w = 320;
    h = 384;
    set_point(&upper_left, 0, 0, 0);
    set_point(&lower_right, w, h, 0);
    print_bg((*vars).mini_img, upper_left, lower_right, color);
    x = 0;
    y = 0;
    mapx = 10;
    mapy = 12; 
    maps = 32; 
    while (y < mapy)    
    {
        x = 0;
        while (x < mapx)
        {
            xo = x * maps;
            yo = y * maps;
            set_point(&begin, xo +1 , yo + 1, 0);
            set_point(&end, xo + maps -1 , yo + maps -1, 0);
            if ((*vars).scene->map[y * mapx + x] == 1)
                print_bg((*vars).mini_img, begin, end, 0x66FFFFFF);
            else if ((*vars).scene->map[y * mapx + x] == 0)
                print_bg((*vars).mini_img, begin, end, 0x66000000);
            else if ((*vars).scene->map[y * mapx + x] == -1)
                print_bg((*vars).mini_img, begin, end, 0x66AEB6BF );
            x++;
        }
        y++;
    }
    mlx_put_image_to_window((*vars).mlx, (*vars).win, (*vars).mini_img->img, 10, 10);  
}