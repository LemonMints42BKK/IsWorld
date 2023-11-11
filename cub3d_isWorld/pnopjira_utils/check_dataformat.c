/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dataformat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 05:59:07 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/11 06:07:57 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	map_begin(char *tmp)
{
	if (ft_strncmp( tmp, "1", 1) == 0)
		return (1);
	return (0);
}

void ck_data_format(char *tmp, int *err)
{
	if (tmp[0] == '\n' && tmp[1] == '\0')
		printf("newline\n");
	else if ( !ft_strncmp( tmp, "NO ", 3) || !ft_strncmp( tmp, "SO ", 3) \
	|| !ft_strncmp( tmp, "WE ", 3) || !ft_strncmp( tmp, "EA ", 3))
		printf("NO/SO/WE/EA\n");
	else if ( !ft_strncmp( tmp, "F ", 2) || !ft_strncmp( tmp, "C ", 2))
		printf("F & C\n");
	else if ( ft_strncmp( tmp, "1", 1) == 0)
		printf("map\n");
	else
	{
		printf(RED"ERROR"RESET"%s", tmp);
		*err = -1;
		return ;
	}
	*err = 0;
}
