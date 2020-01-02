#include "../manage_flags/manage_flags.h"
#include "path.h"
#include "../other/other.h"
#include <unistd.h>

void path_array_print(t_path_array *path_array, t_graph *graph)
{
	uint32_t i;
	uint32_t j;
	t_path	*current;

	if (!flags[PATHS])
		return ;
	i = 0;
	write(1, "\nFound paths:\n", 14);
	while (i < path_array->path_count)
	{
		write(1, "    ", 4);
		current = path_array->paths + i;
		j = 1;
		write(1, graph->start->name, ft_strlen(graph->start->name));
		while (j < current->length)
		{
			write(1, " -> ", 4);
			write(1, graph->nodes[current->path[j]].name,
					ft_strlen(graph->nodes[current->path[j]].name));
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
