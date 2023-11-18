/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:26:37 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/18 20:01:16 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game_setup.h"
 
int map[120] = 
{  
    -1,-1,-1,1,1,1,1,1,1,1,
    -1,-1,-1,1,0,0,0,0,0,1,
    -1,-1,-1,1,0,0,0,0,0,1,
    1,1,1,1,1,1,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,1,1,1,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,1,1
};

void    raycaster(void)
{
    t_var       vars;
    t_data      bgimg;
    t_data      mini;
    t_frame     scene;

    vars.bgimg = &bgimg;
    vars.scene = &scene;
    vars.mini_img = &mini;
    scene.w = 1280;
    scene.h = 720;
    // scene.p.x = 5;
    // scene.p.y = 6;
    scene.map.mapx = 10;
    scene.map.mapy = 12;
    scene.map.maps = 32;
    scene.map.map = map;
    //deploy mlx instance and allocated window frame
	vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, scene.w, scene.h, "isWorld-cub3D");
    //init cavas in to frame
    scene_init(&vars);
    minimap_init(&vars);

    //Keep file texture to img to struct of t_frame type
    /*windon controller*/
    mlx_hook(vars.win, 17, 0, free_on_exit, &vars); //DestroyNotify, NoEventMask
    mlx_key_hook(vars.win, bottons, &vars); //KeyPress, KeyPressMask
    /*loop to call display into the frame*/
    mlx_loop_hook(vars.mlx, display, &vars);// loop scene into the frame ->displaing draws set

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
