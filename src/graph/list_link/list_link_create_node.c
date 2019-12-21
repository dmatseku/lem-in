#include "list_link.h"
#include <stdlib.h>

t_list_link		*list_link_create_node(t_link *ptr)
{
	t_list_link *res;

	res = (t_list_link*)malloc(sizeof(t_list_link));
	if (!res)
		return (0);
	res->next = 0;
	res->link = ptr;
	return (res);
}
