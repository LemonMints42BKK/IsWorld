/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:05:52 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/16 18:22:31 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/game_setup.h"

void    bg_init(t_vp *vars)
{
    t_imgdata  *img;
    t_frame *scene;
         
    img = (*vars).bgimg;
    scene = (*vars).scene; 
    img->img = mlx_new_image((*vars).mlx, scene->w, scene->h);
    img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->llen, &img->endian);
}

void    minimap_init(t_vp *vars)
{
    t_imgdata  *img;
    t_map   *map;

    map = (*vars).scene->map; 
    img = (*vars).mini_img;
    img->img = mlx_new_image((*vars).mlx, map->mapx * map->minisize, map->mapy * map->minisize);
    img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->llen, &img->endian);    
}

int    display_minimap(t_main *main)
{
	t_vp *vars;
	
	vars = (*main).viewport;
	background(vars, (*vars).scene->floor_color);
    minimap(vars, 0xCCBFC9CA);
    return (0);
}

int    display(t_main *main)
{
	(void)main;
	//cub3d_render(main, main->viewport); // SEGV on unknown address 0x00000000005c (pc 0x00010c6b7fad bp 0x7ffee3551cc0 sp 0x7ffee3551ae0 T0)
    return (0);
}