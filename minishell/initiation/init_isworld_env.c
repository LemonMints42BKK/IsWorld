/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_isworld_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 03:47:03 by pnopjira          #+#    #+#             */
/*   Updated: 2023/09/07 23:01:20 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		set_isworld_shell (t_isworld **prompt, char ***envp);
int		set_envlist(t_env	**envls,char **envp);
t_env	*init_env(int envc, char ***env);
int		key_and_value(char *str, char **key, char **value);
int		check_valid(char *str, int *j);

int		set_isworld_shell (t_isworld **prompt, char ***envp)
{
	/*all valuables in t_isworld first inited here*/
	(*prompt)->envls = NULL;
	(*prompt)->exit_status = 0;
	/* init evnp into sturc of t_evn (singer linklist)*/
	if(set_envlist(&(*prompt)->envls, *envp))
		return(EXIT_FAILURE);

	/* read_history from file .isworld_history then add to history*/
	rd_history(*prompt);
	/* enable key to block or interrupt signal*/
//	enable_signals(prompt, &(*prompt)->exit_status);

	return(EXIT_SUCCESS);
}

int		set_envlist(t_env	**envls,char **envp)
{
	int	envc;

	envc = 0;
	while (envp[envc])
		envc++;
	if(!(*envls = init_env(envc, &envp)))
		return(EXIT_FAILURE);
	else
		return(EXIT_SUCCESS);
}

t_env	*init_env(int envc, char ***env)
{
	t_env  *top;
	char	**envp;
	char	*key;
	char	*value;
	int		i;

	i = 0;
	top = NULL;
	envp = *env;
	while(i < envc)
	{
		if (key_and_value(envp[i], &key, &value))
			return (NULL);
		if (key || value)
			push(&top, &key, &value);
		i++;
	}
	return(top);
}

int		key_and_value(char *str, char **key, char **value)
{
	int	j;
	int	len;

	j = 0;
	len = ft_strlen(str);
	if (check_valid(str, &j))
	{
		*key = (char*)malloc(sizeof(char) * (j + 1));
		if (!*key)
			return (perror("error"), EXIT_FAILURE);
		*value = (char*)malloc(sizeof(char) * (len - j + 2));
		if (!*value)
			return (perror("error"), EXIT_FAILURE);
		ft_strlcpy(*key, str, j + 1);
		ft_strlcpy(*value, (str + j + 1), (len - j + 2));
	}
	return (EXIT_SUCCESS);
}

int		check_valid(char *str, int *j)
{
	int valid_str;

	valid_str = 0;
	*j = 0;
	 while (str[*j] != '\0')
	{
		(*j)++;
		if (str[*j] == '=')
		{
			valid_str = 1;
			break ;
		}
	}
	return (valid_str);
}
