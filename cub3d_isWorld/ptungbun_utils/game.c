/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:26:11 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/17 13:04:49 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/game_setup.h"

void	background(t_vp *vars)
{
    t_coor upper_left;
    t_coor lower_right;
    
    set_point(&upper_left, 0, 0);
    set_point(&lower_right, (*vars).scene->w, (*vars).scene->h /2);
    print_bg((*vars).bgimg, upper_left, lower_right, vars->scene->ceiling_color);
	set_point(&upper_left, 0, (*vars).scene->h /2);
    set_point(&lower_right, (*vars).scene->w, (*vars).scene->h);
    print_bg((*vars).bgimg, upper_left, lower_right, vars->scene->floor_color);
    
	mlx_put_image_to_window((*vars).mlx, (*vars).win, (*vars).bgimg->img, 0, 0);
}
