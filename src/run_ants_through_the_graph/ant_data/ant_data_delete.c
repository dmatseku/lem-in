#include "ant_data.h"
#include <stdlib.h>

void	ant_data_delete(t_ant_data *data, uint32_t ants)
{
	while (ants--)
		free(data[ants].name);
	free(data);
}
