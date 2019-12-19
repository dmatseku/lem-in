#include "list_link.h"
#include "../../other/other.h"

void			list_link_pushback(list_link **list, s_link *ptr)
{
	list_link *tmp;

	if (!*list)
	{
		*list = list_link_create_node(ptr);
		if (!*list)
			exit_error("Malloc error");
		return;
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = list_link_create_node(ptr);
	if (!tmp->next)
		exit_error("Malloc error");
}
