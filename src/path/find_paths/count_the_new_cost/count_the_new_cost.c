#include <stdint.h>
#include <stdlib.h>
#include "../../path.h"
#include "../../../other/other.h"
#include "count_the_new_cost.h"

static uint32_t	*find_the_cost_for_each_paths(t_path *new_path,
					t_path_array *paths, t_node_data *data, t_graph *graph)
{
	uint32_t	current_path;
	uint32_t	i;
	uint32_t	*res;

	res = (uint32_t*)malloc(sizeof(uint32_t) * (paths->path_count + 1));
	if (!res)
		exit_error("Malloc error");
	ft_memset(res, 0, sizeof(uint32_t) * (paths->path_count + 1));
	current_path = paths->path_count;
	i = 0;
	while (new_path->path[i] != graph->end->index)
	{
		if (data[new_path->path[i]].owner)
		{
			if (data[new_path->path[i]].owner != current_path)
			{
				res[current_path] +=
						get_size_of_second_part(
							paths->paths[data[new_path->path[i]].owner].path,
							paths->paths[data[new_path->path[i]].owner].length,
							new_path->path[i]);
				current_path = data[new_path->path[i]].owner;
			}
			i += get_death_zone(new_path->path, new_path->length, i, data);
			res[current_path] = get_size_of_first_part(
									paths->paths[current_path].path,
									paths->paths[current_path].length,
									new_path->path[i - 1]
									);
		}
		else
		{
			i++;
			res[current_path]++;
		}
	}
	return (res);
}

int32_t	count_the_new_cost(t_path *new_path, t_path_array *paths,
										t_node_data *data, t_graph *graph)
{

}
