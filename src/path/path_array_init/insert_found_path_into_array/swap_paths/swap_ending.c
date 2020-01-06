#include "swap_paths.h"
#include "../../../../other/other.h"
#include <stdlib.h>

static t_path	create_first_path(t_path *path_1, t_path *path_2,
					t_two_paths_data data, t_node_data *nodes_data)
{
	t_path		res;
	uint32_t	res_i;
	uint32_t	path_i;

	res.length = data.first_path_first_part + data.first_path_second_part;
	if (!(res.path = (uint32_t*)malloc(sizeof(uint32_t) * res.length)))
		exit_error("Malloc error");
	res.index = path_1->index;
	res_i = 0;
	path_i = 0;
	while (path_i < data.first_path_first_part)
	{
		res.path[res_i] = path_1->path[path_i++];
		nodes_data[res.path[res_i++]].owner = res.index;
	}
	path_i = path_2->length - data.first_path_second_part;
	while (path_i < path_2->length)
	{
		res.path[res_i] = path_2->path[path_i++];
		nodes_data[res.path[res_i++]].owner = res.index;
	}
	return (res);
}

static t_path	create_second_path(t_path *path_1, t_path *path_2,
					t_two_paths_data data, t_node_data *nodes_data)
{
	t_path		res;
	uint32_t	res_i;
	uint32_t	path_i;

	res.length = data.second_path_first_part + data.second_path_second_part;
	if (!(res.path = (uint32_t*)malloc(sizeof(uint32_t) * res.length)))
		exit_error("Malloc error");
	res.index = path_2->index;
	res_i = 0;
	path_i = 0;
	while (path_i < data.second_path_first_part)
	{
		res.path[res_i] = path_2->path[path_i++];
		nodes_data[res.path[res_i++]].owner = res.index;
	}
	path_i = path_1->length - data.second_path_second_part;
	while (path_i < path_1->length)
	{
		res.path[res_i] = path_1->path[path_i++];
		nodes_data[res.path[res_i++]].owner = res.index;
	}
	return (res);
}

void			swap_ending(t_two_paths_data data, t_path *path_1,
							t_path *path_2, t_node_data *nodes_data)
{
	t_path res_1;
	t_path res_2;

	res_1 = create_first_path(path_1, path_2, data, nodes_data);
	res_2 = create_second_path(path_1, path_2, data, nodes_data);
	free(path_1->path);
	free(path_2->path);
	*path_1 = res_1;
	*path_2 = res_2;
}
