#include "graph_create.h"
#include "../../other/other.h"

t_list_string	*set_ants(t_list_string *input, t_graph *s_graph)
{
	input = skip_comments(input);

	if (!input || !validate_ant(input->str))
		exit_error("Invalid ants");
	s_graph->ants = ft_atou(input->str);
	return (input->next);
}
