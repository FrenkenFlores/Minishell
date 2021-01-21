/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 22:28:39 by wabomina          #+#    #+#             */
/*   Updated: 2020/07/27 22:28:47 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_itoa_base(size_t nb, int base)
{
	char	*str;
	size_t	tmp;
	size_t	i;

	tmp = nb;
	i = 1;
	while ((tmp /= base) >= 1)
		i++;
	if (!(str = (char *)malloc((i + 1) * sizeof(*str))))
		return (NULL);
	str[i] = '\0';
	while (i--)
	{
		if (nb % base < 10)
			str[i] = nb % base + '0';
		else
			str[i] = nb % base + 'a' - 10;
		nb /= base;
	}
	return (str);
}
