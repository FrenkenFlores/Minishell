/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflores <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:16:33 by fflores           #+#    #+#             */
/*   Updated: 2021/01/26 18:18:33 by fflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void				free_data_and_exit(t_shell *shell, char **new_data,
											char *var_name)
{
	free(var_name);
	free(*new_data);
	exit_shell(shell, EXIT_FAILURE);
}

static void				set_last_var(t_shell *shell, char **new_data,
									char *var_name)
{
	char		*temp;
	char		*temp_var;

	temp_var = 0;
	if (!(temp = ft_strjoin("$", var_name)))
		free_data_and_exit(shell, new_data, var_name);
	if (!shell->last_var)
	{
		if (!(shell->last_var = ft_strdup(temp)))
			free_data_and_exit(shell, new_data, var_name);
	}
	else
	{
		temp_var = shell->last_var;
		if (!(shell->last_var = ft_strjoin(shell->last_var, temp)))
			free_data_and_exit(shell, new_data, var_name);
	}
	free(temp);
	free(temp_var);
}

static char				*get_value_by_name_and_free_varname(t_shell *shell,
															char *var_name)
{
	char				**env_tab;
	char				*var_value;
	int					len;

	var_value = 0;
	env_tab = shell->env;
	len = ft_strlen(var_name);
	while (*env_tab)
	{
		if (!ft_strncmp(*env_tab, var_name, len) && *((*env_tab) + len) == '=')
		{
			if (!(var_value = ft_strdup((*env_tab) + len + 1)))
			{
				free(var_name);
				return (0);
			}
		}
		env_tab++;
	}
	free(var_name);
	if (!var_value)
		var_value = ft_strdup("");
	return (var_value);
}

char					*arg_type_num(char **var_name, t_shell *shell,
							char **new_data, char **data)
{
	char *var_value;

	if (!(*var_name = ft_calloc(2, sizeof(char))))
		free_data_and_exit(shell, new_data, 0);
	(*var_name)[0] = *(*data)++;
	(*var_name)[1] = '\0';
	set_last_var(shell, new_data, *var_name);
	if (!(var_value = get_value_by_name_and_free_varname(shell, *var_name)))
		free_data_and_exit(shell, new_data, 0);
	return (var_value);
}

char					*arg_type_alpha(char **var_name, t_shell *shell,
							char **new_data, char **data)
{
	int		i;
	char	*var_value;

	i = 0;
	if (!(*var_name = ft_calloc(ft_strlen(*data) + 1, sizeof(char))))
		free_data_and_exit(shell, new_data, 0);
	while (**data && ft_isalnum(**data))
		(*var_name)[i++] = *(*data)++;
	set_last_var(shell, new_data, *var_name);
	if (!(var_value = get_value_by_name_and_free_varname(shell, *var_name)))
		free_data_and_exit(shell, new_data, 0);
	return (var_value);
}
