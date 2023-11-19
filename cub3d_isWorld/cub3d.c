/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:26:37 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/19 16:42:39 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game_setup.h"
 
int map[518] = 
{  
    -1,-1,-1,-1,-1,-1,-1,-1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,-1,-1,-1,
    -1,-1,-1,-1,-1,-1,-1,-1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    -1,-1,-1,-1,-1,-1,-1,-1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    -1,-1,-1,-1,-1,-1,-1,-1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1

};

int    mapsize(t_map *m)
{
    if (((*m).mapx > 12 || (*m).mapy > 12) && ((*m).mapx >= 3 && (*m).mapy >= 3))
    {   if ((*m).mapx <= 37 && (*m).mapy <= 37)
            (*m).maps = 16;
        else
            return (EXIT_FAILURE);
    }
    else
    {
        if ((*m).mapx < 3 || (*m).mapy < 3)
            return (EXIT_FAILURE);
        else
           (*m).maps = 32;
    }  
    return (EXIT_SUCCESS);
}

int    init_frame(t_frame *scene)
{
    t_frame *s;
    t_map   *m;
    t_pos   *p;
    
    s = scene;
    m = (*s).map;
    p = (*s).p;
    s->w = 1280;
    s->h = 720;
    m->mapx = 7;
    m->mapy = 4;
    if (mapsize(m))
        return (4);
    m->map = map;
    p->mx = 1;
    p->my = 1;
    if (m->maps == 16)
        p->ms = 5;
    else if (m->maps == 32)
        p->ms = 10;
    return (EXIT_SUCCESS);
}

int   raycaster(t_var *vars)
{
    t_map   map;
    t_pos   p;

    (*vars).scene->map = &map;
    (*vars).scene->p = &p;
    if (explicit_error(init_frame((*vars).scene)))
        return (EXIT_FAILURE);
    //deploy mlx instance and allocated window frame
	(*vars).mlx = mlx_init();
    (*vars).win = mlx_new_window((*vars).mlx, (*vars).scene->w, (*vars).scene->h, "isWorld-cub3D");
    //init cavas in to frame
    scene_init(vars);
    minimap_init(vars);
    //Keep file texture to img to struct of t_frame type
    /*windon controller*/
    mlx_hook((*vars).win, 17, 0, free_on_exit, vars); //DestroyNotify, NoEventMask
    mlx_key_hook((*vars).win, bottons, vars); //KeyPress, KeyPressMask
    /*loop to call display into the frame*/
    mlx_loop_hook((*vars).mlx, display, vars);// loop scene into the frame ->displaing draws set
    //It is an infinite loop that waits for an event
    mlx_loop((*vars).mlx);
    return (0);
}

int main(int argc, char **argv)
{
    t_var       vars;
    t_data      bgimg;
    t_data      mini;
    t_frame     scene;

    vars.bgimg = &bgimg;
    vars.scene = &scene;
    vars.mini_img = &mini;
    if (argc == 2)
    {
        if (check_invalid_mapfile(argv[1]))
            return (EXIT_FAILURE);
        else
            if (raycaster(&vars))
                return (EXIT_FAILURE);
    } else
        return(ft_putstr_fd(GREEN"Used: ./cub3d maps/<filename>.cub\n"RESET, 2)\
        , 1);
    return (EXIT_SUCCESS);
}
