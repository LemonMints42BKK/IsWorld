/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:58:51 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/13 11:47:28 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// int	handler_key(int key, t_viewport *vp)
// {
// 	if (key == KEY_ESC)
// 	{
// 		vp_free_on_exit(vp);
// 		return (0);
// 	}
// 	if ((*vp).plan->is_completed == 1)
// 		return (0);
// 	if (key == KEY_LEFT || key == KEY_A_LEFT)
// 		(*vp).plan->moves += move_left((*vp).plan);
// 	else if (key == KEY_RIGHT || key == KEY_D_RIGHT)
// 		(*vp).plan->moves += move_right((*vp).plan);
// 	else if (key == KEY_DOWN || key == KEY_S_DOWN)
// 		(*vp).plan->moves += move_down((*vp).plan);
// 	else if (key == KEY_UP || key == KEY_W_UP)
// 		(*vp).plan->moves += move_up((*vp).plan);
// 	level_print_info((*vp).plan, key);
// 	if ((*vp).plan->is_completed == 1)
// 	{
// 		ft_printf("----------------------\n~* level completed! *~\n" \
// 					"----------------------\n");
// 		exit (0);
// 	}
// 	return (0);
// }

int	key_handler(int keycode, t_frame *scene)
{
   if (keycode == KEY_ESC)
   {
     free_on_exit(keycode, (*scene).vars);
	   exit(0);
   }
   else if (keycode == KEY_A_LEFT)
      { printf("%d :\n", keycode); (*scene).player.px -= 5; printf("%d :\n", (*scene).player.px); }
   else if (keycode == KEY_D_RIGHT)
      { printf("%d :\n", keycode); (*scene).player.px += 5; printf("%d :\n", (*scene).player.px); }
   else if (keycode == KEY_W_UP)
      { printf("%d :\n", keycode); (*scene).player.py -= 5; printf("%d :\n", (*scene).player.px); }
   else if (keycode == KEY_S_DOWN)
      { printf("%d :\n", keycode); (*scene).player.py += 5; printf("%d :\n", (*scene).player.px); }
	return (0);
}
