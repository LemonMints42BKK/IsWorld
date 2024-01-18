/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_allocated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:42:34 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/17 23:15:43 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/game_setup.h"

void	del(void *lst)
{
	t_list	*tmp;

	tmp = (t_list *)lst;
	free(tmp->key);
	free(tmp->content);
	tmp->key = NULL;
	tmp->content = NULL;
}

void	free_scene(t_frame *scene)
{
	t_frame	*s;
	int		i;
	
	i = 0;
	s = scene;
	ft_lstclear(&s->map->iden, del);
	if (s->map->map_original)
		while (s->map->map_original[i])
			free(s->map->map_original[i++]);
	i = 0;
	if (s->map->map)
		while (s->map->map[i])
			free(s->map->map[i++]);
	free(s->map);
	free(s->p->pos);
	free(s->p->dir);
	free(s->p->cam_plane);
	free(s->p);
	s->map = NULL;
	s->p = NULL;
}

int	cub3d_exit(t_main *main_struc)
{
	t_vp *vp;

	vp = main_struc->viewport;
	mlx_destroy_image( vp->mlx, vp->bgimg->img);
	mlx_destroy_image(vp->mlx, vp->mini_img->img);
	mlx_destroy_window(vp->mlx, vp->win);
	if (vp->scene)
		free_scene(vp->scene);
	if (main_struc->ray)
		free(main_struc->ray);
	return (0);
}