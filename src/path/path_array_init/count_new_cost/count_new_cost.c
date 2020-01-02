#include "../../path.h"

static uint32_t	get_max_length(t_path_array *paths)
{
	uint32_t res;
	uint32_t i;

	res = 0;
	i = 0;
	while (i < paths->path_count)
	{
		if (res < paths->paths[i].length)
			res = paths->paths[i].length;
		i++;
	}
	return (res - 1);
}

uint32_t		count_new_cost(t_path_array *paths, uint32_t ants)
{
	uint32_t	cost;
	uint32_t	i;

	cost = get_max_length(paths);
	ants -= paths->path_count;
	i = 0;
	while (i < paths->path_count && ants)
	{
		if (paths->paths[i].length - 1 < cost)
		{
			if (ants < (cost - paths->paths[i].length + 1))
				ants = 0;
			else
				ants -= (cost - paths->paths[i].length + 1);
		}
		i++;
	}
	cost += ants / paths->path_count;
	cost += (ants % paths->path_count > 0);
	return (cost);
}
