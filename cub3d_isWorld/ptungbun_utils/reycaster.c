/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:05:52 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/12 15:10:26 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    draw_squares(t_data *img)
{
    int x = 100;
    int y;
    while ( x < 200)
    {
        y = 100;
        my_mlx_pixel_put(img, x++, y, 0x00FF0000);
        while (y < 200)
            my_mlx_pixel_put(img, x, y++, 0x00FF0000);
    }
}

void    mlx_raycaster()
{
    void    *mlx;
	void	*mlx_win;
    t_data  img;

    //call graphic system and prepare img frame
	mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1024, 512, "isWorld-cub3D");
    //allocat img canvas and get canvas address
    img.img = mlx_new_image(mlx, 1024, 512);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
    &img.line_length, &img.endian);
    //Drawing
    draw_squares(&img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    //loop screen
    mlx_loop(mlx);
}
