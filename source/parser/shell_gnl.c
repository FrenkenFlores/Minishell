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

int	shell_gnl(t_shell *shell, char **line)
{
	static char		*temp_line;
	int				status;

	if (!line)
		return (-1);
	if (!(shell->buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (temp_line)
		if (shell_get_line(shell, &temp_line, line))
		{
			free_buf(shell);
			return (1);
		}
	if ((status = shell_read_fd(shell, line, &temp_line, shell->buf)) == -1)
	{
		free_buf(shell);
		return (-1);
	}
	free_buf(shell);
	if (status)
		return (1);
	*line = temp_line;
	temp_line = NULL;
	return (0);
}
