#include "../path.h"
#include "../../other/other.h"
#include <limits.h>
#include "find_paths.h"

static void		finding_cycle(t_graph *graph, t_path_array *array,
													t_node_data *nodes_data)
{
	t_path	*current_path;
	int32_t	cost;

	while ((current_path = find_one_path(graph, array->path_count, nodes_data)))
	{
		current_path = find_one_path(graph, array->path_count, nodes_data);
		cost = count_the_new_cost(current_path, array, nodes_data, graph);
	}
}

t_path_array	*find_paths(t_graph *graph)
{
	t_path_array	*result;
	t_node_data		*nodes_data;

	if (!(result = create_path_array(graph)))
		exit_error("Malloc error");
	if (!(nodes_data
			= (t_node_data*)malloc(sizeof(t_node_data) * graph->nodes_length)))
		exit_error("Malloc error");
	ft_memset(nodes_data, 0, sizeof(t_node_data) * graph->nodes_length);
	finding_cycle(graph, result, nodes_data);
	return (result);
}
