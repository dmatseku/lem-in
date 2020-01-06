#ifndef LEM_IN_V2_FIND_ONE_PATH_H
# define LEM_IN_V2_FIND_ONE_PATH_H

# include "../../../graph/graph.h"

bool	set_cost_for_child(t_node *node_1, t_node *node_2,
						int32_t weight, t_node_data *nodes_data);

void	bf_search(t_graph *graph, t_node_data *nodes_data);
#endif
