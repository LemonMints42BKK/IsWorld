/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:05:52 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/13 11:51:14 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    init(t_frame *scene)
{
    void    *mlx;
    t_data  *img;
    t_pos   *player;

    mlx = (*scene).vars->mlx;
    img = &(*scene).img;
    player = &(*scene).player;
    img->img = mlx_new_image((void *)mlx, 1024, 512);
    img->addr = mlx_get_data_addr(img->img, \
    &img->bits_per_pixel, &img->line_length, &img->endian);
    player->px = 300;
    player->py = 300;
}

int    display(t_frame *scene)
{
    t_var   *vars;
    t_data  img;

    vars = (*scene).vars;
    img = (*scene).img;
    draw_player(scene);
    mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
    return (0);
}
