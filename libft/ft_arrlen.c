//
// Created by Wilton Abomination on 1/22/21.
//

int ft_arrlen(char **s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}