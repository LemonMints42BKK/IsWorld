/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00map_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:37:51 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/29 16:39:00 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"

int	rd_mapdata(char *maps_path, t_map **map, t_pos **p)
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
	return (err);
}

void	key_to_content(void **iden, char *key, char *content)
{
	t_list	*tmp;

	tmp = *iden;
	while (tmp)
	{
		if (ft_strncmp(tmp->key, key, ft_strlen(key)) == 0)
		{
			if (tmp->content)
				free(tmp->content);
			tmp->content = ft_strdup(content);
			return ;
		}
		tmp = tmp->next;
	}
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
	(*plan).iden = NULL;
	(*plan).map_begin = false;
	(*plan).line_map_begin = 0;
	(*plan).mapx = 0;
	(*plan).mapy = 0;
	(*plan).maps = 0;
	(*plan).map = NULL;
	(*plan).map_original = NULL;
}

void	init_player(t_pos *player)
{
	t_point	*p_pos = NULL;
	
	p_pos = (t_point *)malloc(sizeof(t_point) * 1);
	if (!p_pos)
		p_pos = NULL;
	p_pos->x = -1;
	p_pos->y = -1;
	(*player).pos = NULL;
	(*player).p_pos = p_pos;
	(*player).one_player = false;
	(*player).dir = 'N';
	(*player).ms = 0;
}

void	init_map(t_frame *scene)
{
	t_map	*plan;
	t_pos	*player;

	plan = malloc(sizeof(t_map) * 1);
	player = malloc(sizeof(t_pos) *1);
	
	//map plan
	init_plan(plan);
	// (*plan).iden = NULL;
	// (*plan).map_begin = false;
	// (*plan).line_map_begin = 0;
	// (*plan).mapx = 0;
	// (*plan).mapy = 0;
	// (*plan).maps = 0;
	// (*plan).map = NULL;
	// (*plan).map1 = NULL;
	//player
	init_player(player);
	// (*player).pos = NULL;
	// (*player).p_pos = NULL;
	// (*player).dir = 'N';
	// (*player).ms = 0;
	
	(*scene).p = player;
	iden_list(&(*plan).iden);
	(*scene).map = plan;
}

int	mapsize(t_map *m)
{
	if (((*m).mapx > 12 || (*m).mapy > 12) && \
	((*m).mapx >= 3 && (*m).mapy >= 3))
	{
		if ((*m).mapx <= 38 && (*m).mapy <= 38)
			(*m).maps = 18;
		else
			return (EXIT_FAILURE);
	}
	else
	{
		if ((*m).mapx < 3 || (*m).mapy < 3)
			return (EXIT_FAILURE);
		else
			(*m).maps = 36;
	}
	return (EXIT_SUCCESS);
}
