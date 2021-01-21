/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 21:10:33 by wabomina          #+#    #+#             */
/*   Updated: 2020/07/25 17:12:31 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_x(t_params *data, va_list ap)
{
	char	*p;
	int		spaces;
	char	c;
	int		len;

	p = ft_itoa_base(va_arg(ap, unsigned int), 16);
	if (*p == '0' && data->precision == 0)
		len = 0;
	else
		len = ft_strlen(p);
	spaces = (data->precision > len) ? data->precision : len;
	c = flag_relate(data);
	(data->minus == 1) ? print_nbr(len, data, p) : 0;
	gaps(data->width - spaces, c, data);
	(data->minus == 0) ? print_nbr(len, data, p) : 0;
	free(p);
}

void	ft_print_xupper(t_params *data, va_list ap)
{
	char	*p;
	int		spaces;
	char	c;
	int		len;
	int		i;

	i = 0;
	p = ft_itoa_base(va_arg(ap, unsigned int), 16);
	while (p[i])
	{
		p[i] = ft_toupper((unsigned char)p[i]);
		i++;
	}
	if (*p == '0' && data->precision == 0)
		len = 0;
	else
		len = ft_strlen(p);
	spaces = (data->precision > len) ? data->precision : len;
	c = flag_relate(data);
	(data->minus == 1) ? print_nbr(len, data, p) : 0;
	gaps(data->width - spaces, c, data);
	(data->minus == 0) ? print_nbr(len, data, p) : 0;
	free(p);
}

void	ft_print_p(t_params *data, va_list ap)
{
	char	*p;
	int		spaces;
	char	c;
	int		len;

	p = ft_itoa_base((size_t)va_arg(ap, void *), 16);
	(data->precision >= 0 && data->zero == 1) ? data->zero = 0 : 0;
	len = (*p == '0' && data->precision == 0) ? 0 : ft_strlen(p);
	spaces = (data->precision > len) ? data->precision : len;
	spaces -= len;
	c = (data->zero == 1) ? '0' : ' ';
	if (data->minus == 1)
	{
		ptf_ft_putstr_fd("0x", 1, data);
		checkoptions_gap(spaces, '0', data, 1);
		(len == 0 && *p == '0') ? 0 : ptf_ft_putstr_fd(p, 1, data);
	}
	gaps(data->width - (2 + len), c, data);
	if (data->minus == 0)
	{
		ptf_ft_putstr_fd("0x", 1, data);
		checkoptions_gap(spaces, '0', data, 0);
		(len == 0 && *p == '0') ? 0 : ptf_ft_putstr_fd(p, 1, data);
	}
	free(p);
}
