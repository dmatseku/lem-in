#ifndef LEM_IN_V2_FIND_ONE_PATH_H
#define LEM_IN_V2_FIND_ONE_PATH_H

#include "../../../graph/graph.h"

bool	set_the_cost_for_the_child(t_node *parent, t_node *child,
									int32_t weight, t_node_data *nodes_data);

void	bfs_search(t_graph *graph, t_node_data *nodes_data);
#endif
