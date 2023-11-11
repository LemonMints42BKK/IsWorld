/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:26:37 by pnopjira          #+#    #+#             */
/*   Updated: 2023/11/11 05:41:00 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
int    explicit_error(int stage)
{
    if (stage != 0)
        ft_putstr_fd(RED"error\n"RESET, 2);
    if (stage == 1)
        ft_putstr_fd(RED":empty file\n"RESET, 2);
    else if (stage == 2)
        ft_putstr_fd(RED":the type identifier is invalid\n"RESET, 2);
    else if (stage == 3)
        ft_putstr_fd(RED":the map is invalid\n"RESET, 2);
    else if (stage != 0)
        ft_putstr_fd(RED":unindentify\n"RESET, 2);
    return (stage);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        if (invalid_filepath(argv[1], "maps/", ".cub"))
            return (ft_putstr_fd(GREEN"Used: maps/<filename>.cub\n"RESET, 2)\
            , 1);
        if (explicit_error(invalid_mapdata(argv[1])))
            return (1);
        else
            printf(GREEN"game casting"RESET"\n"); // game casting here
    } else
        return(ft_putstr_fd(GREEN"Used: ./cub3d maps/<filename>.cub\n"RESET, 2)\
        , 1);
    return (0);
}
