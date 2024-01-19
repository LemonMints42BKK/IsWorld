/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:31:21 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/19 19:26:00 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_SETUP_H
# define GAME_SETUP_H

# include "../libft/libft.h"
# include <stdbool.h>

typedef struct s_color
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}	t_color;

typedef struct s_coor //coordinate
{
	double	x;
	double	y;
}	t_coor;

typedef struct s_ray
{
	t_coor	raydir; //Xray coordinate on camera plane
	double	rdx; //X initial step x ray distance + total step rdx
	double	rdy; //X initial step y ray distance + total step rdy
	double	step_rdx; //X step x ray distance
	double	step_rdy; //X step y ray distance
	double	lcpd; //X local_cam_plane_dist
	int		step_side_x; //X the indicator to define step in x direction
	int		step_side_y; //X the indicator to define step in y direction
	bool	wall_hit_side; //X if hit N or S wall_hit_side = 0, if hit E or W wall_hit_side = 1
	double	proj_dist; //X project distance from camera
	int		wall_hight; //X wall hight distance
	int		wall_y_start; //X start from top
	int		wall_y_end; //X end at bottom
	// int		wall_x_start; //X  start from left
	// int		wall_x_end; //X end at right
	int		tex_x; //X texture x coordinate
	int		index; //X
}	t_ray;

typedef struct s_imgdata
{
	void	*img;
	char	*addr;
	int		bpp;
	int		llen;
	int		endian;
}	t_imgdata;

typedef struct s_map
{
	t_list	*iden; //
	bool	map_begin; //
	int		line_map_begin; //
	char	**map_original; //
	int		mapx; //
	int		mapy; //
	int 	mapsize; //
	int		**map; //
}	t_map;

typedef struct s_player
{
	int		map_x; //x position in map //
	int		map_y; //y position in map //
	t_coor	*pos; //position of player in coordinate system //
	t_coor	*dir; //direction of player //
	t_coor	*cam_plane; //the coordinate of the center of the camera plane //
	bool	one_player; //ok
	char	D; //ok
	int		psize; //ok
}	t_player;

typedef struct s_frame
{
	int				w;//width
	int				h;//height
	unsigned int	floor_color; //floor color
	unsigned int	ceiling_color; //ceiling color
	t_player		*p;//player position //
	t_map			*map; //
}	t_frame; 

typedef struct s_viewport /*t_mlx -> t_vp*/
{
	void		*mlx; //mlx_init()
	void		*win; //mlx_new_window()
	t_imgdata	*bgimg;  //
	t_imgdata	*mini_img;
	
	t_imgdata	tex_so_img;
	t_imgdata	tex_no_img;
	t_imgdata	tex_we_img;
	t_imgdata	tex_ea_img;
	 
	t_frame 	*scene; 
}	t_vp;

typedef struct s_main
{
	t_vp 		*viewport; 
	t_map		*filemap;
	t_player	*player; 
	t_ray		*ray;
	int			**map;
	int			wall_strip_width; 
	unsigned int	floor_color; //
	unsigned int	ceiling_color; //
	char		*tex_so; //
	char		*tex_we; //
	char		*tex_ea; //
	char		*tex_no; //

	int			tex_width;
	int			tex_hight;
	
	bool		one_player; //
	bool		on_minimap; //
}	t_main;	

// typedef struct s_main
// {
// 	t_vp		viewport;
// 	t_imgdata		mini_map; //->viewport.mini_img // unused
// 	int			**map; //->map->map
// 	int			wall_strip_width;
// 	t_player	*player;
// 	t_ray		*ray;
// 	double		cur_time;
// 	double		old_time;
// 	bool		one_player; //->player->one_player
// 	int			ms; //->player->ms
// }	t_main;

#endif
