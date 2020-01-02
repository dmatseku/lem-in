#include "ant_data.h"
#include "../../other/other.h"
#include <stdlib.h>

t_ant_data		*ant_data_create(uint32_t ants)
{
	t_ant_data	*res;
	uint32_t	i;
	uint32_t	len;

	if (!(res = (t_ant_data*)malloc(sizeof(t_ant_data) * ants)))
		exit_error("Malloc error");
	i = 0;
	while (i < ants)
	{
		res[i].position = 0;
		res[i].owner_path = 0;
		res[i].was_run = false;
		len = uintlen(i + 1);
		if (!(res[i].name = (char*)malloc(sizeof(char) * (len + 2))))
			exit_error("Malloc error");
		res[i].name[0] = 'L';
		int_to_string(res[i].name + 1, i + 1, len);
		i++;
	}
	return (res);
}
