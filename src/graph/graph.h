#ifndef LEM_IN_V2_S_GRAPH_H
#define LEM_IN_V2_GRAPH_H

#include "../list_string/list_string.h"
#include "structs/s_graph.h"
#include "structs/s_link.h"
#include "structs/s_node.h"

t_graph		*graph_create(t_list_string *input);

void		graph_delete(t_graph *del_gr);

#endif
