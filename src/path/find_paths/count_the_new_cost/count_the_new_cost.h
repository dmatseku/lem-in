#ifndef LEM_IN_V2_COUNT_THE_NEW_COST_H
#define LEM_IN_V2_COUNT_THE_NEW_COST_H

#include <stdint.h>

uint32_t	get_size_of_first_part(uint32_t const *path, uint32_t length,
															uint32_t index);

uint32_t	get_size_of_second_part(uint32_t const *path, uint32_t length,
													uint32_t index);

uint32_t	get_death_zone(uint32_t const *path, uint32_t length,
							uint32_t first_index, t_node_data *data);

#endif
