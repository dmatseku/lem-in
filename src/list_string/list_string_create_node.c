#include "list_string.h"
#include <stdlib.h>

list_string	*list_string_create_node(char *str)
{
	list_string *res;

	res = (list_string*)malloc(sizeof(list_string));
	if (!res)
		return (0);
	res->next = 0;
	res->str = str;
	return (res);
}
