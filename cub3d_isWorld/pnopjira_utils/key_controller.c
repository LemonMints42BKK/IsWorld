/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: (p->ms / 3)0(p->ms / 3)(p->ms / 3)/11/1(p->ms / 3) 17:58:51 by pnopjira          #+#    #+#             */
/*   Updated: 202(p->ms / 3)/11/19 20:16:00 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../game_setup.h"

int	bottons(int keycode, t_var *vars)
{
   t_pos    *p;
   t_frame  *s;

   p = (*vars).scene->p;
   s = (*vars).scene;
   if (keycode == KEY_ESC)
   {
      printf(RED"\'ESC\' to Exit\n"RESET);
      free_on_exit(vars);
	   exit(0);
   }
   else if (keycode == KEY_A_LEFT)
      {
         if ((p->pos->x) - (p->ms / 3) > 0)
         {
            p->pos->x -= (p->ms / 3); 
            if (p->pos->x < (p->mapp->x * s->map->maps) && p->pos->x < ((p->mapp->x - 1) * s->map->maps) && (p->mapp->x > 1))
               p->mapp->x -= 1;
         }
         printf("pmx: %d, pmy: %d, pms: %d\n", p->mapp->x, p->mapp->y, p->mapp->s);
      }
   else if (keycode == KEY_D_RIGHT) //
      {  
         if ((p->pos->x + p->ms) + (p->ms / 3) < (s->map->mapx * s->map->maps))
         {
            p->pos->x += (p->ms / 3); 
            if ((p->pos->x + p->ms) > (p->mapp->x * s->map->maps) && (p->mapp->x <= s->map->mapx))
               p->mapp->x += 1;
         }
         printf("pmx: %d, pmy: %d, pms: %d\n", p->mapp->x, p->mapp->y, p->mapp->s);
      }
   else if (keycode == KEY_W_UP)//
      {  
         if ((p->pos->y) - (p->ms / 3) > 0)
         {
            p->pos->y -= (p->ms / 3); 
            if (p->pos->y < (p->mapp->y * s->map->maps) && p->pos->y < ((p->mapp->y - 1) * s->map->maps) && (p->mapp->y > 1))
               p->mapp->y -= 1;
         }
         printf("pmx: %d, pmy: %d, pms: %d\n", p->mapp->x, p->mapp->y, p->mapp->s);
      }
   else if (keycode == KEY_S_DOWN)//
      {  
         if ((p->pos->y + p->ms) + (p->ms / 3) < (s->map->mapy * s->map->maps))
         {
            p->pos->y += (p->ms / 3); 
            if ((p->pos->y + p->ms) > (p->mapp->y * s->map->maps) && (p->mapp->y <= s->map->mapy))
               p->mapp->y += 1;
         }
         printf("pmx: %d, pmy: %d, pms: %d\n", p->mapp->x, p->mapp->y, p->mapp->s);
      }
   else if (keycode == KEY_LEFT)
      {}
   else if (keycode == KEY_RIGHT)
      {}
	return (0);
}
