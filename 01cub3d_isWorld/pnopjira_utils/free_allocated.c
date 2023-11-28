/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_allocated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:42:34 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/27 20:15:37 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../game_setup.h"

void	del(void *lst)
{
	t_list	*tmp;

	tmp = (t_list *)lst;
	free(tmp->key);
	free(tmp->content);
	tmp->key = NULL;
	tmp->content = NULL;
}

int	free_on_exit(t_var *vars)
{
	mlx_destroy_image((*vars).mlx, (*vars).bgimg->img);
	mlx_destroy_image((*vars).mlx, (*vars).mini_img->img);
	mlx_destroy_window((*vars).mlx, (*vars).win);
	ft_lstclear(&(*vars).scene->map->iden, del);
	free((*vars).scene->map);
	exit(0);
}
