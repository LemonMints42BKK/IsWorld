/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:38:38 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/16 15:13:39 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	set_player(t_player *p, t_map *m)
{
	p->pos = malloc(sizeof(t_coor));
	if (!p->pos)
		return (EXIT_FAILURE);
	p->pos->x = ((p->map_x + 1) * m->minisize) - (m->minisize / 2);
	p->pos->y = ((p->map_y + 1) * m->minisize) - (m->minisize / 2);
	return (EXIT_SUCCESS);
}

void translate_rgb(char *str, t_color *color)
{
	char	**rgb;
	int		i;

	i = 0;
	
	(void)color;
	rgb = ft_split(str, ',');
	if (!rgb)
		return ;
	while (rgb[i])
	{
		if (i == 0)
			color->r = ft_atoi(rgb[i]);
		else if (i == 1)
			color->g = ft_atoi(rgb[i]);
		else if (i == 2)
			color->b = ft_atoi(rgb[i]);
		free(rgb[i]);
		i++;
	}
}

unsigned int hexcode(t_frame *secen, char *key)
{
	t_list *ptr;
	t_color	color;
	char	*str;
	
	ptr = secen->map->iden->next;
	while (ptr)
	{
		if (ft_strncmp(ptr->key, key, 1) == 0)
			break ;
		ptr = ptr->next;
	}
	str = ptr->content;
	translate_rgb(str, &color);
	return (color3f(color.r, color.g, color.b));
}

int	init_frame(t_frame *scene)
{
	scene->w = WINDOW_WIDTH;
	scene->h = WINDOW_HEIGHT;
	scene->ceiling_color = hexcode(scene, "C");
	scene->floor_color = hexcode(scene, "F");
	if (mapsize(scene->map, scene->p))
		return (4);
	set_player(scene->p, scene->map);  //set player position on map;
	return (EXIT_SUCCESS);
}
