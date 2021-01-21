/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 16:08:48 by wabomina          #+#    #+#             */
/*   Updated: 2020/05/27 00:19:41 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	unsigned char	*p;

	if (!(p = (unsigned char *)malloc(n * size)))
		return (NULL);
	ft_memset(p, 0, n * size);
	return ((void *)p);
}
