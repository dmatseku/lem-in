#include "graph/graph.h"
#include "graph/structs/s_graph.h"
#include "read_from_input/read_from_input.h"
#include "path/path.h"
#include <unistd.h>
#include "manage_flags/manage_flags.h"
#include "other/other.h"
#include "run_ants_through_the_graph/run_ants_through_the_graph.h"
#include "color/color.h"

static void	run_ants_and_print_all_info(t_list_string *input, t_graph *graph,
										   t_path_array	*paths)
{
	t_list_string *last;

	print_color(BLUE);
	list_string_print(input);
	print_color(YELLOW);
	run_ants_through_the_graph(graph, paths);
	if (flags[LAST])
	{
		last = list_string_get_last(input);
		if (last->str[0] == '#')
		{
			write(1, "\n", 1);
			print_color(RED);
			write(1, last->str + 1, ft_strlen(last->str) - 1);
			write(1, "\n", 1);
		}
	}
	print_color(RED);
	path_array_print_steps_count(paths->need_step_cost);
	print_color(MAGENTA);
	path_array_print(paths, graph);
	print_color(GREEN);
	graph_print_nodes_count(graph->nodes_length);
}

bool	print_help(void)
{
	if (!flags[HELP])
		return (false);
	write(1, "Usage:\n"
		"    ./lem-in < *path to file*\n"
		"    cat *path to file* | ./lem-in\n"
		"    ./lem-in *write data in the standard input\n\n"
		"-steps - Print the number of my lines\n"
		"-rooms - Print number of rooms\n"
		"-paths - Print all the path\n"
		"-last - Print last line in file\n"
		"-color - Print with colors\n", 275);
	flags_delete();
	return (true);
}

int main(int ac, char **av)
{
	t_list_string	*input;
	t_graph		*graph;
	t_path_array	*paths;

	manage_flags(ac, av);
	if (print_help())
		return (0);
	input = read_from_input(0);
	graph = graph_create(input);
	paths = path_array_init(graph);
	if (!paths->path_count)
		exit_error("No paths found");
	run_ants_and_print_all_info(input, graph, paths);
	list_string_delete(input);
	graph_delete(graph);
	path_array_delete(paths);
	flags_delete();
	print_color(CLEAR);
	return (0);
}
