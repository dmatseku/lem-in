#include "list_link.h"
#include <stdlib.h>

list_link		*list_link_create_node(s_link *ptr)
{
	list_link *res;

	res = (list_link*)malloc(sizeof(list_link));
	if (!res)
		return (0);
	res->next = 0;
	res->link_ptr = ptr;
	return (res);
}