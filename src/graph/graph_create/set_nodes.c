#include "graph_create.h"
#include "../../other/other.h"

static int  			count_the_number_of_rooms(t_list_string *input)
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

static void				set_room(t_node *node, int index, t_states state,
													char const *room)
{
	char *name;
	int i;

	node->index = index;
	node->state = state;
	node->links = 0;
	node->links_count = 0;
	i = 0;
	while (room[i] != ' ')
		i++;
	name = (char*)malloc(sizeof(char) * (i + 1));
	if (!name)
		exit_error("Malloc error");
	name[i] = '\0';
	while (i--)
		name[i] = room[i];
	node->name = name;
}

static t_list_string	*init_rooms(t_list_string *input, t_graph *graph)
{
	uint32_t	i;
	t_states	state;

	i = 0;
	while (i < graph->nodes_length)
	{
		input = skip_comments_check_commands(input, &state);
		if ((state == START && graph->start)
			|| (state == END && graph->end))
			exit_error("Double start or end");
		if ((state == START || state == END) && input->str[0] == '#')
			exit_error("Invalid field after command");
		if (state == START)
			graph->start = graph->nodes + i;
		else if (state == END)
			graph->end = graph->nodes + i;
		set_room(graph->nodes + i, i, state, input->str);
		input = input->next;
		i++;
	}
	return (input);
}

t_list_string 			*set_nodes(t_list_string *input, t_graph *graph)
{
	t_list_string	*res;

	graph->nodes_length = count_the_number_of_rooms(input);
	graph->nodes = (t_node*)malloc(sizeof(t_node) * graph->nodes_length);
	if (!graph->nodes)
		exit_error("Malloc error");
	ft_memset(graph->nodes, 0, graph->nodes_length);
	res = init_rooms(input, graph);
	if (!graph->start || !graph->end)
		exit_error("Start or end not found");
	return (res);
}
