/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:26:37 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/12 13:31:32 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
    mlx_win = mlx_new_window(mlx, 1024, 512, "Hello world!");
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

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        if (check_invalid_mapfile(argv[1]))
            return (1);
        else
        {
            printf(GREEN"-----game Start-----"RESET"\n"); // game raycasting here
            mlx_raycaster();
        }
    } else
        return(ft_putstr_fd(GREEN"Used: ./cub3d maps/<filename>.cub\n"RESET, 2)\
        , 1);
    return (0);
}
