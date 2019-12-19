#ifndef LEM_IN_V2_S_NODE_H
#define LEM_IN_V2_S_NODE_H

#include "../list_link/list_link.h"
#include <stdint.h>

typedef enum	states
{
	START,
	END,
	OTHER
}				states;

typedef struct	s_node node;

struct			s_node
{
	uint32_t	index;
	list_link	*links;
	uint32_t	links_count;
	states		state;
	node		*input;
	node		*output;
	int8_t		cost;
	int8_t		is_cost_set;
};

#endif
