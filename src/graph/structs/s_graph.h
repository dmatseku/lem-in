#ifndef LEM_IN_V2_S_GRAPH_H
#define LEM_IN_V2_S_GRAPH_H

#include "s_node.h"

typedef struct			s_graph
{
	t_node				*nodes;
	t_link				*links;
	t_node				*start;
	t_node				*end;
	uint32_t			nodes_length;
	uint32_t			links_length;
	uint16_t			ants;
}						t_graph;

#endif
