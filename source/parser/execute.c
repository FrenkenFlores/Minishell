/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:34:19 by wabomina          #+#    #+#             */
/*   Updated: 2021/01/26 00:34:21 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int				run_buildin(t_shell *shell, t_command *command)
{
	if (ft_strcmp(command->argv[0], "echo"))
		echo(command->argv);
	else if (ft_strcmp(command->argv[0], "cd"))
		cd(shell, command->argv);
	else if (ft_strcmp(command->argv[0], "pwd"))
		pwd(shell);
	else if (ft_strcmp(command->argv[0], "export"))
		export(shell, command);
	else if (ft_strcmp(command->argv[0], "unset"))
		unset(shell, command);
	else if (ft_strcmp(command->argv[0], "env"))
		print_env(shell);
	else if (ft_strcmp(command->argv[0], "exit"))
		close_shell(shell);
	else
		return (0);
	return (1);
}

static int		exec_buildins_if_no_pipe(t_shell *shell, t_command *command,
										int pipeline)
{
	if (!pipeline)
	{
		if (ft_strcmp(command->argv[0], "export"))
		{
			export(shell, command);
			return (1);
		}
		else if (ft_strcmp(command->argv[0], "unset"))
		{
			unset(shell, command);
			return (1);
		}
		else if (ft_strcmp(command->argv[0], "exit"))
		{
			close_shell(shell);
			return (1);
		}
		else if (ft_strcmp(command->argv[0], "cd"))
		{
			cd(shell, command->argv);
			return (1);
		}
	}
	return (0);
}

void			execute(t_shell *shell, t_command *command)
{
	int			fd_in;
	int			fd_out;
	int			pid;
	static int	pipeline;

	pipeline = pipeline ? pipeline : command->is_pipe;
	if (exec_buildins_if_no_pipe(shell, command, pipeline))
		return ;
	fd_in = set_fd_in(shell, command);
	fd_out = set_fd_out(shell, command);
	dup2(fd_in, 0);
	close(fd_in);
	dup2(fd_out, 1);
	close(fd_out);
	pid = fork();
	if (pid == -1)
		exit_shell(shell, EXIT_FAILURE);
	if (pid == 0)
		child_process(shell, command);
	if (!command->is_pipe)
	{
		pipeline = 0;
		parent_process(shell, pid);
	}
}
