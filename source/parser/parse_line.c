/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 00:36:17 by wabomina          #+#    #+#             */
/*   Updated: 2021/01/26 00:36:18 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char				*find_wave(t_shell *shell, char *src)
{
	int i;
	int j;

	i = 0;
	while (shell->env[i])
	{
		j = 0;
		while (shell->env[i][j] == src[j])
			j++;
		if (j == ft_strlen(src))
			return (shell->env[i] + ft_strlen(src) + 1);
		i++;
	}
	return (NULL);
}

static int				process_wave(t_shell *shell, t_token **token)
{
	char *str;

	str = ft_strdup(find_wave(shell, "USER"));
	if (!str)
		return (-10);
	free((*token)->data);
	(*token)->data = ft_strjoin("/Users/", str);
	return (-9);
}

static int				process_not_quoted(t_shell *shell, t_token **token,
										char **line, int i)
{
	if (ft_strchr(";|<", **line))
		i = process_operators(shell, token, line, i);
	else if (ft_isspace(**line))
		i = process_whitespaces(shell, token, line, i);
	else if (**line == '>')
		i = process_out_operator(shell, token, line, i);
	else
		(*token)->data[i++] = *(*line)++;
	return (i);
}

t_token					*parse_line(t_shell *shell, char *line)
{
	t_quotes			quote;
	int					i;
	t_token				*token;
	t_token				*first_token;

	quote.sq = 0;
	quote.dq = 0;
	i = 0;
	first_token = token_init(shell, ft_strlen(line));
	shell->tokens = first_token;
	token = first_token;
	while (*line && i != -9)
		if (*line == '\\')
			i = skip_backslashed(token, &line, i);
		else if (*line == '"')
			i = process_double_quote(&quote, token, &line, i);
		else if (*line == '\'')
			i = process_single_quote(&quote, token, &line, i);
		else if (*line == '~')
			i = process_wave(shell, &token);
		else if (quote.dq || quote.sq)
			token->data[i++] = *line++;
		else if (!quote.dq && !quote.sq)
			i = process_not_quoted(shell, &token, &line, i);
	return (first_token);
}
