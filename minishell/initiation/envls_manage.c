/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envls_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 03:46:59 by pnopjira          #+#    #+#             */
/*   Updated: 2023/09/06 04:13:28 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		check_valid(char *str, int *j);
void	push(t_env **top, char **key, char **value);
void	print_list(t_env *top);

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

void	push(t_env **top, char **key, char **value)
{
	t_env	*temp;
	t_env	*ptr;

	ptr = *top;
	temp = (t_env *)malloc(sizeof(t_env));
	if (!temp)
		temp = NULL;
	temp->key = *key;
	temp->value = *value;
	temp->next = NULL;
	if (ptr != NULL)
	{
		while(ptr->next != NULL)
			ptr = ptr->next;
		 ptr->next = temp;
	}
	else
		*top = temp;
	ptr = NULL;
	temp = NULL;
}

void	print_list(t_env *top)
{
	t_env	*ptr;

	ptr = top;
	while (ptr)
	{
		if (ptr->key && ptr->value)
			printf("%s=%s\n", ptr->key, ptr->value);
		ptr = ptr->next;
	}
}

