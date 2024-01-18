/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:09:46 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/17 22:38:29 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void find_player_pos(t_map *mapfile, t_player *p)
{
	double pos_x;
	double pos_y;

	pos_x = (p->map_x + 0.5);
	pos_y = (p->map_y + 0.5);
	if (pos_x < 0)
		pos_x = 0;
	else if (pos_x > mapfile->mapx)
		pos_x = (mapfile->mapx) - 0.5;	
	if (pos_y < 0)
		pos_y = 0;
	else if (pos_y > mapfile->mapy)
		pos_y = (mapfile->mapy) - 0.5;
	p->pos->x = pos_x;
	p->pos->y = pos_y;
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

