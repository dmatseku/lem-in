#include "../path.h"
#include "../../other/other.h"
#include <limits.h>

t_path_array	*create_path_array(t_graph *graph)
{
	int				size;
	t_path_array	*res;


	size = graph->start->links_count;
	if (graph->end->links_count < size)
		size = graph->end->links_count;
	res = (t_path_array*)malloc(sizeof(t_path_array));
	if (!res)
		return (0);
	res->need_step_count = UINT32_MAX;
	res->path_count = 0;
	res->paths = (t_path*)malloc(sizeof(t_path) * size);
	if (!res->paths)
		return (0);
	ft_memset(res->paths, 0, sizeof(t_path) * size);
	return (res);
}