/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:36:56 by wabomina          #+#    #+#             */
/*   Updated: 2021/01/26 00:36:58 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int		process_single_quote(t_quotes *quote, t_token *token,
									char **line, int i)
{
	if (!quote->dq)
		quote->sq = !quote->sq;
	token->data[i++] = *(*line)++;
	return (i);
}

int		process_double_quote(t_quotes *quote, t_token *token,
									char **line, int i)
{
	if (!quote->sq)
		quote->dq = !quote->dq;
	token->data[i++] = *(*line)++;
	return (i);
}

int		process_operators(t_shell *shell, t_token **token,
					   char **line, int i)
{
	int j; // unused?
	int l;

	j = 0;
	l = ft_strlen(*line);
	if (i)
	{
		(*token)->data[i] = '\0';
		i = 0;
		(*token)->next = (l > 1 ? token_init(shell, 2) : token_init(shell, 1));
		*token = (*token)->next;
	}
	(*token)->data[0] = *(*line)++;
	if (l > 1)
	{
		if (**line == (*token)->data[0])
			(*token)->data[1] = *(*line)++;
	}
	if (**line)
		*token = create_next_token(shell, *token, *line);
	return (i);
}

int		process_whitespaces(t_shell *shell, t_token **token,
										char **line, int i)
{
	while (ft_isspace(**line))
		(*line)++;
	if (i)
	{
		(*token)->data[i] = '\0';
		i = 0;
		if (**line)
			*token = create_next_token(shell, *token, *line);
	}
	else if (!**line)
		remove_last_token(shell);
	return (i);
}

int		process_out_operator(t_shell *shell, t_token **token,
										char **line, int i)
{
	if (i)
	{
		(*token)->data[i] = '\0';
		i = 0;
		if (*(*line + 1) == '>')
			(*token)->next = token_init(shell, 2);
		else
			(*token)->next = token_init(shell, 1);
		*token = (*token)->next;
	}
	(*token)->data[0] = *(*line)++;
	if (**line == '>')
		(*token)->data[1] = *(*line)++;
	if (**line)
		*token = create_next_token(shell, *token, *line);
	return (i);
}
