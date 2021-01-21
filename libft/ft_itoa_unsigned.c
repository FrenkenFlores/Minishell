/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 19:46:14 by wabomina          #+#    #+#             */
/*   Updated: 2020/07/24 20:12:54 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_lenint(unsigned long long int n)
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

static int			ft_z(unsigned long long int n)
{
	if (n >= 0)
		return (1);
	else
		return (2);
}

char				*ft_itoa_unsigned(unsigned long long int n)
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
