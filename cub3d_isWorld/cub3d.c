/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:26:37 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/16 19:09:19 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"
#include "./include/game_setup.h"

int	check_invalid_filedata(char *maps_path, t_map *map, t_player *p)
{
	if (invalid_filepath(maps_path, "maps/", ".cub"))
		return (ft_putstr_fd(GREEN"Used: maps/<filename>.cub\n"RESET, 2), \
		EXIT_FAILURE);
	if (explicit_error(rd_mapdata(maps_path, map, p)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	show_main_struct(t_main *main)
{
	printf("\nmain struct:\n");
	printf("viewport: %p\n", main->viewport);
		printf("\tmlx: %p\n", main->viewport->mlx);
		printf("\twin: %p\n", main->viewport->win);
		printf("\tbgimg: %p\n", main->viewport->bgimg);
			printf("\t\timg: %p\n", main->viewport->bgimg->img);
			printf("\t\taddr: %p\n", main->viewport->bgimg->addr);
			printf("\t\tbpp: %d\n", main->viewport->bgimg->bpp);
			printf("\t\tllen: %d\n", main->viewport->bgimg->llen);
			printf("\t\tendian: %d\n", main->viewport->bgimg->endian);
		// printf("\tmini_img: %p\n", main->viewport->mini_img);
		// 	printf("\t\timg: %p\n", main->viewport->mini_img->img);
		// 	printf("\t\taddr: %p\n", main->viewport->mini_img->addr);
		// 	printf("\t\tbpp: %d\n", main->viewport->mini_img->bpp);
		// 	printf("\t\tllen: %d\n", main->viewport->mini_img->llen);
		// 	printf("\t\tendian: %d\n", main->viewport->mini_img->endian);
		//printf("\tscene: %p\n", main->viewport->scene);
			// printf("\t\tscreen width: %d\n", main->viewport->scene->w);
			// printf("\t\tscreen height: %d\n", main->viewport->scene->h);
			// printf("\t\tfloor color: %x\n", main->viewport->scene->floor_color);
			// printf("\t\tceiling color: %x\n", main->viewport->scene->ceiling_color);
			printf("\t\tp player: %p\n", main->viewport->scene->p);
				printf("\t\t\tmap_x: %d\n", main->viewport->scene->p->map_x);
				printf("\t\t\tmap_y: %d\n", main->viewport->scene->p->map_y);
				printf("\t\t\tpos: %p\n", main->viewport->scene->p->pos);
					printf("\t\t\t\tx: %f\n", main->viewport->scene->p->pos->x);
					printf("\t\t\t\ty: %f\n", main->viewport->scene->p->pos->y);
				printf("\t\t\tdir: %p\n", &main->viewport->scene->p->dir);
					printf("\t\t\t\tx: %f\n", main->viewport->scene->p->dir.x);
					printf("\t\t\t\ty: %f\n", main->viewport->scene->p->dir.y);
				printf("\t\t\tcam_plane: %p\n", &main->viewport->scene->p->cam_plane);
					printf("\t\t\t\tx: %f\n", main->viewport->scene->p->cam_plane.x);
					printf("\t\t\t\ty: %f\n", main->viewport->scene->p->cam_plane.y);
				printf("\t\t\tone_player: %d\n", main->viewport->scene->p->one_player);
				printf("\t\t\tD: %c\n", main->viewport->scene->p->D);
				printf("\t\t\tpsize: %d\n", main->viewport->scene->p->psize);
			// printf("filemap: %p\n", main->filemap);
				// printf("\tiden: %p\n", main->filemap->iden);
				// t_list *ptr = main->filemap->iden;	
				// while (ptr)
				// {
				// 	printf("\t\t%s %s\n", ptr->key, ptr->content);
				// 	ptr = ptr->next;
				// }
			// 	printf("\tmap size x: %d\n", main->filemap->mapx);
			// 	printf("\tmap size y: %d\n", main->filemap->mapy);
			// 	printf("\tminimap size: %d\n", main->filemap->minisize);
			// 	printf("int **map: %p\n", main->filemap->map);
			// 	for (int i = 0; i < main->filemap->mapy; i++) {
			// 		for (int j = 0; j < main->filemap->mapx; j++) {
			// 			printf("%d ", main->filemap->map[i][j]);
			// 		}
			// 		printf("\n");
			// 	}
	printf("int **map: %p\n", main->map);
		for (int i = 0; i < main->filemap->mapy; i++) {
			for (int j = 0; j < main->filemap->mapx; j++) {
				printf("%d ", main->map[i][j]);
			}
			printf("\n");
		}
	printf("ray: %p\n", main->ray);
	printf("wall_strip_width: %d\n", main->wall_strip_width);
	printf("floor color: %x\n", main->floor_color);
	printf("ceiling color: %x\n", main->ceiling_color);
	printf("SO: %s\n", main->tex_so);
	printf("NO: %s\n", main->tex_no);
	printf("WE: %s\n", main->tex_we);
	printf("EA: %s\n", main->tex_ea);
	printf("one_player: %d\n", main->one_player);
	printf("on_minimap: %d\n", main->on_minimap);
	printf("\n");
}

int	raycaster_loop(t_main *main)
{
	t_vp	*vars;

	vars = (*main).viewport;
	// if (set_vp(vars))
	// 	return (cub3d_exit(main), EXIT_FAILURE);
	// (*main).wall_strip_width = vars->bgimg->llen / (N_RAY - 1);
	show_main_struct(main);
	printf("before init_ray\n");
	// init_ray(main); //SEGV on unknown address 0x000000000774 (pc 0x00010ee4f40d bp 0x7ffee0dbf350 sp 0x7ffee0dbf270 T0)
	printf("after init_ray\n");
//	mlx_hook(vars->win, 17, 0, free_on_exit, vars);
//	mlx_hook(vars->win, 2, 0, bottons, main);
	// if (main->on_minimap == 1)
    // 	mlx_loop_hook(vars->mlx, display_minimap, main);
	// else
	// {	// try to display wall in 2 way but didn't work at all, fixed init_ray() first.
	// 	cub3d_render(main, main->viewport); // SEGV on unknown address 0x00000000005c (pc 0x00010c6b7fad bp 0x7ffee3551cc0 sp 0x7ffee3551ae0 T0)
	// 	//mlx_loop_hook(vars->mlx, display, main);
	// }
//	mlx_loop(vars->mlx);
	return (0);
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
	if (set_main_struct(&main_struc))
		return (cub3d_exit(&main_struc), EXIT_FAILURE);
	raycaster_loop(&main_struc);
	return (EXIT_SUCCESS);
}
