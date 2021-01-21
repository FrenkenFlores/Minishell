
#include "../../minishell.h"

int				is_escape_char(char ch)
{
	if (ch == '$' || ch == '"' || ch == '\'' || ch == '\\' ||
		ch == '>' || ch == '<' || ch == '|' || ch == ';')
		return (1);
	return (0);
}
