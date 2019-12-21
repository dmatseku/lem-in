#include "read_from_input.h"

t_list_string	*read_from_input(int fd)
{
	char			*str;
	t_list_string	*result;

	result = 0;
	while (read_line(&str, fd) > 0)
		list_string_pushback(&result, str);
	return (result);
}
