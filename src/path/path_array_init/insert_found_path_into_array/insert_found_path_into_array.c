#include <stdlib.h>
#include "../../path.h"
#include "insert_found_path_into_array.h"

static void	insert_with_loop(t_path_array *path_array, t_graph *graph,
														t_node_data *nodes_data)
{
	uint32_t	*current_path;
	uint32_t	path_nb;
	uint32_t	i;

	path_nb = path_array->path_count - 1;
	current_path = path_array->paths[path_nb].path;
	i = 0;
	nodes_data[graph->start->index].owner = 0;
	while (current_path[i] != graph->end->index)
	{
		if (nodes_data[current_path[i]].owner &&
			nodes_data[current_path[i]].owner != path_nb + 1)
		{
			path_nb = swap_paths(&path_array->paths[path_nb],
					&path_array->paths[nodes_data[current_path[i]].owner - 1],
					i, nodes_data);
			current_path = path_array->paths[path_nb].path;
			i = 0;
		}
		else
			i++;
	}
}

static void	insert_first_path(t_path *path, t_node_data *data)
{
	uint32_t i;

	i = 0;
	while (i < path->length)
		data[path->path[i++]].owner = 1;
}

void		insert_found_path_into_array(t_path new_path,
		t_path_array *path_array, t_graph *graph, t_node_data *nodes_data)
{
	path_array->paths[path_array->path_count++] = new_path;
	if (path_array->path_count > 1)
		insert_with_loop(path_array, graph, nodes_data);
	else
		insert_first_path(path_array->paths, nodes_data);
}
