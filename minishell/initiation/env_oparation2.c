/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_oparation2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:13:39 by pnopjira          #+#    #+#             */
/*   Updated: 2023/09/07 18:01:14 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_lst(t_env *top);
void	free_lst(t_env **temp);
int		clear_linklst(t_env **top);
char	*seach_lst(t_env *top, char *key);
//void	sort_lst(t_env **top);

void	print_lst(t_env *top)
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

void  free_lst(t_env **temp)
{
	if (*temp && (*temp)->key)
    {
		free((*temp)->key);
    	free((*temp)->value);
	}
	if (*temp)
    	free(*temp);
	*temp = NULL;
	return ;
}

int	clear_linklst(t_env **top) //cannot clear all linklist yet ****
{
	t_env	*ptr1;
	t_env	*ptr2;

	ptr1 = *top;
	ptr2 = NULL;
	while (ptr1)
	{
		ptr2 = ptr1->next;
		free_lst(&ptr1);
		ptr1 = ptr2;
		ptr2 = NULL;
	}
	return(EXIT_SUCCESS);
}

char	*seach_lst(t_env *top, char *key)
{
	t_env	*ptr;

	ptr = top;
	while (ptr)
	{
		if (ft_strncmp(ptr->key, key, ft_strlen(key)) == 0 && ptr->value)
			if (ft_strlen( ptr->key) == ft_strlen(key))
				return (ptr->value);
		ptr = ptr->next;
	}
	return (NULL);
}
