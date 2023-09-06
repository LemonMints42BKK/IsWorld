/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:36:24 by pnopjira          #+#    #+#             */
/*   Updated: 2023/09/06 14:34:26 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_isworld	*prompt;

	(void)argc;
	(void)argv;
	if(!(prompt = (t_isworld*)malloc(sizeof(t_isworld))))
		return (EXIT_FAILURE);
	set_isworld_shell (&prompt, &envp);
//	print_lst(prompt->envls); //to show environment variables from set_env()

	while (42)
	{

	}
	return (0);
}
