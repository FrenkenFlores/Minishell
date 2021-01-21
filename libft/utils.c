/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 23:28:40 by wabomina          #+#    #+#             */
/*   Updated: 2020/07/24 21:58:29 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	checkoptions_gap(int gaps, char c, t_params *data, int option)
{
	int	i;

	if (data->minus == option)
	{
		i = 0;
		while (i++ < gaps)
		{
			write(1, &c, 1);
			data->length++;
		}
	}
}

void	gaps(int gaps, char c, t_params *data)
{
	int	i;

	i = 0;
	while (i++ < gaps)
		ptf_ft_putchar_fd(c, 1, data);
}

char	flag_relate(t_params *data)
{
	(data->zero == 1 && data->minus == 1) ? data->zero = 0 : 0;
	(data->zero == 1 && data->precision != -1) ? data->zero = 0 : 0;
	if (data->zero == 1)
		return ('0');
	return (' ');
}
