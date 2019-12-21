#include "../../path.h"
#include "stdbool.h"
#include "../../../graph/structs/s_graph.h"
#include "find_one_path.h"
#include <stdlib.h>

static int32_t		count_of_nodes(t_node *end, t_node *start)
{
	int32_t res;

	res = 0;
	while (end != start)
	{
		end = end->parent;
		res++;
	}
	return (res);
}

static void			set_indices_in_the_path(uint32_t *path, uint32_t last,
											t_node *end, t_node *start)
{
	while (end != start)
	{
		path[--last] = end->index;
		end = end->parent;
	}
}

t_path				*find_one_path(t_graph *graph, uint32_t path_index)
{
	t_path *res;

	bfs_search(graph);
	if (!graph->end->is_cost_set)
		return (0);
	res = (t_path*)malloc(sizeof(t_path));
	if (!res)
		return (0);
	res->length = count_of_nodes(graph->end, graph->start);
	res->path = (uint32_t*)malloc(sizeof(uint32_t) * res->length);
	if (!res->path)
		return (0);
	set_indices_in_the_path(res->path, res->length, graph->end, graph->start);
	res->index = path_index;
	return (res);
}
