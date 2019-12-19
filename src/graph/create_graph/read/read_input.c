#include "../../../list_string/list_string.h"
#include "read.h"

list_string	*input_data;

void		read_from_input(int fd)
{
	char *str;

	input_data = 0;
	while (read_line(&str, fd) > 0)
		list_string_pushback(&input_data, str);
}
