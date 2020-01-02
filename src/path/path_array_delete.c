#include <stdlib.h>
#include "path.h"

void		path_array_delete(t_path_array *array)
{
	uint32_t i;

	i = 0;
	while (i < array->path_count)
		free(array->paths[i++].path);
	free(array->paths);
	free(array);
}
