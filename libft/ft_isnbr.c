//
// Created by Wilton Abomination on 1/22/21.
//

#include "libft.h"

int		ft_isnbr(char *s)
{
	if (s)
	{
		while (*s)
		{
			if (!ft_isdigit(*s))
				return (0);
			s++;
		}
	}
	return (1);
}