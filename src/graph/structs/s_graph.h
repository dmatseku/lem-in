#ifndef LEM_IN_V2_S_GRAPH_H
#define LEM_IN_V2_S_GRAPH_H

#include <stdint.h>
#include "s_link.h"
#include "s_node.h"

typedef struct	graph graph;

struct			graph
{
	node		*nodes;
	link		*links;
	node		*start;
	node		*end;
	uint32_t	nodes_length;
	uint32_t	links_length;
	uint16_t	ants;
};

#endif
