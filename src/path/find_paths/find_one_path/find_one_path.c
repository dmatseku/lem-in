#include "../../path.h"
#include "stdbool.h"
#include "../../../graph/structs/s_graph.h"
#include "find_one_path.h"
#include <stdlib.h>
#include <limits.h>

static int32_t	count_of_nodes(t_node *end, t_node_data *nodes_data)
{
	int32_t res;

	res = 0;
	while (end->state != START)
	{
		end = nodes_data[end->index].parent;
		res++;
	}
	return (res);
}

static void		set_indices_in_the_path(uint32_t *path, uint32_t last,
										t_node *end, t_node_data *nodes_data)
{
	while (end->state != START)
	{
		path[--last] = end->index;
		end = nodes_data[end->index].parent;
	}
}

static void		clear_data(t_node_data *nodes_data, uint32_t length,
															uint32_t start)
{
	while (length--)
	{
		nodes_data->parent = 0;
		nodes_data->cost = INT32_MAX;
		nodes_data->is_the_prev_input = 0;
	}
	nodes_data[start].cost = 0;
}

t_path			*find_one_path(t_graph *graph, uint32_t path_index,
													t_node_data *nodes_data)
{
	t_path *res;

	clear_data(nodes_data, graph->nodes_length, graph->start->index);
	bfs_search(graph, nodes_data);
	if (!nodes_data[graph->end->index].parent)
		return (0);
	res = (t_path*)malloc(sizeof(t_path));
	if (!res)
		return (0);
	res->length = count_of_nodes(graph->end, nodes_data);
	res->path = (uint32_t*)malloc(sizeof(uint32_t) * res->length);
	if (!res->path)
		return (0);
	set_indices_in_the_path(res->path, res->length, graph->end, nodes_data);
	res->index = path_index;
	return (res);
}
