/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:26:11 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/12 21:17:00 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
//Fountion to convert RGB values to a hexadecimal integer
int     color3f(int r, int g, int b)
{
    return (r << 16 | g << 8 | b);    
}
//a function that will mimic the behaviour of mlx_pixel_put but will simply be many times faster
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    draw_player(t_map mini)
{
    int x = mini.player.px;
    int y = mini.player.py;
    while ( x < (mini.player.px + 8))
    {
        y = mini.player.py;
        my_mlx_pixel_put(&mini.img, x++, y, color3f(255, 200, 0));
        while (y < (mini.player.py + 8))
            my_mlx_pixel_put(&mini.img, x, y++, color3f(255, 200, 0));
    }
}