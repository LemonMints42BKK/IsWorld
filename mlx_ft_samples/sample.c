/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:06:45 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/17 15:13:48 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sample.h"

# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_A_LEFT 0
# define KEY_S_DOWN 1
# define KEY_D_RIGHT 2
# define KEY_W_UP 13

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8)); //calculate the memory offset using the line length set by mlx_get_data_addr
	*(unsigned int*)dst = color; //write the color to the memory address
}

unsigned int	trgb(unsigned int t, unsigned int r, unsigned int g, unsigned int b) //the ARGB values
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	set_point(t_point *p,int x, int y, int s)
{
	(*p).x = x;
	(*p).y = y;
	(*p).s = s;
}

void	set_line(t_line *l, t_point *start, t_point *end, int t)
{
	(*l).s = start;
	(*l).e = end;
	(*l).t = t;
}

void	draw_point(t_data *img, t_point p, unsigned int color)
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

void draw_line(t_data *img, t_line *l, unsigned int color)
{
	t_point d;
	t_point P;
	t_point Pinc;

	d.x = l->e->x - l->s->x;
	d.y = l->e->y - l->s->y;
	int steps = abs(d.x) > abs(d.y) ? abs(d.x) : abs(d.y);
	Pinc.x = d.x / (float)steps;
	Pinc.y = d.y / (float)steps;
	P.x = l->s->x;
	P.y = l->s->y;
	P.s = l->t;
	int i = 0;
	while (i <= steps)
	{
		draw_point(img, P, color);
		P.x += Pinc.x;
		P.y += Pinc.y;
		i++;
	}
}

void draw_squares (t_data *img, int W, t_point P, unsigned int color)
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

int	close_win(t_vars vars)
{
	mlx_destroy_image(vars.mlx, vars.img->img);
	mlx_destroy_window(vars.mlx, vars.win);
	exit(0);
	return (0);
}

// int	resize_win(t_vars *vars)
// {
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	vars->win = mlx_new_window(vars->mlx, 640, 360, "map");
// 	vars->img->img = mlx_new_image(vars->mlx, 640, 360);
// 	return (0);
// }

int	buttons(int key,t_vars *vars)
{
	if (key == KEY_ESC) // Prass ESC to exit
	{
		printf ("Click 'ESC' to exit\n");
		close_win(*vars);
	}
	if (key == KEY_A_LEFT)
	{
		printf("Left\n");
	}
	if (key == KEY_S_DOWN)
	{
		printf("Move down\n");
	}
	if (key == KEY_D_RIGHT)
	{
		printf("Right\n");
	}
	if (key == KEY_W_UP)
	{
		printf("Move up\n");
	}
	if (key == KEY_LEFT)
	{
		printf("Rotate left\n");
	}
	if (key == KEY_RIGHT)
	{
		printf("Rotate right\n");
	}
	return (0);
}

int	mouse_hook(int key, t_vars *vars)
{
	(void)vars;
	if (key == 1)
	{
		printf("Left click\n");
	}
	if (key == 2)
	{
		printf("Right click\n");
	}
	if (key == 3)
	{
		printf("Middle click\n");
	}
	if (key == 5)
	{
		printf("Scroll up\n");
	}
	if (key == 4)
	{
		printf("Scroll down\n");
	}
	return (0);
}

int	mouse_move(int x, int y, t_vars *vars)
{
	// char xbuffer[20];
	// char ybuffer[20];
	// itoa(x, xbuffer, 10);
	// itoa(y, ybuffer, 10);
	printf("x: %d, y: %d\n", x, y);
	mlx_string_put(vars->mlx, vars->win, 50, 30, 0x00FFFFFF, "x: ");
//	mlx_string_put(vars->mlx, vars->win, 100, 30, 0x00FFFFFF, xbuffer);
	mlx_string_put(vars->mlx, vars->win, 150, 30, 0x00FFFFFF, "y: ");
//	mlx_string_put(vars->mlx, vars->win, 200, 30, 0x00FFFFFF, ybuffer);
	return (0);
}

int	scene_init(t_frame *scene)
{
	scene->width = 1280;
	scene->height = 720;
	scene->bg_color = 0x0041424C;
	scene->plan.mapX = 20;
	scene->plan.mapY = 22;
	scene->plan.mapS = 32;
	set_point(&(scene->p), 25, 25, 8);
	set_point(&(scene->mini), 0, 0, 32);
	return (0);
}


void	backgound(t_vars *vars, unsigned int color)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < vars->scene->height)
	{
		i = 0;
		while (i < vars->scene->width)
			my_mlx_pixel_put(vars->img, i++, j, color);
		j++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

void	draw_player (t_data *img, t_point p, unsigned int color)
{
	draw_point(img, p, color);
		//draw a line
	t_point p1;
	t_point p2;
	t_line l;
	set_point(&p1, p.x+3, p.y+3, 0);
	set_point(&p2, p.x+3, p.y-11, 0);
	set_line(&l, &p1, &p2, 2);
	draw_line(img, &l, 0x33FFFF00);
}

int	display_minimap(t_vars *vars)
{
	draw_player(vars->img, vars->scene->p, 0x00FF0000);
//	draw_minimap(vars->img, vars->scene->mini, vars->scene->plan);
	return (0);
}

int	render_next_frame(t_vars *vars)
{
	display_minimap(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return (0);
}

int main(void)
{
	t_vars	vars;
	t_data	img;
	t_frame scene;

	scene_init(&scene);
	//make a window frame
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, scene.width, scene.height, "map");
	//make a image canvas
	img.img = mlx_new_image(vars.mlx, scene.width, scene.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
		&img.line_length, &img.endian); //calculate the memory offset using the line length set by
	vars.img = &img;
	vars.scene = &scene;
	backgound(&vars, scene.bg_color);
	// int	w = 64;
	// int h = 64;
	// if (!mlx_xpm_file_to_image(vars.mlx, "0_gress.xpm", &w, &h))
	// 	return (0);
	//It is an infinite loop that waits for an event
	mlx_hook(vars.win, 17, 0, close_win, &vars);
	mlx_hook(vars.win, 2, 0, buttons, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_hook(vars.win, 6, 0, mouse_move, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
