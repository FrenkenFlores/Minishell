/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 03:52:10 by wabomina          #+#    #+#             */
/*   Updated: 2020/07/27 03:52:34 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	parse_params(t_params *data, va_list ap)
{
	char c;

	c = data->s[data->i];
	if (c == 'c')
		ft_print_c(data, ap);
	else if (c == 's')
		ft_print_s(data, ap);
	else if (c == 'p')
		ft_print_p(data, ap);
	else if (c == 'd')
		ft_print_d(data, ap);
	else if (c == 'i')
		ft_print_i(data, ap);
	else if (c == 'u')
		ft_print_u(data, ap);
	else if (c == 'x')
		ft_print_x(data, ap);
	else if (c == 'X')
		ft_print_xupper(data, ap);
	else if (c == '%')
		ft_print_pers(data);
}
