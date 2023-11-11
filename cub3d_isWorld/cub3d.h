/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:09:08 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/11 13:43:50 by pnopjira         ###   ########.fr       */
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

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define RESET "\033[0m"

typedef struct s_metatag
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}	t_metatag;

typedef struct s_map
{
	char	**map;
	int		row;
	int		col;
}	t_map;

/*pnopjira_utils*/
char	*get_next_line(int fd);
int		invalid_filepath(char *maps_path, char *path, char *format);
int		invalid_mapdata(char *maps_path);
void	ck_data_format(char *tmp, int *err);

/*ptungbun_utils*/

#endif

