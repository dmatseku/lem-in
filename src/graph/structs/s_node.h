#ifndef LEM_IN_V2_S_NODE_H
#define LEM_IN_V2_S_NODE_H

#include <stdint.h>
#include "../list_link/list_link.h"
#include <stdbool.h>

typedef enum			e_states
{
	START,
	END,
	OTHER
}						t_states;

typedef struct			s_node
{
	char				*name;
	uint32_t			index;
	t_list_link			*links;
	uint32_t			links_count;
	struct s_node		*input;
	struct s_node		*output;
	bool				is_the_prev_input;
	uint32_t			owner;
	t_states			state;
	int8_t				cost;
	bool				is_cost_set;
	struct s_node		*parent;
}						t_node;

#endif
