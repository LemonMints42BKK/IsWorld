/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:26:37 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/15 21:49:32 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game_setup.h"

int	check_invalid_filedata(char *maps_path, t_map **map, t_pos **p)
{
	if (invalid_filepath(maps_path, "maps/", ".cub"))
		return (ft_putstr_fd(GREEN"Used: maps/<filename>.cub\n"RESET, 2), \
		EXIT_FAILURE);
	if (explicit_error(rd_mapdata(maps_path, map, p)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	raycaster(t_var *vars)
{
	t_point	pos;

	(*vars).scene->p->pos = &pos;
	if (explicit_error(init_frame((*vars).scene)))
		return (EXIT_FAILURE);
	//deploy mlx instance and allocated window frame
	(*vars).mlx = mlx_init();
	(*vars).win = mlx_new_window((*vars).mlx, (*vars).scene->w, \
	(*vars).scene->h, "isWorld-cub3D");
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

int	is_invalid_input(char *argv, t_main *main_struc)
{
	t_var	vars;
	t_data	bgimg;
	t_data	mini;
	t_frame	scene;

	(void)main_struc;
	vars.bgimg = &bgimg;
	vars.mini_img = &mini;
	vars.scene = &scene;
	init_map(&scene);
	
	if (check_invalid_filedata(argv, &scene.map, &scene.p))
	{
		free_scene(&vars.scene);
		return (EXIT_FAILURE);
	}
	else if (raycaster(&vars))
		return (EXIT_FAILURE);
	main_struc->map = scene.map;
	return (EXIT_SUCCESS);
}

void	init_main_struct(t_main *main_struc)
{
	main_struc->main_mlx = NULL;
	main_struc->map = NULL;
	main_struc->player = NULL;
	main_struc->ray = NULL;
	main_struc->n_ray = 0;
	main_struc->cur_time = 0;
	main_struc->old_time = 0;
	main_struc->one_player = false;	
}

void	cub3d_exit(t_main *main_struc)
{
	(void)main_struc;
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_main	main_struc;
	
	init_main_struct(&main_struc);
	if (argc != 2)
		return (perror(GREEN"USED: ./cud3d maps/<filename>.cub"RESET), \
		EXIT_FAILURE);
	if(is_invalid_input(argv[1], &main_struc))
		return (cub3d_exit(&main_struc), EXIT_FAILURE);
	// if (reycaster_loop(&main_struc))
	// 	return (cub3d_exit(&main_struc), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
