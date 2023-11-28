/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01map_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:01:21 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/27 22:46:05 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	rd_mapdata_only(char *maps_path, t_map **map)
{
	int		fd;
	char	*line;
	char 	**mapdata;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	fd = open(maps_path, O_RDONLY);
	line = get_next_line(fd);
	mapdata = malloc(sizeof(char *) * ((*map)->mapy + 1));
	while (line)
	{
		if (i < (*map)->line_map_begin)
			i++;
		else
		{
			mapdata[j] = line;
			printf("%s\n", mapdata[j]);
			j++;
		}
		line = NULL;
		line = get_next_line(fd);
	}
	mapdata[j] = NULL;
	(*map)->map1 = mapdata;
	if(line)
		free(line);
	close(fd);
	return (EXIT_SUCCESS);
}