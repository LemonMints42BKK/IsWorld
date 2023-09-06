/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:38:32 by pnopjira          #+#    #+#             */
/*   Updated: 2023/09/06 22:44:44 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <dirent.h>
# include <signal.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <termios.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <readline/history.h>
# include <readline/readline.h>

# define HISTORY_FILE "/.isworld_history"
# define PROMPT ":\033[0;34mIs\033[0;33mWorld\033[0;32m<$>\033[0m "

typedef struct s_env
{
	char	*key;
	char	*value;
	struct s_env *next;
}	t_env;

typedef struct	s_isworld
{
	t_env	*envls; // usefor builtin: env, export, unset
	int		*exit_status; // usefor exit status when "echo $?" or "echo $? | cat -e"

	char	cmdline[1024]; // usefor readline() or gercwd()
}	t_isworld;

////*expansion*////

////*initiation*////
/*init_isworld_env.c*/
int		set_isworld_shell (t_isworld **prompt, char ***envp);//set t_isworld, read history, enable signals(cltr+c, cltr+d, cltr+\), init env into linklist(t_env)
int		set_envlist(t_env	**envls,char **envp); //init env into linklist(t_env)
t_env	*init_env(int envc, char ***env); //init env
int		key_and_value(char *str, char **key, char **value); //init env
int		check_valid(char *str, int *j); //init env
/*env_oparation1.c*/
void	push(t_env **top, char **key, char **value); // push new env data into stack:- export
int		is_empty(t_env **top); // check stack is empty or not
int		pop(t_env **top, char *key); // pop env data from stack:- unset
/*env_oparation2.c*/
void	print_lst(t_env *top); // print all env data in stack:- env, export
void	free_lst(t_env **temp); // free env data node in stack, just one node
int		clear_linklst(t_env **top); // free all env data in stack;
char	*seach_lst(t_env *top, char *key); // search env data in stack, use key to search for value:- export {arg}, unset {arg}, pwd, echo $USER
/*prompt_n_history.c*/
void	get_prompt(t_isworld	**prompt); // get user input(readline) to prompt->cmdline and add to history:
void	wr_history(char *line, t_isworld *prompt); // write history to file .isworld_history ***underconstruction***
void	rd_history(t_isworld *prompt); // read history from file .isworld_history ***underconstruction***

////*parentheses*////

////*parser*////

////*pipeline*////

////*readline*////

////*redirection*////

////*signals*////

////*utiles*////

////*bin*////
#endif
