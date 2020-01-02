#ifndef LEM_IN_V2_PATH_ARRAY_INIT_H
#define LEM_IN_V2_PATH_ARRAY_INIT_H

#include "../path.h"

bool		find_one_path(t_graph *graph, uint32_t path_index,
						  t_node_data *nodes_data, t_path *path);

uint32_t	count_new_cost(t_path_array *paths, uint32_t ants);

void		insert_found_path_into_array(t_path new_path,
			t_path_array *path_array, t_graph *graph, t_node_data *nodes_data);

void		reverse_links(t_path_array *paths_array, t_graph *graph,
												t_node_data *nodes_data);
#endif
