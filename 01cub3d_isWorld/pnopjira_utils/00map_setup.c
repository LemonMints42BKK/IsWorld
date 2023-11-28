/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00map_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:37:51 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/27 22:39:20 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"

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

void	init_map(t_frame *scene)
{
	t_map	*plan;

	plan = malloc(sizeof(t_map) * 1);
	(*plan).iden = NULL;
	(*plan).map_begin = false;
	(*plan).line_map_begin = 0;
	(*plan).mapx = 0;
	(*plan).mapy = 0;
	(*plan).maps = 0;
	(*plan).map = NULL;
	(*plan).map1 = NULL;
	iden_list(&(*plan).iden);
	(*scene).map = plan;
}

int	mapsize(t_map *m)
{
	if (((*m).mapx > 12 || (*m).mapy > 12) && \
	((*m).mapx >= 3 && (*m).mapy >= 3))
	{
		if ((*m).mapx <= 37 && (*m).mapy <= 37)
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
