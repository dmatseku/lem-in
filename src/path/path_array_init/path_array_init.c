#include "../path.h"
#include "../../other/other.h"
#include "path_array_init.h"

static inline t_path_array	*create_array(t_graph *graph)
{
	t_path_array	*result;

	if (!(result = path_array_create(graph)))
		exit_error("Malloc error");
	return (result);
}

static t_path_array			*finding_cycle(t_graph *graph,
									t_node_data *nodes_data)
{
	t_path_array	*actual_array;
	t_path_array	*new_array;
	t_path			current_path;
	uint32_t		cost;

	actual_array = create_array(graph);
	new_array = create_array(graph);
	while (find_one_path(graph, actual_array->path_count + 1,
								nodes_data, &current_path))
	{
		insert_found_path_into_array(current_path, new_array, graph,
															nodes_data);
		cost = count_new_cost(new_array, graph->ants);
		if (cost >= actual_array->need_step_cost)
			break;
		new_array->need_step_cost = cost;
		path_array_copy(actual_array, new_array);
		reverse_links(actual_array, graph, nodes_data);
	}
	path_array_delete(new_array);
	return (actual_array);
}

t_path_array				*path_array_init(t_graph *graph)
{
	t_node_data		*nodes_data;
	t_path_array	*res;

	if (!(nodes_data
			= (t_node_data*)malloc(sizeof(t_node_data) * graph->nodes_length)))
		exit_error("Malloc error");
	ft_memset(nodes_data, 0, sizeof(t_node_data) * graph->nodes_length);
	res = finding_cycle(graph, nodes_data);
	free(nodes_data);
	return (res);
}
