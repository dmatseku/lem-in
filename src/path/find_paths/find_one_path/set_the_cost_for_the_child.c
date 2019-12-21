#include "../../path.h"
#include "stdbool.h"
#include "../../../graph/list_link/list_link.h"
#include "../../../graph/graph.h"

static bool	check_cost(t_node *parent, t_node *child, int32_t weight)
{
	if (parent->state != END && child != START)
	{
		if (!parent->input || parent->is_the_prev_input
							|| child == parent->output)
		{
			if (!child->is_cost_set || child->cost > parent->cost + weight)
			{
				return (true);
			}
		}
	}
	return (false);
}

bool	set_the_cost_for_the_child(t_node *parent, t_node *child,
												int32_t weight)
{
	if (check_cost(parent, child, weight))
	{
		child->is_the_prev_input = false;
		if (parent == child->input)
			child->is_the_prev_input = true;
		child->parent = parent;
		child->cost = parent->cost + weight;
		child->is_cost_set = true;
		return (true);
	}
	return (false);
}
