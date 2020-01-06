#ifndef LEM_IN_V2_SWAP_PATHS_H
# define LEM_IN_V2_SWAP_PATHS_H

# include "../../../path.h"

typedef	struct	s_two_paths_data
{
	uint32_t	first_path_first_part;
	uint32_t	first_path_second_part;
	uint32_t	second_path_first_part;
	uint32_t	second_path_second_part;
}				t_two_paths_data;

uint32_t		get_size_of_fisrt_part(t_path *path, uint32_t elem);

uint32_t		get_size_of_second_part(t_path *path, uint32_t elem);

void			swap_ending(t_two_paths_data data, t_path *path_1,
							t_path *path_2, t_node_data *nodes_data);

#endif
