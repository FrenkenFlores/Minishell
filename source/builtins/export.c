/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:38:15 by wabomina          #+#    #+#             */
/*   Updated: 2021/01/24 14:38:17 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	ft_isalpha_shell(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_')
		return (1024);
	return (0);
}

int		export_valid(char *name)
{
	if (!ft_isalpha_shell(*name++))
		return (0);
	while (*name)
	{
		if (*name != '_' && !ft_isalnum(*name) && *name != '=' &&
			*name != ':' && *name != '/')
				return (0);
		name++;
	}
	return (1);
}

void	export(t_shell *shell, t_command *command)
{
	char	*var;
	char	*value;
	int		i;

	i = 1;
	if (command->argv[i] == NULL)
		print_env(shell);
	while (command->argv[i])
	{
		if (!export_valid(command->argv[i]))
		{
			ft_printf("minishell: export: `%s': not a valid "\
							"identifier\n", command->argv[i]);
			g_last_exit_status = 1;
			i++;
			continue ;
		}
		var = get_var_name(shell, command->argv[i]);
		value = get_var_value(shell, command->argv[i]);
		if (check_env_exist(shell, var))
			upd_env(shell, var, value);
		else
			add_env(shell, var, value);
		i++;
		g_last_exit_status = 0;
	}
	upd_shell_path(shell);
}

