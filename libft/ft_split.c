/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:11:03 by wabomina          #+#    #+#             */
/*   Updated: 2020/05/30 01:00:49 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			count_w(const char *s, char c)
{
	int i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
			i++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (i);
}

static size_t		len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static char			**clear(char **s, int i)
{
	while (i > 0)
	{
		free(s[i]);
		i--;
	}
	free(s[i]);
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		w;
	int		j;

	i = 0;
	w = 0;
	if (!s || !(result = (char **)malloc(sizeof(char *) * (count_w(s, c) + 1))))
		return (NULL);
	while ((j = 0) || s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			if (!(result[w] = (char*)malloc(sizeof(char) * \
				(len(s + i, c) + 1))))
				return (clear(result, w));
			while (s[i] != '\0' && s[i] != c)
				result[w][j++] = s[i++];
			result[w++][j] = 0;
		}
	}
	result[w] = 0;
	return (result);
}
