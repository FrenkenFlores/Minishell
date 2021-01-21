/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:12:10 by wabomina          #+#    #+#             */
/*   Updated: 2021/01/19 18:12:16 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisnum(char *s)
{
	if (ft_isdigit(*s) || ft_strchr("-+", *s))
	{
		s++;
		while (*s)
		{
			if (ft_isdigit(*s))
				s++;
			else
				return (0);
		}
	}
	else
		return (0);
	return (1);
}
