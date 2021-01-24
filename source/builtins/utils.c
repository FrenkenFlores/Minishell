/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:45:24 by wabomina          #+#    #+#             */
/*   Updated: 2021/01/24 14:53:35 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	remove_env(t_shell *shell, char *variable)
{
	int		i;
	char	**new_env;
	int		offset;

	offset = 0;
	new_env = (char **)malloc(sizeof(char *) * shell->env_len);
	if (!new_env)
		exit_shell(shell, EXIT_FAILURE);
	new_env[shell->env_len - 1] = NULL;
	i = 0;
	while (shell->env[i])
	{
		if (!ft_strncmp(shell->env[i], variable, ft_strlen(variable)))
		{
			free(shell->env[i]);
			offset = 1;
		}
		else
			new_env[i - offset] = shell->env[i];
		i++;
	}
	shell->env_len--;
	free(shell->env);
	shell->env = new_env;
}
