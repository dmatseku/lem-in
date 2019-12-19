#include "create_graph.h"
#include "../../other/other.h"

list_string	*set_ants(list_string *input, graph *s_graph)
{
	input = skip_comments(input);

	if (!input || !validate_ant(input->str))
		return (0);
	s_graph->ants = ft_atou(input->str);
}
