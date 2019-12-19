#ifndef LEM_IN_V2_S_NODE_H
#define LEM_IN_V2_S_NODE_H

#include "../link_list/link_list.h"

typedef enum	states
{
	START,
	END,
	OTHER
}				states;

typedef struct	s_node node;

struct			s_node
{
	int			index;
	link_list	*links;
	states		state;
};

#endif
