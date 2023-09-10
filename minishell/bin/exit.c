/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:07:23 by pnopjira          #+#    #+#             */
/*   Updated: 2023/09/10 01:10:02 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	clean_exit(int code_error, t_isworld **data)
{
	free_lst(&(*data)->envls);
	free (*data);
	write (1, "exit\n", 5);
	rl_clear_history();
	exit (code_error);
}

void	isworld_exit(int ac, char **av, t_isworld **prompt_data)
{
	if (ac == 1 )
		clean_exit(EXIT_SUCCESS, prompt_data);
	else if (ac == 2)
	{
		if (ft_isdigit(av[1][0]))
			clean_exit(av[1][0], prompt_data);
		else
		{
			printf("exit\nisworld: exit: %s: numeric argument required\n", av[1]);
			(*prompt_data)->exit_status = 255;
		}
	}
	else
	{
		printf("exit\nminishell: exit: too many arguments\n");
		(*prompt_data)->exit_status = EPERM;
	}
}
