#include "../graph/graph.h"
#include "../path/path.h"
#include "ant_data/ant_data.h"
#include "../other/other.h"
#include <unistd.h>

static void print_ant(char *ant_name, char *node_name, bool was_input)
{
	char		*output;
	uint32_t	len;

	len = ft_strlen(ant_name) + ft_strlen(node_name) + 2;
	if (was_input)
		len += 1;
	if (!(output = (char*)malloc(sizeof(char) * len)))
		exit_error("Malloc error");
	ft_memset(output, 0, len);
	if (was_input)
		output[0] = ' ';
	ft_strcat(output, ant_name);
	ft_strcat(output, "-");
	ft_strcat(output, node_name);
	write(1, output, len - 1);
	free(output);
}

static bool keep_walking(t_ant_data *data, t_path *paths,
											t_graph *graph)
{
	uint32_t	ant;
	bool		res;
	uint32_t	owner;
	uint32_t	position;

	res = false;
	ant = 0;
	while (ant < graph->ants && data[ant].was_run)
	{
		if (data[ant].position + 1 != paths[data[ant].owner_path].length)
		{
			owner = data[ant].owner_path;
			data[ant].position++;
			position = data[ant].position;
			print_ant(data[ant].name,
					  graph->nodes[paths[owner].path[position]].name, res);
			res = true;
		}
		ant++;
	}
	return (res);
}

static bool	do_first_steps(t_ant_data *ant_data, t_path_array *paths,
											t_graph *graph, bool was_input)
{
	uint32_t	path;
	uint32_t	ant;
	bool		res;

	path = 0;
	ant = 0;
	res = false;
	while (path < paths->path_count)
	{
		while (ant < graph->ants && ant_data[ant].was_run)
			ant++;
		if (ant == graph->ants)
			break ;
		res = true;
		print_ant(ant_data[ant].name,
				graph->nodes[paths->paths[path].path[1]].name, was_input);
		ant_data[ant].position = 1;
		ant_data[ant].was_run = true;
		ant_data[ant].owner_path = path;
		was_input = true;
		path++;
	}
	return (res);
}

void	run_ants_through_the_graph(t_graph *graph, t_path_array *paths)
{
	t_ant_data	*ant_data;
	bool		res_of_walk;

	ant_data = ant_data_create(graph->ants);
	res_of_walk = false;
	write(1, "\n", 1);
	while (res_of_walk | do_first_steps(ant_data, paths, graph, res_of_walk))
	{
		write(1, "\n", 1);
		res_of_walk = keep_walking(ant_data, paths->paths, graph);
	}
	ant_data_delete(ant_data, graph->ants);
}
