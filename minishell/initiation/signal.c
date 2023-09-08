/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:51:11 by pnopjira          #+#    #+#             */
/*   Updated: 2023/09/07 19:32:33 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handler_ctrl_c(int sig)
{
	if (sig != SIGINT)
		return ;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

void	sig_quit(int sig)
{
	if (sig != SIGQUIT)
		return ;
}

int	enable_signals(t_isworld **prompt ,int	*exit_status)
{
	/* enable key to block or interrupt signal*/
	(*prompt)->act_int.sa_handler = handler_ctrl_c;
	(*prompt)->act_quit.sa_handler = sig_quit;
	(*prompt)->act_noting.sa_handler = SIG_IGN;
	(*prompt)->act_int.sa_flags = 0;
	(*prompt)->act_quit.sa_flags = 0;
	(*prompt)->act_noting.sa_flags = 0;
	sigemptyset(&(*prompt)->act_int.sa_mask);
	sigemptyset(&(*prompt)->act_quit.sa_mask);
	sigemptyset(&(*prompt)->act_noting.sa_mask);
	if (sigaction(SIGINT, &(*prompt)->act_int, NULL) < 0)
		return (EXIT_FAILURE);
	if (sigaction(SIGQUIT, &(*prompt)->act_quit, NULL) < 0)
		return (EXIT_FAILURE);
	if (sigaction(SIGTSTP, &(*prompt)->act_noting, NULL) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
