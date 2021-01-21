/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wabomina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 00:18:52 by wabomina          #+#    #+#             */
/*   Updated: 2020/07/23 23:02:36 by wabomina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_pers(t_params *data)
{
	int		i;
	char	c;
	int		spaces;

	i = data->i;
	while ((ft_strchr(SPECIFIER, data->s[i + 1]) && data->s[i]) &&
	!(ft_isalpha(data->s[i])))
		i++;
	if ((data->s[i] == '%') || (data->s[data->i] == '%'))
	{
		c = ((data->zero == 1) && (data->minus) == 0) ? '0' : ' ';
		spaces = (1 >= data->width) ? 0 : data->width - 1;
		checkoptions_gap(spaces, c, data, 0);
		write(1, "%%", 1);
		data->length++;
		checkoptions_gap(spaces, c, data, 1);
	}
	else
	{
		write(1, "%%", 1);
		data->length++;
	}
}
