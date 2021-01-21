/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 23:37:30 by wabomina          #+#    #+#             */
/*   Updated: 2020/07/24 21:15:43 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	parse_options(t_params *data, va_list ap)
{
	int	tmp;

	tmp = data->i;
	if (ft_strchr(FLAGS, data->s[data->i]))
		check_flags(data);
	if (ft_isdigit(data->s[data->i]) || data->s[data->i] == '*')
		check_width(data, ap);
	if (data->s[data->i] == '.')
		check_precision(data, ap);
	(data->s[data->i] == '\0') ? data->i-- : 0;
	data->specifier = data->s[data->i];
	if (!(ft_strchr(SPECIFIER, data->s[data->i])))
		data->i = tmp - 1;
}

int		check_errors(t_params *data)
{
	int i;

	i = data->i;
	while ((data->s[i]) && !(ft_strchr(SPECIFIER, data->s[i])))
	{
		if (ft_isalpha(data->s[i]))
			break ;
		i++;
	}
	return (1);
}

void	init_data(t_params *data)
{
	data->zero = 0;
	data->minus = 0;
	data->width = 0;
	data->precision = -1;
	data->specifier = 0;
	data->length = 0;
}

void	init_again(t_params *data)
{
	data->zero = 0;
	data->minus = 0;
	data->width = 0;
	data->precision = -1;
	data->specifier = 0;
}

int		ft_printf(const char *s, ...)
{
	va_list		ap;
	t_params	data;

	va_start(ap, s);
	data.s = s;
	data.i = 0;
	init_data(&data);
	while (data.s[data.i] != '\0')
	{
		if (data.s[data.i] == '%' && data.s[data.i + 1])
		{
			data.i++;
			if (check_errors(&data))
			{
				init_again(&data);
				parse_options(&data, ap);
				parse_params(&data, ap);
			}
		}
		else
			ptf_ft_putchar_fd(data.s[data.i], 1, &data);
		data.i++;
	}
	va_end(ap);
	return (data.length);
}
