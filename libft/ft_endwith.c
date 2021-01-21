/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endwith.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:03:53 by wabomina          #+#    #+#             */
/*   Updated: 2021/01/19 18:04:00 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_endwith(char *str, char *suff)
{
	int suff_len;
	int str_len;

	suff_len = ft_strlen(suff);
	str_len = ft_strlen(str);
	if (str_len >= suff_len)
		return (ft_strcmp(str + str_len - suff_len, suff));
	return (0);
}
