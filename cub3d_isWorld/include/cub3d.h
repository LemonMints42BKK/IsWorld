/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:09:08 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/19 23:30:45 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>

# include <OpenGL/gl3.h>
# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "../libft/libft.h"
# include "game_setup.h"

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define RESET "\033[0m"

// define key for mac
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_M 14
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53

// define key for linux
// # define KEY_W 119
// # define KEY_A 97
// # define KEY_S 115
// # define KEY_D 100
// # define KEY_M 109
// # define KEY_LEFT 65361
// # define KEY_RIGHT 65363
// # define KEY_ESC 65307

# define WINDOW_WIDTH 1440
# define WINDOW_HEIGHT 832
# define PI 3.141592654
# define FOV 90
# define MOVE_SPEED 0.1
# define TEX_WIDTH 64
# define TEX_HIGHT 64

/*cub3d*/
int		check_invalid_filedata(char *maps_path, t_map *map, t_player  *p);
int		raycaster_loop(t_main *main);
void	show_main_struct(t_main *main);
/*pnopjira_utils*/
//00map_setup
int		rd_mapdata(char *maps_path, t_map *map, t_player *p);
void    iden_list(t_list **iden);
void	init_plan(t_map *plan);
void	init_player(t_player *player);
void	init_scene(t_frame *scene);
//01map_setup
int		is_invalid_input(char *argv, t_main *main);
void	init_main_struct(t_main *main_struc);
void	del_nl(char **line);
int		setup_pos(char *dir,int x, int y, t_player *p);
int		setup_pos_mapx(char **mapdata, int j, t_map *map, t_player *p);
//02map_setup
void	before_map_line(int fd2, int map_begin, char **line);
void	ck_invalid_map(int *err, int fd2, t_map *map, t_player *p);
void	print_map_original(char **map_original, t_map *map, t_player *p);
int		mapsize(t_map *m, t_player *p);
void	key_to_content(t_list *iden, char *key, char *content);
//03map_setup
int		set_main_struct(t_main	*main);
void	get_textures_path(t_main *main);
int		set_vp(t_main *main);
int		char_to_int_map(char **o_map, t_map *plan);
int		ck_map_info(t_map *map);
//check_dataformat
int		init_content(t_list *iden, char **dst, char **src, char *key);
int		ck_no_so_we_ea(char *tmp, t_list *iden);
int		ck_f_c_color(char *tmp, t_list *iden);
void	ck_data_format(char *tmp, int *err, t_map *map);
void	ck_invalid_data(int *err, int fd1, t_map *map);
//check_invalid
int		explicit_error(int stage);
int		invalid_filepath(char *maps_path, char *path, char *format);
int		invalid_color_code(char *rgb);
int		ck_identify(int *err, t_list *iden);
int		before_map(t_map *map, int *err);
//free_allocated
void	del(void *lst);
void	free_scene(t_frame *scene);
int		cub3d_exit(t_main *main_struc);
//get_next_line
char	*get_next_line(int fd);
//frame_setup
void 	translate_rgb(char *str, t_color *color);
unsigned int hexcode(t_frame *secen, char *key);
int		set_scene(t_frame *scene);
//player_setup
void	find_player_pos(t_map *mapfile, t_player *p);
void	begin_dir_of_player(t_main *main, char D);
void	camera_plane_of_player(t_main *main, char D);

/*ptungbun_utils*/
//reycaster
void	bg_init(t_vp *vars);
void    minimap_init(t_vp *vars);
t_imgdata	get_tex_image(t_vp *vp, char *path, int *w, int *h);
int		display_minimap(t_main *main);
int		display(t_main *main);
//minimap
void	draw_minimap(t_vp *vars, t_map *plan, t_coor *begin, t_coor *end);
void	draw_player(t_vp *vars, t_map *plan, t_player **p);
void    minimap(t_vp *vars, unsigned int color);
//game
void	background(t_vp *vars);
//key_controller
int		bottons(int keycode, t_main *main);
//01drawing_tools
void    print_bg(t_imgdata *img, t_coor begin, t_coor end, unsigned int color);
void	print_square_point(t_imgdata *img, t_coor p, unsigned int color);
void	print_player_charater(t_imgdata *img, t_coor p, unsigned int color);
void	set_point(t_coor *p,double x, double y);
void	my_mlx_pixel_put(t_imgdata *data, int x, int y, unsigned int color);
int     color3f(int r, int g, int b);
//init_ray_data.c
void	init_ray(t_main *main_struc);
void	get_step_ray_dist(t_ray *ray);
void	get_first_step_ray_dist(t_ray *ray, t_player *p);
void	perform_dda(t_ray *ray, int **map, t_player *p);
void	cal_ray_projection_dist_n_wall_hight(t_ray *ray);
//bresenham.c
void	bresenham_x(t_imgdata *img, int *x, int *y, int color);
void	imgpixelput(t_imgdata *img, int x, int y, int color);
void	bresenham_y(t_imgdata *img, int *x, int *y, int color);
void	drawline(t_imgdata *img, int *x, int *y, int color);
//cube3d_render.c
void	get_y(t_ray ray, int *y1, int *y2, int index);
void	cub3d_render(t_main *main_struc, t_vp *vp);
//rotate.c
void	rotate(t_main *main_struc, double degree);
//draw_wall.c
void	ray_on_wall_pos_cal(t_main *ms, t_ray *ray, t_player *p);
int		get_tex_color(t_imgdata *tex_img, int x, int y);
t_imgdata	*get_texture(t_ray *ray, t_vp *vp);
void	draw_wall(t_main *ms ,int x, int *y, t_ray *ray);

#endif

