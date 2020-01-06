#ifndef LEM_IN_V2_S_LINK_H
# define LEM_IN_V2_S_LINK_H

# include "s_node.h"

typedef enum			e_direction
{
	LEFT,
	RIGHT,
	TWO
}						t_direction;

struct					s_link
{
	t_node				*left_node;
	t_node				*right_node;
	t_direction			dir;
	int32_t				weight;
};

#endif
