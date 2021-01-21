/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 00:06:31 by wabomina          #+#    #+#             */
/*   Updated: 2020/05/31 18:43:19 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	sublen;
	char	*part;

	i = 0;
	if (!s)
		return (NULL);
	if (len <= 0 || start > ft_strlen(s))
		return (ft_strdup(""));
	sublen = ft_strlen(s + start);
	if (sublen < len)
		len = sublen;
	if (!(part = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		part[i] = s[start + i];
		i++;
	}
	part[i] = '\0';
	return (part);
}
