//
// Created by Wilton Abomination on 1/22/21.
// SEGMENTATION FAULT (((

#include "../../minishell.h"

static void		free_shell(t_shell *shell)
{
	if (!shell)
		return ;
	nested_free(shell->path);
	free(shell->cwd);
	nested_free(shell->buildin_commands);
	nested_free(shell->env);
	free(shell->line);
	free(shell->last_var);
	close(shell->fd_stdin);
	close(shell->fd_stdout);
	free(shell->buf);
	free(shell);
}

void			exit_shell(t_shell *shell, int exit_status)
{
	free_command(shell);
	free_tokens(shell);
	free_shell(shell);
	if (exit_status == EXIT_FAILURE && errno)
		print_error(0, strerror(errno), 1);
	exit(exit_status);
}

void	close_shell(t_shell *shell)
{
	errno = 0;
	if (!ft_isnbr(shell->command->argv[1]))
	{
		ft_printf("exit\n");
		//ft_printf("minishell: exit: %s: numeric argument "\
						"required\n", shell->command->argv[1]);
		exit_shell(shell, 255);
	}
	if (ft_arrlen(shell->command->argv) > 2)
	{
		ft_printf("exit\n");
		ft_printf("minishell: exit: too many arguments\n");
		g_last_exit_status = 1;
	}
	else
	{
		ft_printf("exit\n");
		exit_shell(shell, EXIT_SUCCESS);
	}
}

