#include <stdlib.h>
#include "../../path.h"
#include "insert_found_path_into_array.h"

static inline void	insert_path_in_array(t_path *new_path, t_path_array *array)
{
	array->paths[array->path_count++] = *new_path;
	free(new_path);
}

static uint32_t		get_new_path(t_path *first, t_path *second, uint32_t i,
												t_node_data *data)
{
	uint32_t	new_nb;

	new_nb = data[first->path[i]].owner;
	swap_paths(first, second, i, data);
	return  (new_nb);
}

void				insert_found_path_into_array(t_path *new_path,
		t_path_array *path_array, t_graph *graph, t_node_data *data)
{
	uint32_t	*current_path;
	uint32_t	path_nb;
	uint32_t	i;

	insert_path_in_array(new_path, path_array);
	path_nb = path_array->path_count - 1;
	current_path = path_array->paths[path_nb].path;
	i = 0;
	while (current_path[i] != graph->end->index)
	{
		while (current_path[i] != graph->end->index)
		{
			if (data[current_path[i]].owner &&
				data[current_path[i]].owner != path_nb)
			{
				path_nb = get_new_path(&path_array->paths[path_nb],
						&path_array->paths[current_path[i]], i, data);
				current_path = path_array->paths[path_nb].path;
				i = 0;
				break;
			}
			i++;
		}
	}
}
