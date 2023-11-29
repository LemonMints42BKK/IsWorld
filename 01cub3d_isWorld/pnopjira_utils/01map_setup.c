/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01map_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:01:21 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/29 12:56:43 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	del_nl(char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = *line;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
		{
			tmp[i] = '\0';
			break ;
		}
		i++;
	}
}

int	setup_pos_mapx(char **mapdata, int j, t_map **map, t_pos **p)
{
	int		x;
	
	x = 0;
	while (mapdata[j][x])
	{
		if (mapdata[j][x] == 'N' || mapdata[j][x] == 'S' || mapdata[j][x] == 'W' || mapdata[j][x] == 'E')
		{
			if ((*p)->p_pos)
				set_point((*p)->p_pos, x, j, 0);
			(*p)->dir = mapdata[j][x];
			mapdata[j][x] = '0';
		}
		x++;
	}
	if ((int)ft_strlen(mapdata[j]) > (*map)->mapx)
		(*map)->mapx = ft_strlen(mapdata[j]);
	return (EXIT_SUCCESS);	
}

void	ck_invalid_map(int *err, int fd2, t_map **map, t_pos **p)
{
	char	*line;
	char 	**mapdata;
	int		i;
	int		j;

	i = 0;
	j = 0;
	mapdata = malloc(sizeof(char *) * ((*map)->mapy + 1));
	if (!mapdata)
		mapdata = NULL;
	line = get_next_line(fd2);
	while (line)
	{
		if (i++ < ((*map)->line_map_begin - 1))
			free(line);
		else
		{
			del_nl(&line);
			mapdata[j] = line;
			*err = setup_pos_mapx(mapdata, j, map, p);
			printf("%s\n", mapdata[j]);
			j++;
		}
		line = NULL;
		line = get_next_line(fd2);
	}
	mapdata[j] = NULL;
	(*map)->mapy = j;
	printf("pmx: %d, pmy: %d dir:%c\n", (*p)->p_pos->x, (*p)->p_pos->y, (*p)->dir);
	printf("mapx: %d, mapy: %d line map:%d\n", (*map)->mapx, (*map)->mapy, (*map)->line_map_begin);
	(*map)->map_original = mapdata;
	printf("map original: %p\n", (*map)->map_original);
	if(line)
		free(line);
	close(fd2);
	*err = 0;
}