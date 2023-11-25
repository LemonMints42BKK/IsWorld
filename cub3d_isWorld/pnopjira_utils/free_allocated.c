/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_allocated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:42:34 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/24 22:03:17 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../game_setup.h"

void    del(void *content)
{
    t_list *lst;

    lst = (t_list *)content;
    free(lst->key);
    free(lst->content);
    lst->key = NULL;
    lst->content = NULL;
}

int	free_on_exit(t_var *vars)
{
    t_list *iden;

    iden = (*vars).scene->map->iden;
    ft_lstclear(&iden, del);
    mlx_destroy_image((*vars).mlx, (*vars).bgimg->img);
    mlx_destroy_image((*vars).mlx, (*vars).mini_img->img);
    mlx_destroy_window((*vars).mlx, (*vars).win);
    exit(0);
}
