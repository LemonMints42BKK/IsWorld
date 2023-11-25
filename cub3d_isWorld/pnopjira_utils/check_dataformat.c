/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dataformat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 05:59:07 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/25 06:51:06 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_content(t_list **iden, char **dst, char **src, char *key)
{
	char	*tmp;
	tmp = ft_strtrim(*src, key);
	*dst = ft_strtrim(tmp, " ");
	free(tmp);
	key_to_content((void**)iden, key, *dst);
}

int	ck_no_so_we_ea_path(char *tmp, t_list **iden)
{
	char	*str1;
	char	*str2;

	str2 = NULL;
	str1 = (char*)malloc(sizeof(char) * ft_strlen(tmp));
	ft_strlcpy(str1, tmp, ft_strlen(tmp) - 1);
	if (!ft_strncmp(str1, "NO ", 3))
		init_content(iden, &str2, &str1, "NO");
	else if (!ft_strncmp(str1, "SO ", 3))
		init_content(iden, &str2, &str1, "SO");
	else if (!ft_strncmp(str1, "WE ", 3))
		init_content(iden, &str2, &str1, "WE");
	else if (!ft_strncmp(str1, "EA ", 3))
		init_content(iden, &str2, &str1, "EA");
	if (str1 != NULL && str1)
		free (str1);
	if (invalid_filepath(str2, "./textures/", ".xpm"))
    {
		free(str2);
		return (3);
	}
	if (str2 != NULL && str1)
		free (str2);
	return(EXIT_SUCCESS);
}

int ck_f_c_color(char *tmp, t_list **iden)
{
	char	*str1;
	char	*str2;

	str2 = NULL;
	str1 = (char*)malloc(sizeof(char) * ft_strlen(tmp));
	ft_strlcpy(str1, tmp, ft_strlen(tmp) - 1);
	if (!ft_strncmp(str1, "F ", 2))
		init_content(iden, &str2, &str1, "F");
	else if (!ft_strncmp(str1, "C ", 2))
		init_content(iden, &str2, &str1, "C");
	if (str1 != NULL && str1)
		free (str1);
	if (invalid_color_code(str2))
	{
		free(str2);
		return (6);
	}
	if (str2 != NULL && str1)
		free (str2);
	return(EXIT_SUCCESS);
}

void ck_data_format(char *tmp, int *err, t_var *vars)
{
	if (tmp[0] == '\n' && tmp[1] == '\0')
	{
		printf("newline\n"); //for test
		*err = 0;
	}
	else if ( !ft_strncmp( tmp, "NO ", 3) || !ft_strncmp( tmp, "SO ", 3) \
	|| !ft_strncmp( tmp, "WE ", 3) || !ft_strncmp( tmp, "EA ", 3))
		*err = ck_no_so_we_ea_path(tmp, &(*vars).scene->map->iden);
	else if ( !ft_strncmp( tmp, "F ", 2) || !ft_strncmp( tmp, "C ", 2))
		*err = ck_f_c_color(tmp, &(*vars).scene->map->iden);
	else if ( !ft_strncmp( tmp, "1", 1) || !ft_strncmp( tmp, "0", 1))
	{
		printf("map\n"); //for test
		if ((*vars).scene->map->map_begin == false)
			(*vars).scene->map->map_begin = true;
		*err = 0;
	}
	else
	{
		printf(RED"ERROR"RESET"%s", tmp); //for test
		*err = -1;
	}
}
