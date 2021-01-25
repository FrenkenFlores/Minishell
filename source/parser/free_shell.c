/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:36:02 by wabomina          #+#    #+#             */
/*   Updated: 2021/01/26 00:36:04 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void			free_command(t_shell *shell)
{
	if (!shell || !shell->command)
		return ;
	free(shell->command->correct_path);
	nested_free(shell->command->argv);
	free(shell->command->out_file_name);
	free(shell->command->input_file_name);
	if (shell->command->file_fd_in)
		close(shell->command->file_fd_in);
	if (shell->command->file_fd_out)
		close(shell->command->file_fd_out);
	free(shell->command);
	shell->command = 0;
}

void			free_tokens(t_shell *shell)
{
	t_token		*temp_token;

	while (shell && shell->tokens)
	{
		temp_token = shell->tokens;
		shell->tokens = shell->tokens->next;
		free(temp_token->data);
		free(temp_token);
	}
	shell->tokens = 0;
}

void			nested_free(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_buf(t_shell *shell)
{
	free(shell->buf);
	shell->buf = 0;
}
