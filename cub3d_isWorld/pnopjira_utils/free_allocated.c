/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_allocated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:42:34 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/21 11:28:00 by pnopjira         ###   ########.fr       */
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

void	free_int_map(int **tab,int mapy)
{
	int j;

	j = 0;
	while (j < mapy)
		free(tab[j++]);
	free(tab);
}

void	free_map(t_map *map)
{
	int j;
	int	i;
	
	i = 0;
	j = 0;
	if (map->iden)
		ft_lstclear(&map->iden, del);
	if (map->map_original)
	{
		while (map->map_original[i])
			free(map->map_original[i++]);
		free(map->map_original);
	}
	if (map->map)
		free_int_map(map->map, map->mapy);
}

void	free_player(t_player *p)
{
	free(p->pos);
	free(p->dir);
	free(p->cam_plane);
}

void	free_scene(t_frame *scene)
{
	t_frame	*s;

	s = scene;
	if (s->map)
	{
		free_map(s->map);
		free(s->map);
	}
	if (s->p)
	{
		free_player(s->p);
		free(s->p);
	}
	s->map = NULL;
	s->p = NULL;
}

int	cub3d_exit(t_main *main_struc)
{
	t_vp *vp;

	vp = main_struc->viewport;
	if(vp)
	{
		if (vp->scene)
		{
			free_scene(vp->scene);
			free(vp->scene);
		}
		if (vp->bgimg)
		{
			if (vp->bgimg->img)
				mlx_destroy_image(vp->mlx, vp->bgimg->img);
			free(vp->bgimg);
		}
		if (vp->mini_img)
		{
			if (vp->mini_img->img)
				mlx_destroy_image(vp->mlx, vp->mini_img->img);
			free(vp->mini_img);
		}
		if (vp->mlx && vp->win)
			mlx_destroy_window(vp->mlx, vp->win);
		free(vp);
	}
	if (main_struc->ray)
		free(main_struc->ray);
	return (0);
}