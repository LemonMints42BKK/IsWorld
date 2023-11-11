/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_invalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 06:00:23 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/11 06:08:58 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	invalid_filepath(char *maps_path, char *path, char *format)
{
	char	*begin;
	char	*end;
	int		len;
	int		fd;

	begin = maps_path;
	len = ft_strlen(maps_path);
	end = maps_path + (len - 4);
	// check if the argument is valid
	if (len == 0)
		return (perror(RED"Error: Invalid Argument"RESET), 1);
	else if (ft_strncmp(begin, path, 5) != 0)
		return (perror(RED"Error: Invalid file path "RESET), 1);
	else if (ft_strncmp(end, format, 4) != 0)
		return (perror(RED"Error: Invalid file format "RESET), 1);
	// check if the file is exist
	fd = open(maps_path, O_RDONLY);
	if (fd == -1)
		return (perror(RED"Error: Invalid file name "RESET), 1);
	else
		close(fd);
	return (0);
}

int	invalid_mapdata(char *maps_path)
{
	char	*line;
	char	*tmp;
	int		fd;
	int		err;
	int		tag_map;

	err = 1;
	tag_map = 0;
	fd = open(maps_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strtrim(line, " ");
		// printf("%s\n", tmp);	// debug tmp
		free(line);
		ck_data_format(tmp, &err);
		free(tmp);
		if (err != 0)
			break;
		line = get_next_line(fd);
	}
	close(fd);
	return (err);
}

