/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:51:11 by pnopjira          #+#    #+#             */
/*   Updated: 2023/09/09 14:53:37 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_ctrl_c(int signum)
{
	(void)signum;
	printf("\b \b\b \b \n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	// g_exit_status = 1;
}

void	handle_ctrl_c_child(int signum)
{
	(void)signum;
	printf("\b\b\n");
	// g_exit_status = 130;
}

void	handle_ctrl_backslash(int signum)
{
	(void)signum;
	printf("\b\b^\\Quit: 3\n");
// 	g_exit_status = 131;
 }

void	enable_signals(void)
{
	signal(SIGINT, handle_ctrl_c);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTERM, SIG_DFL);
	signal(SIGTSTP, SIG_DFL);
	signal(SIGTTIN, SIG_DFL);
	signal(SIGTTOU, SIG_DFL);
	signal(SIGCHLD, SIG_DFL);
}

void	enable_signals_child(void)
{
	signal(SIGINT, handle_ctrl_c_child);
	signal(SIGQUIT, handle_ctrl_backslash);
}

/*
void	ft_does_nothing(int signum)
{
	(void)signum;
	return ;
}

void	ft_exit(int signum)
{
	printf("Quit: %d\n", signum);
	exit(signum);
}

void	handler_ctrl(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
	else if (sig == SIGQUIT)
		signal(SIGQUIT, ft_does_nothing);
	else
		kill(getpid(), SIGSTOP);
	return ;
}

// void	sig_quit(int sig)
// {
// 	if (sig != SIGQUIT)
// 		return ;
// }
/*
int	enable_signals(t_isworld **prompt ,int	*exit_status)
{
	/* enable key to block or interrupt signal*/
	// (*prompt)->act_int.sa_handler = handler_ctrl;
	// (*prompt)->act_quit.sa_handler = sig_quit;
	// (*prompt)->act_noting.sa_handler = SIG_IGN;

	// (*prompt)->act_int.sa_flags = SA_RESTART;
	// (*prompt)->act_quit.sa_flags = SA_RESTART;

	// sigemptyset(&(*prompt)->act_int.sa_mask);
	// sigaddset(&(*prompt)->act_int.sa_mask, SIGINT);
	// sigaddset(&(*prompt)->act_int.sa_mask, SIGQUIT);

	// sigemptyset(&(*prompt)->act_quit.sa_mask);
	// sigaddset(&(*prompt)->act_quit.sa_mask, SIGQUIT)
	// sigaddset(&(*prompt)->act_quit.sa_mask, SIGCHLD);

	// if (sigaction(SIGINT, &(*prompt)->act_int, NULL) < 0)
	// 	return (EXIT_FAILURE);
	// if (sigaction(SIGQUIT, &(*prompt)->act_quit, NULL) < 0)
	// 	return (EXIT_FAILURE);
// 	return (EXIT_SUCCESS);
// }

