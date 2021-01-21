/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 17:20:28 by wabomina          #+#    #+#             */
/*   Updated: 2020/05/27 01:34:57 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!src || !dst)
		return (0);
	if (size <= 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && size > 0 && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = src[i];
	if (size != 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}
