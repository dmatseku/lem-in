#include "../structs/s_graph.h"
#include "read/read.h"
#include "create_graph.h"
#include "../../other/other.h"

graph	*create_graph(int fd)
{
	list_string	*input;
	graph		*result;

	read_from_input(fd);
	if (!(result = (graph*)malloc(sizeof(graph))))
		exit_error("Malloc error");
	ft_memset(result, 0, sizeof(graph));
	input = set_ants(input_data, result);
	input = set_nodes(input, result);
}
