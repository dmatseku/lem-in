#ifndef LEM_IN_V2_ANT_DATA_H
# define LEM_IN_V2_ANT_DATA_H

# include <stdint.h>
# include <stdbool.h>

typedef struct	s_ant_data
{
	char		*name;
	uint32_t	position;
	uint32_t	owner_path;
	bool		was_run;
}				t_ant_data;

t_ant_data		*ant_data_create(uint32_t ants);

void			ant_data_delete(t_ant_data *data, uint32_t ants);

#endif
