/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01map_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:01:21 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/29 19:41:17 by pnopjira         ###   ########.fr       */
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

int	setup_pos(char *dir,int x, int y, t_pos **p)
{
	if ((*p)->one_player == false)
		(*p)->one_player = true;
	else
		return (EXIT_FAILURE);
	if ((*p)->p_pos)
		set_point((*p)->p_pos, x, y, 0);
	(*p)->dir = *dir;
	return (EXIT_SUCCESS);
}

int	setup_pos_mapx(char **mapdata, int j, t_map **map, t_pos **p)
{
	int		x;
	
	x = 0;
	while (mapdata[j][x])
	{
		if (mapdata[j][x] == 'N' || mapdata[j][x] == 'S' || mapdata[j][x] == 'W' || mapdata[j][x] == 'E')
		{
			if (setup_pos(&mapdata[j][x], x, j, p))
				return (5);
		}
		else if (!(mapdata[j][x] == '0' || mapdata[j][x] == '1' || mapdata[j][x] == ' '))
			return (5);
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
	while (line && *err == 0)
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
	(*map)->map_original = mapdata;
	if ((*p)->p_pos->x == -1 && (*p)->p_pos->y == -1)
		*err = 5;
	printf("px: %d, py: %d dir:%c\n", (*p)->p_pos->x, (*p)->p_pos->y, (*p)->dir);
	printf("mapx: %d, mapy: %d\n", (*map)->mapx, (*map)->mapy);
	if(line)
		free(line);
	close(fd2);
}