/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03map_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:53:43 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/19 23:18:47 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	set_main_struct(t_main	*main)
{
	if(set_vp(main))
		return (EXIT_FAILURE);
	main->filemap = main->viewport->scene->map;
	main->player = main->viewport->scene->p;
	find_player_pos(main->filemap, main->player);
	begin_dir_of_player(main, main->player->D);
	camera_plane_of_player(main, main->player->D);
	main->map = main->viewport->scene->map->map;
	main->wall_strip_width = main->viewport->bgimg->llen / WINDOW_WIDTH;
	main->floor_color = main->viewport->scene->floor_color;
	main->ceiling_color = main->viewport->scene->ceiling_color;
	get_textures_path(main);
	main->viewport->tex_so_img = get_tex_image(main->viewport ,main->tex_so , \
	&main->tex_width, &main->tex_hight);
	main->viewport->tex_no_img = get_tex_image(main->viewport ,main->tex_no , \
	&main->tex_width, &main->tex_hight);
	main->viewport->tex_we_img = get_tex_image(main->viewport ,main->tex_we , \
	&main->tex_width, &main->tex_hight);
	main->viewport->tex_ea_img = get_tex_image(main->viewport ,main->tex_ea , \
	&main->tex_width, &main->tex_hight);	
	main->one_player = main->viewport->scene->p->one_player;
	return (EXIT_SUCCESS);
}

void get_textures_path(t_main *main)
{
	t_list *ptr;
	
	ptr = main->filemap->iden;
	while (ptr)
	{
		if (ft_strncmp(ptr->key, "NO", 1) == 0)
			main->tex_no = ptr->content;
		else if (ft_strncmp(ptr->key, "SO", 1) == 0)
			main->tex_so = ptr->content;
		else if (ft_strncmp(ptr->key, "WE", 1) == 0)
			main->tex_we = ptr->content;
		else if (ft_strncmp(ptr->key, "EA", 1) == 0)
			main->tex_ea = ptr->content;
		ptr = ptr->next;
	}
}

int set_vp(t_main *main)
{
	if (explicit_error(set_scene(main->viewport->scene)))
	 	return (EXIT_FAILURE);
	main->viewport->mlx = mlx_init();
	main->viewport->win = mlx_new_window(main->viewport->mlx, main->viewport->scene->w, \
	main->viewport->scene->h, "isWorld-cub3D");
	bg_init(main->viewport);
	minimap_init(main->viewport);
	return (EXIT_SUCCESS);
}

int	char_to_int_map(char **o_map, t_map *plan)
{
	int		**n_map;
	const int	i = plan->mapx;
	const int	j = plan->mapy;
	int y;
	int x;

	y = 0;
	n_map = (int **)malloc(sizeof(int *) * j);
	while (y < j)
		n_map[y++] = (int *)malloc(sizeof(int) * i);
		
	y = 0;
	while(y < j)
	{	
		x = 0;
		while (o_map[y][x] != '\0')
		{
			if (o_map[y][x] == '1')
				n_map[y][x] = 1;
			else if (o_map[y][x] == ' ')
				n_map[y][x] = -1;
			else if (o_map[y][x] == '0')
				n_map[y][x] = 0;
			else 
				n_map[y][x] = 0;
			x++;
		}
		while (x < i)
		{
			n_map[y][x] = -1;
			x++;
		}
		y++;
	}
	plan->map = n_map;
	return (EXIT_SUCCESS);
}

int	ck_map_info(t_map *map)
{
	if (map->map_begin == 0)
	{
		map->map_begin = 1;
		(map->mapy)++;
	}
	else
	{
		(map->mapy)++;
	}
	return (EXIT_SUCCESS);
}