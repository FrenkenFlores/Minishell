/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 17:10:53 by wabomina          #+#    #+#             */
/*   Updated: 2020/05/28 14:25:10 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*p1;
	char	*p2;

	i = 0;
	p1 = (char *)dest;
	p2 = (char *)src;
	while (i < n)
	{
		p1[i] = p2[i];
		if (p1[i] == (char)c)
			return ((char *)dest + i + 1);
		i++;
	}
	return (NULL);
}
