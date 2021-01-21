
#include "../../minishell.h"

void	free_buf(t_shell *shell)
{
	free(shell->buf);
	shell->buf = 0;
}
