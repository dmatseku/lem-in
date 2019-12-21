#include "list_node.h"
#include <stdlib.h>

t_list_node		*list_node_create_node(t_node *ptr)
{
	t_list_node *res;

	res = (t_list_node*)malloc(sizeof(t_list_node));
	if (!res)
		return (0);
	res->next = 0;
	res->node = ptr;
	return (res);
}
