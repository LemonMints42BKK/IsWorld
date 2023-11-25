/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_invalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 06:00:23 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/25 07:20:42 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	explicit_error(int stage)
{
	if (stage != 0)
		perror(RED"Error\n"RESET);
    if (stage == 1)
        ft_putstr_fd(RED":empty file\n"RESET, 2);
    else if (stage == 2)
        ft_putstr_fd(RED":the identity type is invalid or lost\n"RESET, 2);
    else if (stage == 3)
        ft_putstr_fd(RED":the file path is invalid\n"RESET, 2);
	else if (stage == 4)
		ft_putstr_fd(RED":the map is too big or too small\n"RESET, 2);
	else if (stage == 5)
		ft_putstr_fd(RED":the map is invalid\n"RESET, 2);
	else if (stage == 6)
		ft_putstr_fd(RED":the color code is invalid\n"RESET, 2);
    else if (stage != 0)
        ft_putstr_fd(RED":unindentify\n"RESET, 2);
    return (stage);
}

int	ck_inden(int *err, t_list *iden)
{
	t_list	*tmp;

	tmp = iden;
	while(tmp)
	{
		if (ft_strlen(tmp->content) == 0)
		{
			*err = 2;
			return (EXIT_FAILURE);
		}
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}

int	rd_mapdata(char *maps_path, t_var *vars)
{
	char	*line;
	char	*tmp;
	int		fd;
	int		err;

	err = 1;
	fd = open(maps_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if ((*vars).scene->map->map_begin == 1)
			if (ck_inden(&err, vars->scene->map->iden))
				break;
		tmp = ft_strtrim(line, " ");
		free(line);
		line = NULL;
		ck_data_format(tmp, &err, vars);
		free(tmp);
		if (err != 0)
			break;
		line = get_next_line(fd);
	}
	if (line != NULL && line)
		free(line);
	close(fd);
	return (err);
}

int	invalid_filepath(char *maps_path, char *path, char *format)
{
	char	*begin;
	char	*end;
	int		len;
	int		fd;
	char	*fpath;

	begin = maps_path;
	len = ft_strlen(maps_path);
	end = maps_path + (len - 4);
	fpath = end;
	// check if the argument is valid
	if (len == 0)
		return (perror(RED"Error: Invalid Argument"RESET), 1);
	else if (ft_strncmp(begin, path, ft_strlen(path)))
		return (perror(RED"Error: Invalid file path "RESET), 1);
	else if (ft_strncmp(end, format, ft_strlen(format)))
		return (perror(RED"Error: Invalid file format "RESET), 1);
	// check if the file is exist
	fd = open(maps_path, O_RDONLY);
	if (fd == -1)
		return (perror(RED"Error: Invalid file name "RESET), 1);
	else
		close(fd);
	return (EXIT_SUCCESS);
}

int	invalid_color_code(char *rgb)
{
	char	**color;
	int		i;

	i = 0;
	color = ft_split(rgb, ',');
	while (color[i])
		i++;
	if (i > 3)
		return (perror(RED"Error: Invalid color code "RESET), 1);
	else if (ft_strlen(rgb) < 7)
		return (perror(RED"Error: Invalid color code "RESET), 1);
	else if (ft_atoi(color[0]) > 255 || ft_atoi(color[0]) < 0)
		return (perror(RED"Error: Invalid color code "RESET), 1);
	else if (ft_atoi(color[1]) > 255 || ft_atoi(color[1]) < 0)
		return (perror(RED"Error: Invalid color code "RESET), 1);
	else if (ft_atoi(color[2]) > 255 || ft_atoi(color[2]) < 0)
		return (perror(RED"Error: Invalid color code "RESET), 1);
	return (EXIT_SUCCESS);
}
