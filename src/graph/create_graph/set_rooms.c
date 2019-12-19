#include "create_graph.h"
#include "../../other/other.h"

static int  		count_the_number_of_rooms(list_string *input)
{
    int res;

    res = 0;
    input = skip_comments_and_commands(input);
    while (input && !validate_link(input->str))
    {
        if (!validate_room(input->str))
        	exit_error("Invalid room");
        res++;
		input = skip_comments_and_commands(input->next);
    }
    if (!input)
    	exit_error("No links");
	return (res);
}

static list_string	*init_rooms(list_string *input, graph *s_graph)
{
	uint32_t	i;
	states		state;

	i = 0;
	while (i < s_graph->nodes_length)
	{
		skip_comments_check_commands(input, &state);
		if ((state == START && s_graph->start)
			|| (state == END && s_graph->end))
			exit_error("Double start or end");
		if (state == START)
			s_graph->start = s_graph->nodes + i;
		else if (state == END)
			s_graph->end = s_graph->nodes + i;
		s_graph->nodes[i].cost = 1;
		s_graph->nodes[i].index = i;
		s_graph->nodes[i].state = state;
		input = input->next;
		i++;
	}
	return (input);
}

list_string 		*set_nodes(list_string *input, graph *s_graph)
{
	s_graph->nodes_length = count_the_number_of_rooms(input);

	s_graph->nodes = (node*)malloc(sizeof(node) * s_graph->nodes_length);
	if (!s_graph->nodes)
		exit_error("Malloc error");
	ft_memset(s_graph->nodes, 0, s_graph->nodes_length);
	return (init_rooms(input, s_graph));
}
