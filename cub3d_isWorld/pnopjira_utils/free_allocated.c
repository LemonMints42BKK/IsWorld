/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_allocated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:42:34 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/18 16:19:18 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../game_setup.h"

int	free_on_exit(t_var *vars)
{
    mlx_destroy_image((*vars).mlx, (*vars).bgimg->img);
    mlx_destroy_image((*vars).mlx, (*vars).mini_img->img);
    mlx_destroy_window((*vars).mlx, (*vars).win);
    exit(0);
}