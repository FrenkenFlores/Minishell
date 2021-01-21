
#include "../../minishell.h"

/*
** Print list of environment variables. Like 'env' in bash
*/

void	print_env(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->env[i])
		ft_printf("%s\n", shell->env[i++]);
	g_last_exit_status = 0;
}
