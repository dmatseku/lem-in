#include "list_string.h"
#include <stdlib.h>

t_list_string	*list_string_create_node(char *str)
{
	t_list_string *res;

	res = (t_list_string*)malloc(sizeof(t_list_string));
	if (!res)
		return (0);
	res->next = 0;
	res->str = str;
	return (res);
}
