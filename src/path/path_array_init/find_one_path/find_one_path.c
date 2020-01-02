#include "../../path.h"
#include "stdbool.h"
#include "../../../graph/structs/s_graph.h"
#include "find_one_path.h"
#include "../../../other/other.h"
#include <stdlib.h>

static int32_t	count_of_nodes(t_node *end, t_node_data *nodes_data)
{
	int32_t res;

	res = 1;
	while (end->state != START)
	{
		end = nodes_data[end->index].parent;
		res++;
	}
	return (res);
}

static void		set_indices_in_path(uint32_t *path, uint32_t last,
										t_node *end, t_node_data *nodes_data)
{
	while (last)
	{
		path[--last] = end->index;
		if (last)
			end = nodes_data[end->index].parent;
	}
}

static void		clear_data(t_node_data *nodes_data, uint32_t length,
															uint32_t start)
{
	while (length--)
	{
		nodes_data[length].parent = 0;
		nodes_data[length].cost = INT32_MAX;
		nodes_data[length].is_the_prev_input = false;
	}
	nodes_data[start].cost = 0;
	nodes_data[start].is_the_prev_input = true;
}

bool			find_one_path(t_graph *graph, uint32_t path_index,
							t_node_data *nodes_data, t_path *path)
{
	clear_data(nodes_data, graph->nodes_length, graph->start->index);
	bf_search(graph, nodes_data);
	if (!nodes_data[graph->end->index].parent)
		return (false);
	path->length = count_of_nodes(graph->end, nodes_data);
	path->path = (uint32_t*)malloc(sizeof(uint32_t) * path->length);
	if (!path->path)
		exit_error("Malloc error");
	set_indices_in_path(path->path, path->length, graph->end, nodes_data);
	path->index = path_index;
	return (true);
}
