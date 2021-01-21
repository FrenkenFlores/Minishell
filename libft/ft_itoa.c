/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 01:36:17 by wabomina          #+#    #+#             */
/*   Updated: 2020/05/27 23:40:56 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_lenint(int n)
{
	int				i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int			ft_z(int n)
{
	if (n >= 0)
		return (1);
	else
		return (2);
}

char				*ft_itoa(int n)
{
	char			*res;
	long int		nbr;
	int				len;

	nbr = n;
	len = ft_lenint(nbr) + ft_z(nbr);
	if (!(res = (char *)malloc(len)))
		return (NULL);
	if (nbr == 0)
		res[0] = '0';
	if (nbr < 0)
	{
		res[0] = '-';
		nbr *= -1;
	}
	while (nbr)
	{
		len--;
		res[len - 1] = nbr % 10 + '0';
		nbr /= 10;
	}
	len = ft_lenint(n) + ft_z(n);
	res[len - 1] = '\0';
	return (res);
}
