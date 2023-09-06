/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_n_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:47:25 by pnopjira          #+#    #+#             */
/*   Updated: 2023/09/06 21:56:12 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_prompt(t_isworld	**prompt);
void	wr_history(char *line, t_isworld *prompt);
void	rd_history(t_isworld *prompt);

void	get_prompt(t_isworld	**prompt)

{
	char	*line;
	char	*buffer;

	buffer = (*prompt)->cmdline;
	if (!(line = (char *)malloc(sizeof(char) * 1024)))
		return ;
	line = readline(PROMPT);
	if (line && (ft_strncmp(line, " ", 1) != 0))
	{
		ft_strlcpy(buffer, line, 1024);
		add_history(line);
//		wr_history(line, *prompt);
	}
	free(line);
}

void	wr_history(char *line, t_isworld *prompt)
{
	int		fd;
	char	*his;

	his = seach_lst(prompt->envls, "PWD");
	his = ft_strjoin(his, HISTORY_FILE);
	fd = open(his, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	free (his);
	if (fd == -1)
		ft_putstr_fd("Error : To open history file\n", 2);
	ft_putstr_fd(line, fd);
	write(fd, "\n", 1);
	if (close(fd) == -1)
		ft_putstr_fd("Error : To close history file\n", 2);
}

void	rd_history(t_isworld *prompt)
{
	int		fd;
	char	*ch;
	char	*str;
	char	*his;

	rl_clear_history();
	his = seach_lst(prompt->envls, "PWD");
	his = ft_strjoin(his, HISTORY_FILE);
	fd = open(his, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	free (his);
	if (fd == -1)
		ft_putstr_fd("Error : to open history file\n", 2);
	ch = get_next_line(fd);
	while (ch != NULL)
	{
		str = ft_strtrim(ch, "\n");
		free (ch);
		add_history(str);
		free(str);
		ch = get_next_line(fd);
	}
	if (close(fd) == -1)
		ft_putstr_fd("Error : to close history file\n", 2);
}



