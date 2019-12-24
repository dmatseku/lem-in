#include "count_the_new_cost.h"

uint32_t	get_size_of_first_part(uint32_t const *path, uint32_t length,
												  			uint32_t index)
{
	uint32_t res;

	res = 0;
	while (res < length && path[res] != index)
		res++;
	return (res);
}
