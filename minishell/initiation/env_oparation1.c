/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_oparation1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 03:46:59 by pnopjira          #+#    #+#             */
/*   Updated: 2023/09/06 14:20:56 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	push(t_env **top, char **key, char **value);
int		is_empty(t_env **top);
int		pop(t_env **top, char *key);

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

int	is_empty(t_env **top)
{
	if (*top == NULL)
		return (1);
	else
		return (0);
}

int    pop(t_env **top, char *key)
{
    t_env	*temp;
    t_env	*ptr1;
	t_env	*ptr2;

    if (!is_empty(top))
    {
		temp = *top;
		ptr1 = NULL;
		ptr2 = NULL;
        while (ft_strncmp(temp->key, key, ft_strlen(key)) != 0)
		{
			ptr1 = temp;
            temp = temp->next;
		}
        if (temp == NULL)
		{	printf("NOT MATCH");
            return (1);}
		if (ft_strlen(key) == ft_strlen(temp->key))
		{	if (ptr1 == NULL)
				*top = temp->next;
			else
			{
				if (temp->next == NULL)
					ptr1->next = NULL;
				else
				{
					ptr2 = temp->next;
					ptr1->next = ptr2;
				}
			}
			free_lst(&temp);}
		else
			return (1);
        ptr1 = NULL;
		ptr2 = NULL;
		return (EXIT_SUCCESS);
    }
}



