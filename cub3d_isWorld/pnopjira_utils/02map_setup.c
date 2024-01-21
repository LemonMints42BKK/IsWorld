/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02map_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:31:56 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/21 10:27:12 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void before_map_line(int fd2, int map_begin, char **line)
{
	int i;
	
	i = 1;
	while (i++ < map_begin)
	{
		*line = get_next_line(fd2);
		free(*line);
	}
	*line = get_next_line(fd2);
}

void	ck_invalid_map(int *err, int fd2, t_map *map, t_player *p)
{
	char	*line;
	char 	**mapdata;
	int		j;

	j = 0;
	mapdata = (char **)malloc(sizeof(char *) * (map->mapy + 1));
	before_map_line(fd2, map->line_map_begin, &line);
	while (line && err != 0)
	{
		del_nl(&line);
		mapdata[j] = line;
		*err = setup_pos_mapx(mapdata, j, map, p);
		j++;
		line = get_next_line(fd2);
	}
	mapdata[j] = NULL;
	map->map_original = mapdata;
	if(line)
		free(line);
	close(fd2);
}

void	print_map_original(char **map_original)
{
	char	**show_map;

	show_map = map_original;
	while (*show_map)
		printf("%s\n", *(show_map++));
}

int	mapsize(t_map *m, t_player *p)
{
	if ((m->mapx > 12 || m->mapy > 12) && \
	(m->mapx >= 3 && m->mapy >= 3))
	{
		if (m->mapx <= 38 && m->mapy <= 38)
			m->mapsize = 18;
		else
			return (EXIT_FAILURE);
	}
	else
	{
		if (m->mapx < 3 || m->mapy < 3)
			return (EXIT_FAILURE);
		else
			m->mapsize = 36;
	}
	if (m->mapsize == 18)
		p->psize = 6;
	else if (m->mapsize == 36)
		p->psize = 12;
	return (EXIT_SUCCESS);
}

void	key_to_content(t_list *iden, char *key, char *content)
{
	t_list	*tmp;

	tmp = iden;
	while (tmp)
	{
		if (ft_strncmp(tmp->key, key, ft_strlen(key)) == 0)
		{
			if (tmp->content)
				free(tmp->content);
			tmp->content = ft_strdup(content);
			free(content);
			return ;
		}
		tmp = tmp->next;
	}
}