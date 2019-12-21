#include "../path.h"
#include "../../other/other.h"
#include <limits.h>

static void		find_cycle(t_graph *graph, t_path_array *array)
{

}

t_path_array	*find_paths(t_graph *graph)
{
	t_path_array *result;

	if (!(result = create_path_array(graph)))
		exit_error("Malloc error");

}
