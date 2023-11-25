/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 23:33:20 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/25 00:31:09 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    key_to_content(void **lst, void *key, void *content)
{
    t_list  *tmp;

    tmp = *lst;
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

void    iden_list(t_var *vars)
{
    t_list  *iden;

    ft_lstadd_back(&iden, ft_lstnew("NO", ""));
    ft_lstadd_back(&iden, ft_lstnew("SO", ""));
    ft_lstadd_back(&iden, ft_lstnew("WE", ""));
    ft_lstadd_back(&iden, ft_lstnew("EA", ""));
    ft_lstadd_back(&iden, ft_lstnew("F", ""));
    ft_lstadd_back(&iden, ft_lstnew("C", ""));
    (*vars).scene->map->iden = iden;
}

int    mapsize(t_map *m)
{
    if (((*m).mapx > 12 || (*m).mapy > 12) && ((*m).mapx >= 3 && (*m).mapy >= 3))
    {   if ((*m).mapx <= 37 && (*m).mapy <= 37)
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
