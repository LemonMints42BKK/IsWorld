/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04map_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:26:31 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/21 11:28:13 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	fillable(t_map *map,int **tab, int y, int x)
{
	if (y < 0 || x < 0 || y >= map->mapy || x >= map->mapx)
		return (0);
	if (tab[y][x] != 1 && tab[y][x] != 9)
		return (1);
	else
		return (0);
}

void	touch_map_edge(t_map *map, int y, int x)
{
	int **tab;
	
	tab = map->map;
	if (tab[y][x] == -1)
	{
		map->close_map = false;
		return ;
	}
	if (y == 0 || x == 0 || y == map->mapy - 1 || x == map->mapx - 1)
		map->close_map = false;
}

void	flood_fill(t_map *map, int **tab, int y, int x)
{
	if (!map->close_map)
		return ;
	tab[y][x] = 9;
	if (fillable(map, tab, y - 1, x))
	{
		touch_map_edge(map, y - 1, x);
		flood_fill (map, tab, y - 1, x);
	}
	if (fillable(map, tab, y + 1, x))
	{
		touch_map_edge(map, y + 1, x);
		flood_fill (map, tab, y + 1, x);
	}
	if (fillable(map, tab, y, x - 1))
	{
		touch_map_edge(map, y, x - 1);
		flood_fill (map, tab, y, x - 1);
	}
	if (fillable(map, tab, y, x + 1))
	{
		touch_map_edge(map, y, x + 1);
		flood_fill (map, tab, y, x + 1);
	}
}

void	mapdup(int **dst, int **src, int mapy, int mapx)
{
	int i;
	int j;

	j = 0;
	while (j < mapy)
	{
		i = 0;
		while (i < mapx)
		{
			dst[j][i] = src[j][i];
			i++;
		}
		j++;
	}
	
}

void	ck_closed_walls(int *err, t_map *map, t_player *p)
{
	int x;
	int	y;
	int **tap;
	
	x = p->map_x;
	y = p->map_y;
	if ( x == -1 || y == -1)
	{	
		*err = 5;
		return ;
	}
	if (!allocated_map_int(&tap, map->mapy, map->mapx))
		mapdup(tap, map->map, map->mapy, map->mapx);
	flood_fill(map, tap, y, x);
	free_int_map(tap, map->mapy);
	if (!map->close_map)
		*err = 5;
}