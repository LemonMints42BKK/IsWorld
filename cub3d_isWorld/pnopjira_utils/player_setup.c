/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:09:46 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/17 11:27:15 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void find_player_pos(t_map *mapfile, t_player *p)
{
	double map_width;
	double map_height;
	double pos_x;
	double pos_y;
	
	map_width = mapfile->mapx * mapfile->mapsize;
	map_height = mapfile->mapy * mapfile->mapsize;
	pos_x = (mapfile->mapsize * p->map_x) + (mapfile->mapsize / 2);
	pos_y = (mapfile->mapsize * p->map_y) + (mapfile->mapsize / 2);
	if (pos_x < 0)
		p->map_x = 0;
	else if (pos_x > map_width)
		p->map_x = (mapfile->mapx) - 1;	
	if (pos_y < 0)
		p->map_y = 0;
	else if (pos_y > map_height)
		p->map_y = (mapfile->mapy) - 1;
	if (pos_x < 0 || pos_x > map_width || pos_y < 0 || pos_y > map_height)
		find_player_pos(mapfile, p);
	p->pos->x = pos_x;
	p->pos->y = pos_y;
}

void find_player_on_map(t_map *mapfile, t_player *p)
{
	int map_x;
	int map_y;

	map_x = (int)(p->pos->x / mapfile->mapsize);
	map_y = (int)(p->pos->y / mapfile->mapsize);
	if (map_x < 0)
		p->pos->x = 1 + (p->psize / 2);
	else if (map_x > (mapfile->mapx - 1))
		p->pos->x = (mapfile->mapx * mapfile->mapsize) - (1 + (p->psize / 2));
	if (map_y < 0)
		p->pos->y = 1 + (p->psize / 2);
	else if (map_y > (mapfile->mapy - 1))
		p->pos->y = (mapfile->mapy * mapfile->mapsize) - (1 + (p->psize / 2));
	if (map_x < 0 || map_x > (mapfile->mapx - 1) || map_y < 0 || map_y > (mapfile->mapy - 1))
		find_player_on_map(mapfile, p);
	p->map_x = map_x;
	p->map_y = map_y;
}

void begin_dir_of_player(t_main *main, char D)
{
	t_coor *dir;
	
	dir = main->viewport->scene->p->dir;
	if (D == 'N' || D == 'S')
	{
		dir->x = 0;
		if (D == 'N')
			dir->y = 1;
		else
			dir->y = -1;
	}
	else if (D == 'E' || D == 'W')
	{
		dir->y = 0;
		if (D == 'E')
			dir->x = 1;
		else
			dir->x = -1;
	}
	else
		return ;
}

void	camera_plane_of_player(t_main *main, char D)
{
	t_coor *cam_plane;
	
	cam_plane = main->viewport->scene->p->cam_plane;
	if (D == 'N' || D == 'S')
	{
		cam_plane->x = 0.66;
		cam_plane->y = 0;
		if (D == 'S')
			cam_plane->x *= -1;
	}
	else if (D == 'E' || D == 'W')
	{
		cam_plane->x = 0;
		cam_plane->y = 0.66;
		if (D == 'E')
			cam_plane->y *= -1;
	}
	else
		return ;
}

