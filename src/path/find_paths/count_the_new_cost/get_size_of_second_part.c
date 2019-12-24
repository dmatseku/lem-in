#include "count_the_new_cost.h"

uint32_t	get_size_of_second_part(uint32_t const *path, uint32_t length,
															uint32_t index)
{
	while (length-- && path[length] != index)
		length--;
	return (length);
}
