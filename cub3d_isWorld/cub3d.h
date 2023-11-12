/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:09:08 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/12 21:16:50 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <OpenGL/gl3.h>
# include "mlx/mlx.h"
# include "get_next_line.h"
# include "libft/libft.h"
# include "game_setup.h"

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define RESET "\033[0m"
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_A_LEFT 0
# define KEY_S_DOWN 1
# define KEY_D_RIGHT 2
# define KEY_W_UP 13

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_meta
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}	t_meta;

typedef struct s_pos
{
	int	px;
	int	py;
}	t_pos;

typedef struct s_map
{
	t_meta	*info;
	char	**map;
	t_pos	player;
	int		row;
	int		col;
	t_data	img;
	t_var	*vars;
}	t_map;

/*pnopjira_utils*/
char	*get_next_line(int fd);
int		check_invalid_mapfile(char *maps_path);
int		explicit_error(int stage);
int		invalid_filepath(char *maps_path, char *path, char *format);
int		invalid_mapdata(char *maps_path);
void	ck_data_format(char *tmp, int *err);
int		key_handler(int keycode,t_map *scene);
int		free_on_exit(int keycode, t_var *vars);

/*ptungbun_utils*/
void    raycaster();
void	init(long mlx, t_map *scene);
int    display(t_map *scene);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
// test drawing
void    draw_player(t_map mini);
#endif

