#include <stdlib.h>
#include "path.h"
#include "../other/other.h"

static void	copy_path(t_path *in, t_path *src)
{
	uint32_t i;

	in->length = src->length;
	in->index = src->index;
	free(in->path);
	if (!(in->path = (uint32_t*)malloc(sizeof(uint32_t) * in->length)))
		exit_error("Malloc error");
	i = 0;
	while (i < in->length)
	{
		in->path[i] = src->path[i];
		i++;
	}
}

void		path_array_copy(t_path_array *in, t_path_array *src)
{
	uint32_t i;

	i = 0;
	in->path_count = src->path_count;
	in->need_step_cost = src->need_step_cost;
	while (i < src->path_count)
	{
		copy_path(in->paths + i, src->paths + i);
		i++;
	}
}
