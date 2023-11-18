/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:58:51 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/18 13:43:00 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../game_setup.h"

int	bottons(int keycode, t_var *vars)
{
   if (keycode == KEY_ESC)
   {
      printf(RED"\'ESC\' to Exit\n"RESET);
      free_on_exit(vars);
	   exit(0);
   }
   // else if (keycode == KEY_A_LEFT)
   //    { printf("%d :\n", keycode); (*scene).player.px -= 5; printf("%d :\n", (*scene).player.px); }
   // else if (keycode == KEY_D_RIGHT)
   //    { printf("%d :\n", keycode); (*scene).player.px += 5; printf("%d :\n", (*scene).player.px); }
   // else if (keycode == KEY_W_UP)
   //    { printf("%d :\n", keycode); (*scene).player.py -= 5; printf("%d :\n", (*scene).player.px); }
   // else if (keycode == KEY_S_DOWN)
   //    { printf("%d :\n", keycode); (*scene).player.py += 5; printf("%d :\n", (*scene).player.px); }
	return (0);
}
