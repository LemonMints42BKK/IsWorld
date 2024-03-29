/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap->c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:27:40 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/19 16:26:24 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/game_setup.h"

void	draw_minimap(t_vp *vars, t_map *plan, t_coor *begin, t_coor *end)
{
	int x;
    int y;    
    int xo;
    int yo;

	x = 0;
    y = 0;
	(void)vars; //
	while (y < plan->mapy) 
    {
        x = 0;
        while (x < plan->mapx)
        {
            xo = x * plan->mapsize;
            yo = y * plan->mapsize;
            set_point(begin, xo +1 , yo + 1);
            set_point(end, xo + plan->mapsize -1 , yo + plan->mapsize -1);
            if (plan->map[y][x] == 1)
                print_bg((*vars).mini_img, *begin, *end, 0x66FFFFFF);
            else if (plan->map[y][x] == 0)
                print_bg((*vars).mini_img, *begin, *end, 0x66000000);
            else if (plan->map[y][x] == -1)
                print_bg((*vars).mini_img, *begin, *end, 0x66AEB6BF );
            x++;
        }
        y++;
    }
}

void	draw_player(t_vp *vars, t_map *plan, t_player **p)
{
	t_coor py;
	int x;
    int y;  

	x = 0;
    y = 0;
	while (y < plan->mapy) 
    {
        x = 0;
        while (x < plan->mapx)
        {
			if ((x+1) == (*p)->map_x && (y+1) == (*p)->map_y)
        	{   
            	set_point(&py, (*p)->pos->x, (*p)->pos->y); 
            	print_square_point((*vars).mini_img, py, 0x66F1C40F);
				print_player_charater((*vars).mini_img, py, 0x66F1C40F);
        	}
			x++;
		}
		y++;
	}
}

void    minimap(t_vp *vars, unsigned int color)
{   
    t_map   *map;
    t_coor begin;
    t_coor end;
    t_player  *pos;

    map = (*vars).scene->map;
    pos = (*vars).scene->p;

    set_point(&begin, 0, 0);
    set_point(&end, map->mapx * map->mapsize, map->mapy * map->mapsize);
    print_bg((*vars).mini_img, begin, end, color);
	draw_minimap(vars, map, &begin, &end);
	draw_player(vars, map, &pos);
    mlx_put_image_to_window((*vars).mlx, (*vars).win, (*vars).mini_img->img, 10, 10);  
}