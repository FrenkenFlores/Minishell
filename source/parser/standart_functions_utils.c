
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

void	upd_env(t_shell *shell, char *variable, char *new_value)
{
	int	i;

	i = 0;
	if (check_env_exist(shell, variable))
	{
		while (shell->env[i])
		{
			if (!ft_strncmp(shell->env[i], variable, ft_strlen(variable)))
			{
				free(shell->env[i]);
				shell->env[i] = ft_strjoin(variable, new_value);
				free(variable);
				free(new_value);
				break ;
			}
			i++;
		}
	}
	else
		add_env(shell, variable, new_value);
}

int		check_env_exist(t_shell *shell, char *variable)
{
	int	i;

	i = 0;
	if (*variable == 0)
		return (0);
	while (shell->env[i])
	{
		if (!ft_strncmp(shell->env[i], variable, ft_strlen(variable)))
			return (1);
		i++;
	}
	return (0);
}
