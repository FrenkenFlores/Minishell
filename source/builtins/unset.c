/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflores <fflores@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:38:23 by wabomina          #+#    #+#             */
/*   Updated: 2021/01/24 16:20:32 by fflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int		unset_valid(char *name)
{
	if (ft_isalpha(*name++) == 0)
		return (0);
	while (*name)
	{
		if (!ft_isalnum(*name) && *name != '_')
			return (0);
		name++;
	}
	return (1);
}

void	unset(t_shell *shell, t_command *command)
{
	int i;

	i = 1;
	while (command->argv[i])
	{
		if (!unset_valid(command->argv[i]))
		{
			ft_printf("minishell: unset: `%s': not a valid "\
				"identifier\n", command->argv[i]);
			g_last_exit_status = 1;
			return ;
		}
		if (check_env_exist(shell, command->argv[i]))
			remove_env(shell, command->argv[i]);
		i++;
	}
	upd_shell_path(shell);
}
