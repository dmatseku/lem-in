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

static void				set_room(t_node *n, int index, states state,
													char const *room)
{
	char *name;
	int i;

	n->cost = 1;
	n->index = index;
	n->state = state;
	n->links = 0;
	i = 0;
	while (room[i] != ' ')
		i++;
	name = (char*)malloc(sizeof(char) * (i + 1));
	if (!name)
		exit_error("Malloc error");
	name[i] = '\0';
	while (i--)
		name[i] = room[i];
	n->name = name;
}

static t_list_string	*init_rooms(t_list_string *input, t_graph *s_graph)
{
	uint32_t	i;
	states		state;

	i = 0;
	while (i < s_graph->nodes_length)
	{
		input = skip_comments_check_commands(input, &state);
		if ((state == START && s_graph->start)
			|| (state == END && s_graph->end))
			exit_error("Double start or end");
		if ((state == START || state == END) && input->str[0] == '#')
			exit_error("Invalid field after command");
		if (state == START)
			s_graph->start = s_graph->nodes + i;
		else if (state == END)
			s_graph->end = s_graph->nodes + i;
		set_room(s_graph->nodes + i, i, state, input->str);
		input = input->next;
		i++;
	}
	return (input);
}

t_list_string 			*set_nodes(t_list_string *input, t_graph *s_graph)
{
	s_graph->nodes_length = count_the_number_of_rooms(input);
	s_graph->nodes = (t_node*)malloc(sizeof(t_node) * s_graph->nodes_length);
	if (!s_graph->nodes)
		exit_error("Malloc error");
	ft_memset(s_graph->nodes, 0, s_graph->nodes_length);
	return (init_rooms(input, s_graph));
}
