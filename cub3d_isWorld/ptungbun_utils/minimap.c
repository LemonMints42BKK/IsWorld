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

#include "../cub3d.h"
#include "../game_setup.h"

void    minimap(t_var *vars, unsigned int color)
{   
    t_map   *map;
    int x;
    int y;    
    int xo;
    int yo;
    t_point begin;
    t_point end;
    t_point p;

    map = (*vars).scene->map;
    x = 0;
    y = 0;
    set_point(&begin, 0, 0, 0);
    set_point(&end, map->mapx * map->maps, map->mapy * map->maps, 0);
    print_bg((*vars).mini_img, begin, end, color);
    while (y < map->mapy)    
    {
        x = 0;
        while (x < map->mapx)
        {
            xo = x * map->maps;
            yo = y * map->maps;
            set_point(&begin, xo +1 , yo + 1, 0);
            set_point(&end, xo + map->maps -1 , yo + map->maps -1, 0);
            if ((*vars).scene->map->map[y * map->mapx + x] == 1)
                print_bg((*vars).mini_img, begin, end, 0x66FFFFFF);
            else if ((*vars).scene->map->map[y * map->mapx + x] == 0)
                print_bg((*vars).mini_img, begin, end, 0x66000000);
            else if ((*vars).scene->map->map[y * map->mapx + x] == -1)
                print_bg((*vars).mini_img, begin, end, 0x66AEB6BF );
            if (x == (*vars).scene->p->mx && y == (*vars).scene->p->my)
            {   
                set_point(&p, (xo + ( map->maps / 2) - ((*vars).scene->p->ms /2)), (yo +( map->maps / 2) - ((*vars).scene->p->ms /2)), (*vars).scene->p->ms); 
                // set_point(&p, (xo + ( map->maps / 2) - 2), (yo +( map->maps / 2) - 2), 5); 
                print_square_point((*vars).mini_img, p, 0x66F1C40F);
            }
            x++;
        }
        y++;
    }
    mlx_put_image_to_window((*vars).mlx, (*vars).win, (*vars).mini_img->img, 10, 10);  
}