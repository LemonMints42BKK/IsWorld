/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:27:40 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/18 21:01:08 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../game_setup.h"

void    minimap(t_var *vars, unsigned int color)
{   
    int w;
    int h;
    int x;
    int y;
    
    int xo;
    int yo;
    int mapx;
    int mapy;
    int maps;
    t_point upper_left;
    t_point lower_right;
    t_point begin;
    t_point end;
    t_point p;

    w = 320;
    h = 384;
    set_point(&upper_left, 0, 0, 0);
    set_point(&lower_right, w, h, 0);
    print_bg((*vars).mini_img, upper_left, lower_right, color);
    x = 0;
    y = 0;
    mapx = 10;
    mapy = 12; 
    maps = 32; 

    while (y < mapy)    
    {
        x = 0;
        while (x < mapx)
        {
            xo = x * maps;
            yo = y * maps;
            set_point(&begin, xo +1 , yo + 1, 0);
            set_point(&end, xo + maps -1 , yo + maps -1, 0);
            if ((*vars).scene->map->map[y * mapx + x] == 1)
                print_bg((*vars).mini_img, begin, end, 0x66FFFFFF);
            else if ((*vars).scene->map->map[y * mapx + x] == 0)
                print_bg((*vars).mini_img, begin, end, 0x66000000);
            else if ((*vars).scene->map->map[y * mapx + x] == -1)
                print_bg((*vars).mini_img, begin, end, 0x66AEB6BF );
            if (x == (*vars).scene->p.mx && y == (*vars).scene->p.my)
            {   
                set_point(&p, (xo +( maps / 2) - 5 ), (yo +( maps / 2) - 5), 10); 
                print_square_point((*vars).mini_img, p, 0x66F1C40F);
            }
            x++;
        }
        y++;
    }
    mlx_put_image_to_window((*vars).mlx, (*vars).win, (*vars).mini_img->img, 10, 10);  
}