/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 17:13:24 by wabomina          #+#    #+#             */
/*   Updated: 2020/05/27 00:40:06 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char *)dest;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
	return (dest);
}