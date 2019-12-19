#include "create_graph.h"
#include "../../other/other.h"

list_string	*set_ants(list_string *input, graph *s_graph)
{
	input = skip_comments(input);

	if (!input || !validate_ant(input->str))
		exit_error("Invalid ants");
	s_graph->ants = ft_atou(input->str);
	return (input->next);
}
