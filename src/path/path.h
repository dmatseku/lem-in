#ifndef LEM_IN_V2_PATH_H
#define LEM_IN_V2_PATH_H

#include <stdint.h>
#include "../../graph/graph.h"

typedef struct	s_path
{
	uint32_t	*path;
	uint32_t	length;
	uint32_t	index;
}				t_path;

typedef struct	s_path_array
{
	t_path		*paths;
	uint32_t	path_count;
	uint32_t	need_step_count;
}				t_path_array;

t_path_array	*create_path_array(t_graph *graph);

t_path_array	*find_paths(t_graph *graph);

#endif
