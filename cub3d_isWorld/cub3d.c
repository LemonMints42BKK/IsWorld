/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:26:37 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/25 06:45:58 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game_setup.h"

int	check_invalid_filedata(char *maps_path, t_var *vars)
{
	if (invalid_filepath(maps_path, "maps/", ".cub"))
        return (EXIT_FAILURE);
    if (explicit_error(rd_mapdata(maps_path, vars)))
        return (EXIT_FAILURE);
	else
	{
		(void)vars;
	}
	return (EXIT_SUCCESS);
}

int   raycaster(t_var *vars)
{
    t_pos   p;
    t_point pos;
    t_point mapp;

    (*vars).scene->p = &p;
    (*vars).scene->p->pos = &pos;
    (*vars).scene->p->mapp = &mapp;
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
    mlx_hook((*vars).win, 2, 0, bottons, vars); //KeyPress, KeyPressMask
    /*loop to call display into the frame*/
    mlx_loop_hook((*vars).mlx, display, vars);// loop scene into the frame ->displaing draws set
    //It is an infinite loop that waits for an event
    mlx_loop((*vars).mlx);
    return (0);
}

void    init_vars(t_var *vars)
{
    (*vars).mlx = NULL;
    (*vars).win = NULL;
    (*vars).bgimg->addr = NULL;
    (*vars).bgimg->img = NULL;
    (*vars).bgimg->bpp = 0;
    (*vars).bgimg->llen = 0;
    (*vars).bgimg->endian = 0;
    (*vars).mini_img->addr = NULL;
    (*vars).mini_img->img = NULL;
    (*vars).mini_img->bpp = 0;
    (*vars).mini_img->llen = 0;
    (*vars).mini_img->endian = 0;
    (*vars).scene->w = 0;
    (*vars).scene->h = 0;
    (*vars).scene->bgc = 0;
    (*vars).scene->map->iden = NULL;
    (*vars).scene->map->map_begin = false;
    (*vars).scene->map->mapx = 0;
    (*vars).scene->map->mapy = 0;
    (*vars).scene->map->maps = 0;
    (*vars).scene->map->map = NULL;
}

int main(int argc, char **argv)
{
    t_var       vars;
    t_data      bgimg;
    t_data      mini;
    t_frame     scene;
    t_map       map;
    t_list      *tmp; //for test

    vars.bgimg = &bgimg;
    vars.mini_img = &mini;
    vars.scene = &scene;
    vars.scene->map = &map;
    init_vars(&vars);
    if (argc == 2)
    {
        iden_list(&vars); //set list of identity type with empty content
        tmp = vars.scene->map->iden; //for test
        if (check_invalid_filedata(argv[1], &vars))
        {
            ft_lstclear(&tmp, del);
            return (EXIT_FAILURE);
        }
        else
        {
            while(tmp) //for test
            {
                printf("key:%s %s\n", tmp->key, tmp->content);
                tmp = tmp->next;
            }
            if (raycaster(&vars))
                return (perror(RED"Error\n"RESET), EXIT_FAILURE);
        }
    } else
        return(ft_putstr_fd(GREEN"Used: ./cub3d maps/<filename>.cub\n"RESET, 2)\
        , 1);
    return (EXIT_SUCCESS);
}
