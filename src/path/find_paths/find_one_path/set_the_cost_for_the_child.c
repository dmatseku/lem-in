#include "../../path.h"
#include "stdbool.h"

static bool	check_cost(t_node *parent, t_node *child, int32_t weight,
												t_node_data *nodes_data)
{
	uint32_t	p_index;
	uint8_t		c_index;

	p_index = parent->index;
	c_index = child->index;
	if (parent->state != END && child->state != START)
	{
		if (!nodes_data[p_index].input || nodes_data[p_index].is_the_prev_input
			|| child == nodes_data[p_index].output)
		{
			if (nodes_data[c_index].cost > nodes_data[p_index].cost + weight)
			{
				return (true);
			}
		}
	}
	return (false);
}

//true if it is possible, else false
bool	set_the_cost_for_the_child(t_node *parent, t_node *child,
									int32_t weight, t_node_data *nodes_data)
{
	uint32_t	p_index;
	uint8_t		c_index;

	p_index = parent->index;
	c_index = child->index;
	if (check_cost(parent, child, weight, nodes_data))
	{
		nodes_data[c_index].is_the_prev_input = false;
		if (parent == nodes_data[c_index].input)
			nodes_data[c_index].is_the_prev_input = true;
		nodes_data[c_index].parent = parent;
		nodes_data[c_index].cost = nodes_data[p_index].cost + weight;
		return (true);
	}
	return (false);
}
