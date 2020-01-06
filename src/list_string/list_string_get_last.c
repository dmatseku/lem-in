#include "list_string.h"

t_list_string	*list_string_get_last(t_list_string *list)
{
	while (list && list->next)
		list = list->next;
	return (list);
}
