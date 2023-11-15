/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:06:45 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/15 22:30:51 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sample.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8)); //calculate the memory offset using the line length set by mlx_get_data_addr
	*(unsigned int*)dst = color; //write the color to the memory address
}

int	create_trgb(int t, int r, int g, int b) //the ARGB values
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	draw_point(t_data *img, int W, t_point P, int color)
{
	int i = 0;
	int j = 0;

	if (W < 1)
		W = 1;
	else if (W > 15)
		W = 15;
	while (j++ < W)
	{
		i = 0;
		while (i < W)
		{
			my_mlx_pixel_put(img, P.x + i++, P.y + j, color);
		}
	}
}

void draw_line(t_data *img, int W, t_line *l, int color)
{
	t_point d;
	t_point P;
	t_point Pinc;

	d.x = l->end->x - l->start->x;
	d.y = l->end->y - l->start->y;
	int steps = abs(d.x) > abs(d.y) ? abs(d.x) : abs(d.y);
	Pinc.x = d.x / (float)steps;
	Pinc.y = d.y / (float)steps;
	P.x = l->start->x;
	P.y = l->start->y;
	int i = 0;
	(void)W;
	while (i <= steps)
	{
		draw_point(img, W, P, color);
		P.x += Pinc.x;
		P.y += Pinc.y;
		i++;
	}
}

void draw_squares (t_data *img, int W, t_point P, int color)
{
	int i = 0;
	int j = 0;

	if (W < 1)
		W = 1;
	else if (W > 15)
		W = 15;
	while (j++ < W)
	{
		i = 0;
		while (i < W)
		{
			my_mlx_pixel_put(img, P.x + i++, P.y + j, color);
		}
	}
}

int	buttons(int key,t_vars *vars)
{
	if (key == 53) // Prass ESC to exit
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int main(void)
{
	t_vars	vars;
	t_data	img;
	//make a window frame
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1024, 512, "minimap");
	//make a image canvas
	img.img = mlx_new_image(vars.mlx, 1024, 512);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
		&img.line_length, &img.endian); //calculate the memory offset using the line length set by
	//drawing
		//draw a point
	t_point p = {300, 300};
	// p.x = 300;
	// p.y = 300;
	draw_point(&img, 8, p, 0x00FFFF00);
		//draw a line
	t_point p1 = {p.x+3, p.y+3};
	t_point p2 = {p.x+3, p.y-11};
	t_line l = {&p1, &p2};
	draw_line(&img, 2, &l, 0x0000FF00);
	//draw_rectangle(&img);//draw a rectangle
	p = (t_point){309, 300};
	draw_squares(&img, 15, p, 0x00FFFFFF);

	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0); //put the image canvas to the window frame

	//It is an infinite loop that waits for an event
	mlx_key_hook(vars.win, buttons, &vars); //KeyPress, KeyPressMask
	mlx_loop(vars.mlx);
	return (0);
}
