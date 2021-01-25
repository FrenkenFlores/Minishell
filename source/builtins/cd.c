/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:32:35 by wabomina          #+#    #+#             */
/*   Updated: 2021/01/24 14:32:39 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int		check_env_exist(t_shell *shell, char *var)
{
	int	i;

	i = 0;
	if (*var == 0)
		return (0);
	while (shell->env[i])
	{
		if (!ft_strncmp(shell->env[i], var, ft_strlen(var)))
			return (1);
		i++;
	}
	return (0);
}

void	add_env(t_shell *shell, char *variable, char *value)
{
	int		i;
	char	**new_env;

	new_env = (char **)(malloc(sizeof(char *) * (shell->env_len + 2)));
	if (!new_env)
		exit_shell(shell, EXIT_FAILURE);
	new_env[shell->env_len + 1] = NULL;
	i = 0;
	while (shell->env[i])
	{
		new_env[i] = shell->env[i];
		i++;
	}
	shell->env_len++;
	new_env[i] = ft_strjoin(variable, value);
	free(variable);
	free(value);
	free(shell->env);
	shell->env = new_env;
}

void	upd_env(t_shell *shell, char *var, char *new_value)
{
	int	i;

	i = 0;
	if (check_env_exist(shell, var))
	{
		while (shell->env[i])
		{
			if (!ft_strncmp(shell->env[i], var, ft_strlen(var)))
			{
				free(shell->env[i]);
				shell->env[i] = ft_strjoin(var, new_value);
				free(var);
				free(new_value);
				break ;
			}
			i++;
		}
	}
	else
		add_env(shell, var, new_value);
}

void	cd(t_shell *shell, char **args)
{
	char *current_cd;

	if (!args[1])
		return ;
	g_last_exit_status = 0;
	current_cd = getcwd(NULL, 0);
	if (chdir(args[1]) == -1)
	{
		if (args[1][0] == '\0')
			return ;
		ft_printf("minishell: cd: %s: ", args[1]);
		ft_printf("%s\n", strerror(errno));
		g_last_exit_status = 1;
	}
	upd_env(shell, ft_strdup("PWD="), getcwd(NULL, 0));
	shell->cwd = getcwd(NULL, 0);
	upd_env(shell, ft_strdup("OLDPWD="), current_cd);
}
