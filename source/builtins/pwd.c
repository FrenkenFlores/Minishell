//
// Created by Wilton Abomination on 1/4/21.
//
#include "../../minishell.h"

void			pwd(t_shell *shell)
{
	ft_printf("%s\n", shell->cwd);
	g_last_exit_status = 0;
}