/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:33:36 by wabomina          #+#    #+#             */
/*   Updated: 2021/01/26 18:30:12 by fflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	i = 0;
	if (ft_strcmp(args[1], "-n"))
	{
		i = 1;
		new_line = 0;
	}
	while (args[i++])
	{
		if (ft_strcmp(args[i], "-n") == 0)
			ft_printf("%s", args[i]);
		if (args[i + 1] && (ft_strcmp(args[i], "-n") == 0))
			ft_printf(" ");
	}
	if (new_line)
		ft_printf("\n");
	g_last_exit_status = 0;
}
