/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:38:32 by pnopjira          #+#    #+#             */
/*   Updated: 2023/09/06 04:10:12 by pnopjira         ###   ########.fr       */
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
# include <readline/history.h>
# include <readline/readline.h>

# define PROMPT ":\033[0;92mGa\033[0;33mla\033[0;91mzy\033[0;95mol\
\033[0;34m</>\033[0m "

typedef struct s_env
{
	char	*key;
	char	*value;
	struct s_env *next;
}	t_env;

typedef struct	s_isworld
{
	t_env	*envls;
	char	cmdline[1024];
	int		*exit_status;

}	t_isworld;
////*expansion*////

////*initiation*////
/*init_isworld_env.c*/
int		set_isworld_shell (t_isworld **prompt, char ***envp);
int		set_envlist(t_env	**envls,char ***envp);
int		count_env(char	**envp);
t_env	*init_env(int envc, char ***env);
int		key_and_value(char *str, char **key, char **value);
/*envls_manage.c*/
int		check_valid(char *str, int *j);
void	push(t_env **top, char **key, char **value);
void	print_list(t_env *top);

////*parentheses*////

////*parser*////

////*pipeline*////

////*readline*////

////*redirection*////

////*signals*////

////*utiles*////

////*bin*////
#endif
