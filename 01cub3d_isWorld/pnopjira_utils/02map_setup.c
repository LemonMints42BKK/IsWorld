/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02map_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:31:56 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/30 09:25:07 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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