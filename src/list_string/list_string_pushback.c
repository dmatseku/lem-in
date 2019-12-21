#include "list_string.h"
#include "../other/other.h"

void list_string_pushback(t_list_string **list, char *str)
{
	t_list_string *tmp;

	if (!*list)
	{
		*list = list_string_create_node(str);
		if (!*list)
			exit_error("Malloc error");
		return;
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = list_string_create_node(str);
	if (!tmp->next)
		exit_error("Malloc error");
}
