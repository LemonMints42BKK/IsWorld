/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:26:37 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/12 21:19:49 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    raycaster()
{
    t_var  vars;
    t_map   scene;

    scene.vars = &vars;
    //call graphic system and prepare img frame
	vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1024, 512, "isWorld-cub3D");
    //allocat img canvas and get canvas address
    // img.img = mlx_new_image(mlx, 1024, 512);
    // img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
    // &img.line_length, &img.endian);
    init((long)vars.mlx, &scene);
    //Keep file texture to img to viewpoint struct
    /*Drawing*/
        //test drawing
    display(&scene);
        //minimap2D
        //Draw 3D Walls
	mlx_put_image_to_window(vars.mlx, vars.win, scene.img.img, 0, 0);
    
    //Hooking into events
    mlx_hook(vars.win, 17, 0L, free_on_exit, &vars); //DestroyNotify, NoEventMask
    mlx_loop_hook(vars.mlx, display, &scene);
    mlx_key_hook(vars.win, key_handler, &scene); //KeyPress, KeyPressMask
    printf("px=%d\n", scene.player.px);
    printf("py=%d\n", scene.player.py);
	// mlx_loop_hook() Don't sure can used on texture or not

    //It is an infinite loop that waits for an event
    mlx_loop(vars.mlx);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        if (check_invalid_mapfile(argv[1]))
            return (1);
        else
            raycaster();
    } else
        return(ft_putstr_fd(GREEN"Used: ./cub3d maps/<filename>.cub\n"RESET, 2)\
        , 1);
    return (0);
}
