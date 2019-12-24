#include "count_the_new_cost.h"
#include "../../path.h"

uint32_t	get_death_zone(uint32_t const *path, uint32_t length,
							uint32_t first_index, t_node_data *data)
{
	uint32_t const	need_owner = data[path[first_index]].owner;
	uint32_t		res;

	res = 0;
	while (first_index < length && data[path[first_index]].owner == need_owner)
	{
		first_index++;
		res++;
	}
	return (res);
}
