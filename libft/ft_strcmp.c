/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 03:19:34 by wabomina          #+#    #+#             */
/*   Updated: 2021/01/21 03:19:37 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (!(s1 && s2))
		return (-1);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (*str1 == *str2 && *str1 && *str2)
	{
		str1++;
		str2++;
	}
	if (*str1 == '\0' && *str2 == '\0')
		return (1);
	return (0);
}
