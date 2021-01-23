
#include "../../minishell.h"

static void		quit_handler(int signum)
{
	int			exit_status;

	ft_printf("\b\b  \b\b");
	if ((exit_status = wait_for_process()) == -1)
		return ;
	else if (exit_status == 131)
		write(2, "Quit: 3\n", 8);
	(void)signum;
}

static void		int_handler(int signum)
{
	int			exit_status;

	if ((exit_status = wait_for_process()) == -1 && g_sigint_flag != 2)
	{
		ft_printf("\b\b  \b\b");
		ft_printf("\n");
		print_prompt();
		g_sigint_flag = 1;
		errno = 0;
	}
	else if (exit_status == 130)
	{
		ft_printf("\n");
		g_sigint_flag = 0;
	}
	else
		g_sigint_flag = 2;
	(void)signum;
}

void			set_signals_handlers(void)
{
	signal(SIGQUIT, quit_handler); // (ctrl + \)
	signal(SIGINT, int_handler); // ctrl + C
}
