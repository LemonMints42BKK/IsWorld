/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:36:24 by pnopjira          #+#    #+#             */
/*   Updated: 2023/09/05 14:46:10 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	// t_galaxy	*shell;

	(void)argc;
	(void)argv;
	// if(!(shell = (t_galaxy*)malloc(sizeof(t_galaxy))))
	// 	return (EXIT_FAILURE);
	// set_galaxy_shell (&shell, &envp);
    //	print_list(shell->env_ls); // test evn list from set_env()
	// shell.list = ft_env_set(envp);
	// ft_shell_set(&shell);

	// while (42)
	// {
	// 	ft_free_routine(&shell);
	// 	ft_line_set(&shell);
	// 	if (ft_continue(&shell, 1))
	// 		continue ;
	// 	add_history(shell.line);
	// 	shell.parsed = ft_parsed_set(&shell);
	// 	if (ft_continue(&shell, 2))
	// 		continue ;
	// 	ft_lvls(&shell);
	// 	ft_expand_all(&shell, shell.parsed, -1);
	// 	if (ft_continue(&shell, 3) || ft_redirection(&shell))
	// 		continue ;
	// 	ft_while(&shell);
	// }
	return (0);
}
