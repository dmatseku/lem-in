#ifndef LEM_IN_V2_LIST_NODE_H
#define LEM_IN_V2_LIST_NODE_H

#include "../structs/s_node.h"

typedef struct			s_list_node
{
	t_node				*node;
	struct s_list_node	*next;
}						t_list_node;

t_list_node				*list_node_create_node(t_node *ptr);

void					list_node_pushback(t_list_node **list, t_node *ptr);

#endif
