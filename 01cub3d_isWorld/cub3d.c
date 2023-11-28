/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:26:37 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/27 22:47:09 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game_setup.h"

int	check_invalid_filedata(char *maps_path, t_map **map)
{
	if (invalid_filepath(maps_path, "maps/", ".cub"))
		return (ft_putstr_fd(GREEN"Used: maps/<filename>.cub\n"RESET, 2), \
		EXIT_FAILURE);
	if (explicit_error(rd_mapdata(maps_path, map)))
		return (EXIT_FAILURE);
	if ((*map)->map_begin == true)
	{
		rd_mapdata_only(maps_path, map);
	}
	return (EXIT_SUCCESS);
}

int	raycaster(t_var *vars)
{
	t_pos	p;
	t_point	pos;
	t_point	mapp;

	(*vars).scene->p = &p;
	(*vars).scene->p->pos = &pos;
	(*vars).scene->p->mapp = &mapp;
	if (explicit_error(init_frame((*vars).scene)))
		return (EXIT_FAILURE);
	//deploy mlx instance and allocated window frame
	(*vars).mlx = mlx_init();
	(*vars).win = mlx_new_window((*vars).mlx, (*vars).scene->w, \
	(*vars).scene->h, "isWorld-cub3D");
	// t_list	*temp;
	// temp = (*vars).scene->map->iden;
	// while (temp)
	// {
	// 	printf("%s:%s\n", temp->key, temp->content);
	// 	temp = temp->next;
	// }
	//init cavas in to frame
	scene_init(vars);
	minimap_init(vars);
	//Keep file texture to img to struct of t_frame type
	/*windon controller*/
	mlx_hook((*vars).win, 17, 0, free_on_exit, vars);
	mlx_hook((*vars).win, 2, 0, bottons, vars);
	/*loop to call display into the frame*/
	mlx_loop_hook((*vars).mlx, display, vars);
	//It is an infinite loop that waits for an event
	mlx_loop((*vars).mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_var	vars;
	t_data	bgimg;
	t_data	mini;
	t_frame	scene;

	vars.bgimg = &bgimg;
	vars.scene = &scene;
	vars.mini_img = &mini;
	init_map(&scene);
	if (argc != 2)
		return (perror(GREEN"USED: ./cud3d maps/<filename>.cub"RESET), \
		EXIT_FAILURE);
	if (check_invalid_filedata(argv[1], &scene.map))
	{
		ft_lstclear(&scene.map->iden, del);
		free(scene.map);
		return (EXIT_FAILURE);
	}
	else
		if (raycaster(&vars))
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
