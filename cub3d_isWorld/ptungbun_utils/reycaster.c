/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:05:52 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/12 21:17:18 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int    display(t_map *scene)
{
    draw_player(*scene);
    mlx_put_image_to_window((*scene).vars->mlx, (*scene).vars->win, \
    (*scene).img.img, 0, 0);
    return (0);
}

void    init(long mlx, t_map *scene)
{
    (*scene).player.px = 300;
    (*scene).player.py = 300;
    (*scene).img.img = mlx_new_image((void *)mlx, 1024, 512);
    (*scene).img.addr = mlx_get_data_addr((*scene).img.img, \
    &scene->img.bits_per_pixel, &scene->img.line_length, &scene->img.endian);
    
}