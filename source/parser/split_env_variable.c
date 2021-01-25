/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_env_variable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:37:53 by wabomina          #+#    #+#             */
/*   Updated: 2021/01/26 00:37:54 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_var_name(t_shell *shell, char *str)
{
	int		len;
	int		i;
	char	*var_name;

	len = 0;
	while (str[len] && str[len] != '=')
		len++;
	len++;
	var_name = (char *)malloc(sizeof(char) * (len + 1));
	if (!var_name)
		exit_shell(shell, EXIT_FAILURE);
	var_name[len--] = '\0';
	var_name[len--] = '=';
	i = 0;
	while (len-- >= 0)
	{
		var_name[i] = str[i];
		i++;
	}
	return (var_name);
}

char	*get_var_value(t_shell *shell, char *str)
{
	int		len;
	int		i;
	char	*var_value;
	char	*ptr;
	char	*temp;

	ptr = ft_strchr(str, '=');
	if (ptr == NULL)
		return (ft_strdup(""));
	ptr++;
	len = 0;
	temp = ptr;
	while (*ptr++)
		len++;
	var_value = (char *)malloc(sizeof(char) * (len + 1));
	if (!var_value)
		exit_shell(shell, EXIT_FAILURE);
	var_value[len--] = '\0';
	i = 0;
	while (len-- >= 0)
	{
		var_value[i] = *temp++;
		i++;
	}
	return (var_value);
}
