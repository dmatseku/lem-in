#ifndef LEM_IN_V2_FIND_PATHS_H
#define LEM_IN_V2_FIND_PATHS_H

#include "../path.h"

t_path	*find_one_path(t_graph *graph, uint32_t path_index,
									t_node_data *nodes_data);

int32_t	count_the_new_cost(t_path *new_path, t_path_array *paths,
							  t_node_data *data, t_graph *graph);

#endif
