
#include "../../minishell.h"

void		print_error(char *error_source, char *error_msg, int new_line)
{
	ft_putstr_fd("minishell: ", 2);
	if (error_source)
	{
		ft_putstr_fd(error_source, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(error_msg, 2);
	if (new_line)
		ft_putstr_fd("\n", 2);
}
