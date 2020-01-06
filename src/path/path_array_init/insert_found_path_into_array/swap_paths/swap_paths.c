#include "../../../path.h"
#include "swap_paths.h"

static inline void	find_size_of_first_path(t_two_paths_data *data,
				t_path *path_1, t_path *path_2, uint32_t index)
{
	data->first_path_first_part = index + 1;
	data->first_path_second_part = get_size_of_second_part(path_2,
											path_1->path[index]);
}

static inline void	find_size_of_second_path(t_two_paths_data *data,
					t_path *path_1, t_path *path_2, uint32_t index)
{
	data->second_path_first_part = get_size_of_fisrt_part(path_2,
											path_1->path[index]);
	data->second_path_second_part = get_size_of_second_part(path_1,
											path_1->path[index]);
}

static uint32_t		skip_death_zone(t_path *path, uint32_t start_index,
								t_node_data *nodes_data, uint32_t owner)
{
	uint32_t res;

	res = 1;
	start_index++;
	while (nodes_data[path->path[++start_index]].owner == owner)
	{
		nodes_data[path->path[start_index - 1]].owner = 0;
		nodes_data[path->path[start_index - 1]].parent = 0;
		nodes_data[path->path[start_index - 1]].is_the_prev_input = 0;
		nodes_data[path->path[start_index - 1]].cost = 0;
		nodes_data[path->path[start_index - 1]].input = 0;
		nodes_data[path->path[start_index - 1]].output = 0;
		res++;
	}
	return (res);
}

uint32_t			swap_paths(t_path *path_1, t_path *path_2,
			uint32_t start_index, t_node_data *nodes_data)
{
	t_two_paths_data	data;
	uint32_t			death_zone;

	find_size_of_first_path(&data, path_1, path_2, start_index);
	death_zone = skip_death_zone(path_1, start_index, nodes_data,
													path_2->index);
	find_size_of_second_path(&data, path_1, path_2, start_index + death_zone);
	swap_ending(data, path_1, path_2, nodes_data);
	return (path_2->index - 1);
}
