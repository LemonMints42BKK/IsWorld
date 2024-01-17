/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00map_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:37:51 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/17 09:56:08 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../libft/libft.h"

int	rd_mapdata(char *maps_path, t_map *map, t_player *p)
{
	int		fd1;
	int		fd2;
	int		err;
	
	err = 1;
	fd1 = open(maps_path, O_RDONLY);
	fd2 = open(maps_path, O_RDONLY);
	ck_invalid_data(&err, fd1, map);
	if (err == 0)
		ck_invalid_map(&err, fd2, map, p);
	if (err == 0)
		err = char_to_int_map(map->map_original, map);
	if (err == 0)
		print_map_original(map->map_original, map, p);
	return (err);
}

void	iden_list(t_list **iden)
{
	ft_lstadd_back(iden, ft_lstnew("NO", ""));
	ft_lstadd_back(iden, ft_lstnew("SO", ""));
	ft_lstadd_back(iden, ft_lstnew("WE", ""));
	ft_lstadd_back(iden, ft_lstnew("EA", ""));
	ft_lstadd_back(iden, ft_lstnew("F", ""));
	ft_lstadd_back(iden, ft_lstnew("C", ""));
}

void	init_plan(t_map *plan)
{
	plan->iden = NULL;
	plan->map_begin = false;
	plan->line_map_begin = 0;
	plan->map_original = NULL;
	plan->mapx = 0;
	plan->mapy = 0;
	plan->mapsize = 0;
	plan->map = NULL;
}

void	init_player(t_player *player)
{
	
	if (!player->pos)
		return;
	player->map_x = -1;
	player->map_y = -1;
	player->dir->x = 0;
	player->dir->y = 1;
	player->cam_plane->x = 0.66;
	player->cam_plane->y = 0;
	player->one_player = false;
	player->D = 'N';
	player->psize = 1;
}

void	init_scene(t_frame *scene)
{
	t_list	*tmp;

	tmp = NULL;
	scene->map =(t_map *) malloc(sizeof(t_map) * 1);
	scene->p =(t_player*) malloc(sizeof(t_player) *1);
	scene->p->pos = (t_coor*)malloc(sizeof(t_coor) * 1);
	scene->p->dir = (t_coor*)malloc(sizeof(t_coor) * 1);
	scene->p->cam_plane = (t_coor*)malloc(sizeof(t_coor) * 1);
	if (scene->map == NULL || scene->p == NULL)
		return ;
	init_plan(scene->map);
	init_player(scene->p);
	iden_list(&tmp);
	scene->map->iden = tmp;
}
