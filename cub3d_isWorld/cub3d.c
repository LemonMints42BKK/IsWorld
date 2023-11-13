/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:26:37 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/13 12:25:03 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    raycaster()
{
    t_var  vars;
    t_frame   scene;

    //call graphic system and init img frame
	vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1024, 512, "isWorld-cub3D");
    // init vars.mlx and vars.win into t_map struct
    scene.vars = &vars;
    //init cavas in to frame
   init(&scene);
    //Keep file texture to img to struct of t_frame type

    /*windon controller*/
    mlx_hook(vars.win, 17, 0L, free_on_exit, &vars); //DestroyNotify, NoEventMask
    mlx_key_hook(vars.win, key_handler, &scene); //KeyPress, KeyPressMask
    /*loop to call display into the frame*/
    mlx_loop_hook(vars.mlx, display, &scene);// loop scene into the frame ->displaing draws set

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
