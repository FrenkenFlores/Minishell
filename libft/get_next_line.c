/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 01:28:42 by wabomina          #+#    #+#             */
/*   Updated: 2020/07/16 18:48:02 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_n(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != (char)c)
		i++;
	if (str[i] != (char)c)
		return (-1);
	return (i);
}

int	get_line(char *remain, char **line, int i)
{
	int len;

	*line = ft_substr(remain, 0, i);
	++i;
	len = ft_strlen(remain + i) + 1;
	ft_memmove(remain, remain + i, len);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*remain = NULL;
	char		buff[BUFFER_SIZE + 1];
	int			was_read;
	int			i;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || (read(fd, buff, 0) < 0))
		return (-1);
	if (remain && (((i = find_n(remain, '\n')) != -1)))
		return (get_line(remain, line, i));
	while (((was_read = read(fd, buff, BUFFER_SIZE)) > 0))
	{
		buff[was_read] = '\0';
		remain = ft_strjoin_gnl(remain, buff);
		if (((i = find_n(remain, '\n')) != -1))
			return (get_line(remain, line, i));
	}
	if (remain)
	{
		*line = ft_strdup(remain);
		free(remain);
		remain = NULL;
		return (was_read);
	}
	*line = ft_strdup("");
	return (was_read);
}
