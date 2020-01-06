#include "path.h"
#include "../other/other.h"
#include <limits.h>
#include <string.h>

t_path_array	*path_array_create(t_graph *graph)
{
	uint32_t		size;
	t_path_array	*res;

	size = graph->start->links_count;
	if (graph->end->links_count < size)
		size = graph->end->links_count;
	res = (t_path_array*)malloc(sizeof(t_path_array));
	if (!res)
		return (0);
	res->need_step_cost = UINT32_MAX;
	res->path_count = 0;
	res->paths = (t_path*)malloc(sizeof(t_path) * size);
	if (!res->paths)
		return (0);
	memset(res->paths, 0, sizeof(t_path) * size);
	return (res);
}
