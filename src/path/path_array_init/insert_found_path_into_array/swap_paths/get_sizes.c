#include "../../../path.h"

uint32_t	get_size_of_fisrt_part(t_path *path, uint32_t elem)
{
	uint32_t	res;

	res = 0;
	while (path->path[res] != elem)
		res++;
	return (res);
}

uint32_t	get_size_of_second_part(t_path *path, uint32_t elem)
{
	uint32_t res;
	uint32_t i;

	i = path->length;
	res = 0;
	while (path->path[--i] != elem)
		res++;
	return (res);
}
