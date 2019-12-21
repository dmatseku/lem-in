#include "graph_create.h"
#include "../../other/other.h"

t_graph	*graph_create(t_list_string *input)
{;
	t_graph			*result;

	if (!(result = (t_graph*)malloc(sizeof(t_graph))))
		exit_error("Malloc error");
	ft_memset(result, 0, sizeof(t_graph));
	input = set_ants(input, result);
	input = set_nodes(input, result);
	set_links(input, result);
	return (result);
}
