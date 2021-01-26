/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepath_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 04:40:04 by wabomina          #+#    #+#             */
/*   Updated: 2021/01/26 04:40:07 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int		prepath_check(t_shell *shell, t_command *command, char *data)
{
	int		ret;

	if (!(ret = check_buildin_abs_rel(shell, command, data)))
	{
		command->is_found = 1;
		return (1);
	}
	else if (ret == 1 || ret == 2)
	{
		if (ret == 1)
			g_last_exit_status = 127;
		else
			g_last_exit_status = 126;
		return (1);
	}
	return (0);
}
