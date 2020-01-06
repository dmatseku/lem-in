#ifndef LEM_IN_V2_S_NODE_H
# define LEM_IN_V2_S_NODE_H

# include <stdint.h>
# include "../list_link/list_link.h"
# include <stdbool.h>

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
	t_states			state;
}						t_node;

#endif
