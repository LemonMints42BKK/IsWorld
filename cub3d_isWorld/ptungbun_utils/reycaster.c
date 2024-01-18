/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:05:52 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/19 00:09:49 by pnopjira         ###   ########.fr       */
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
    img->img = mlx_new_image((*vars).mlx, map->mapx * map->mapsize, map->mapy * map->mapsize);
    img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->llen, &img->endian);    
}

t_imgdata	get_tex_image(t_vp *vp, char *path, int *w, int *h)
{
	t_imgdata	teximg;

	teximg.img = mlx_xpm_file_to_image(vp->mlx , path, w, h);
	if (teximg.img == NULL)
	{
		printf("image path: %s not found\n", path);
		return (teximg);
	}
	teximg.addr = mlx_get_data_addr(teximg.img, &teximg.bpp, \
	&teximg.llen, &teximg.endian);
	return (teximg);
}

int    display_minimap(t_main *main)
{
	t_vp *vars;
	
	vars = (*main).viewport;
	background(vars);
	cub3d_render(main, main->viewport);
    minimap(vars, 0xCCBFC9CA);
    return (0);
}

int    display(t_main *main)
{
	// t_vp *vars;
	
	// vars = (*main).viewport;
	// background(vars);
	cub3d_render(main, main->viewport);
    return (0);
}