/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:37:33 by wabomina          #+#    #+#             */
/*   Updated: 2021/01/26 00:37:34 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int				shell_get_line(t_shell *shell, char **temp_line,
							char **line)
{
	size_t		i;

	i = 0;
	while ((*temp_line)[i] != '\n')
		if ((*temp_line)[i++] == '\0')
			return (0);
	(*temp_line)[i] = '\0';
	if (!(*line = ft_strdup(*temp_line)))
	{
		free(*temp_line);
		free_buf(shell);
		exit_shell(shell, EXIT_FAILURE);
	}
	free(*temp_line);
	*temp_line = NULL;
	return (1);
}

static void		join_buf(t_shell *shell, char **temp_line, char *buf)
{
	char		*temp;

	temp = *temp_line;
	if (!(*temp_line = ft_strjoin(*temp_line, buf)))
	{
		free(temp);
		free_buf(shell);
		exit_shell(shell, EXIT_FAILURE);
	}
	free(temp);
}

static int		clear(t_shell *shell, char **line,
				char **temp_line, char *buf)
{
	free(*temp_line);
	*temp_line = NULL;
	return (0);
}

int				shell_read_fd(t_shell *shell, char **line,
								char **temp_line, char *buf)
{
	ssize_t		bytes;

	while ((bytes = read(0, buf, BUFFER_SIZE)) >= 0)
	{
		if (g_sigint_flag)
			g_sigint_flag = clear(shell, line, temp_line, buf);
		buf[bytes] = '\0';
		if (bytes == 0 && !*temp_line)
		{
			free_buf(shell);
			!TEST ? write(2, "exit\n", 5) : 0;
			exit_shell(shell, g_last_exit_status);
		}
		ft_dprintf(2, "  \b\b");
		if (*temp_line)
			join_buf(shell, temp_line, buf);
		else if (!(*temp_line = ft_strdup(buf)))
			return (-1);
		if (shell_get_line(shell, temp_line, line))
			break ;
	}
	return (bytes);
}

int				read_line_from_stdin(t_shell *shell, char **line)
{
	if (shell_gnl(shell, line) == -1)
	{
		write(2, "get_next_line() error\n", 22);
		return (-1);
	}
	return (0);
}
