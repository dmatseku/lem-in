#ifndef LEM_IN_V2_PATH_H
#define LEM_IN_V2_PATH_H

#include <stdint.h>
#include "../graph/graph.h"

typedef struct	s_node_data
{
	int32_t		cost;
	t_node		*parent;
	t_node		*input;
	t_node		*output;
	bool		is_the_prev_input;
	uint32_t	owner;
}				t_node_data;

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
	uint32_t	need_step_cost;
}				t_path_array;

void			path_array_delete(t_path_array *array);

void			path_array_copy(t_path_array *in, t_path_array *src);

t_path_array	*path_array_create(t_graph *graph);

t_path_array	*path_array_init(t_graph *graph);

void			path_array_print(t_path_array *path_array, t_graph *graph);

void			path_array_print_steps_count(uint32_t steps);

#endif
