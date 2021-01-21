/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 18:00:04 by wabomina          #+#    #+#             */
/*   Updated: 2020/07/24 19:39:35 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_u(t_params *data, va_list ap)
{
	char	*p;
	int		len;
	int		spaces;
	int		c;

	p = ft_itoa_unsigned(va_arg(ap, unsigned int));
	len = (*p == '0' && data->precision == 0) ? 0 : ft_strlen(p);
	spaces = (data->precision > len) ? data->precision : len;
	c = flag_relate(data);
	(data->minus == 1) ? print_nbr(len, data, p) : 0;
	gaps(data->width - spaces, c, data);
	(data->minus == 0) ? print_nbr(len, data, p) : 0;
	free(p);
}

void	ft_print_d(t_params *data, va_list ap)
{
	char	*p;
	int		len;
	int		spaces;
	int		c;
	int		negative;

	p = ft_itoa(va_arg(ap, int));
	negative = (*p == '-') ? 1 : 0;
	len = (*p == '0' && data->precision == 0) ? 0 : ft_strlen(p);
	(negative && data->precision > 1) ? data->precision++ : 0;
	spaces = (data->precision > len) ? data->precision : len;
	c = flag_relate(data);
	(data->minus == 1) ? print_nbr(len, data, p) : 0;
	if (c == '0' && data->minus == 0 && negative)
		ptf_ft_putchar_fd('-', 1, data);
	else
		negative = 0;
	gaps(data->width - spaces, c, data);
	(data->minus == 0) ? print_nbr(len, data, p + negative) : 0;
	free(p);
}

void	ft_print_i(t_params *data, va_list ap)
{
	char	*p;
	int		len;
	int		spaces;
	int		c;
	int		negative;

	p = ft_itoa(va_arg(ap, int));
	negative = (*p == '-') ? 1 : 0;
	if (*p == '0' && data->precision == 0)
		len = 0;
	else
		len = ft_strlen(p);
	(negative && data->precision > len) ? data->precision++ : 0;
	spaces = (data->precision > len) ? data->precision : len;
	c = flag_relate(data);
	(data->minus == 1) ? print_nbr(len, data, p) : 0;
	if (c == '0' && data->minus == 0 && negative)
		ptf_ft_putchar_fd('-', 1, data);
	else
		negative = 0;
	gaps(data->width - spaces, c, data);
	(data->minus == 0) ? print_nbr(len, data, p + negative) : 0;
	free(p);
}

void	print_nbr(int len, t_params *data, char *p)
{
	int negative;

	negative = 0;
	if (*p == '-')
	{
		negative = 1;
		ptf_ft_putchar_fd('-', 1, data);
	}
	gaps(data->precision - len, '0', data);
	((data->precision == 0) && \
	(*p == '0')) ? 0 : ptf_ft_putstr_fd(p + negative, 1, data);
}
