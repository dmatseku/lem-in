#ifndef LEM_IN_V2_S_LINK_H
#define LEM_IN_V2_S_LINK_H

#include "s_node.h"

typedef enum	direction
{
	left,
	right,
	two
}				direction;

typedef struct	s_link link;

struct			s_link
{
	s_node		*left_node;
	s_node		*right_node;
	direction	dir;
	int			weight;
};

#endif
