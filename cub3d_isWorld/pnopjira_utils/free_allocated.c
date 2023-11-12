/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_allocated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:42:34 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/12 20:33:28 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	free_on_exit(int keycode,t_var *vars)
{
    if (keycode == KEY_ESC)
        printf(RED"\'ESC\' to Exit\n"RESET);
	else 
        printf(RED"Click \'X\' to Exit\n"RESET);
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
}