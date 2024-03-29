/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:35:26 by wabomina          #+#    #+#             */
/*   Updated: 2021/01/26 00:35:34 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int				check_quotes_error(int single_q, int double_q,
								t_shell *shell)
{
	if (double_q || single_q)
	{
		g_last_exit_status = 258;
		print_error(0, "syntax error all quotes must be enclosed", 1);
		shell->parsing_error = 1;
		return (-1);
	}
	return (0);
}
