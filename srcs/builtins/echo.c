
#include "../../minishell.h"

void	echo(char **args)
{
	int i;
	int	new_line;

	if (args[1] == NULL)
	{
		ft_printf("\n");
		return ;
	}
	new_line = 1;
	i = 1;
	if (ft_strcmp(args[1], "-n"))
	{
		i = 2;
		new_line = 0;
	}
	while (args[i])
	{
		ft_printf("%s", args[i]);
		if (args[i + 1])
			ft_printf(" ");
		i++;
	}
	if (new_line)
		ft_printf("\n");
	g_last_exit_status = 0;
}
