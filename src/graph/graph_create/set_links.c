#include "graph_create.h"
#include "../../other/other.h"
#include "../structs/s_link.h"

static int  count_the_number_of_links(t_list_string *input)
{
	int res;

	res = 0;
	input = skip_comments(input);
	if (!input)
		exit_error("No links");
	while (input)
	{
		if (!validate_link(input->str))
			exit_error("Invalid link");
		res++;
		input = skip_comments(input->next);
	}
	return (res);
}

static t_node	*find_node(char *name, t_graph *s_graph)
{
	uint32_t	i;
	t_node		*nodes;
	uint32_t	nodes_length;

	i = 0;
	nodes = s_graph->nodes;
	nodes_length = s_graph->nodes_length;
	while (i < nodes_length && ft_strcmp(nodes[i].name, name))
		i++;
	if (i < nodes_length)
		return (nodes + i);
	return (0);
}

static void	set_link(t_link *l, t_node *node_one, t_node *node_two)
{
	l->dir = TWO;
	l->weight = 1;
	if (!node_one || !node_two)
		exit_error("Undefined node");
	l->left_node = node_one;
	l->right_node = node_two;
	list_link_pushback(&(node_one->links), l);
	list_link_pushback(&(node_two->links), l);
	node_one->links_count++;
	node_two->links_count++;
}

static void	init_links(t_list_string *input, t_graph *s_graph)
{
	uint32_t	i;
	uint32_t	delim_nb;
	t_node		*node_one;
	t_node		*node_two;

	i = 0;
	while (i < s_graph->links_length)
	{
		input = skip_comments(input);
		delim_nb = 0;
		while (input->str[delim_nb] != '-')
			delim_nb++;
		input->str[delim_nb] = '\0';
		node_one = find_node(input->str, s_graph);
		node_two = find_node(input->str + delim_nb + 1, s_graph);
		input->str[delim_nb] = '-';
		set_link(s_graph->links + i, node_one, node_two);
		input = input->next;
		i++;
	}
}

void		set_links(t_list_string *input, t_graph *s_graph)
{
	s_graph->links_length = count_the_number_of_links(input);
	s_graph->links = (t_link*)malloc(sizeof(t_link) * s_graph->links_length);
	if (!s_graph->links)
		exit_error("Malloc error");
	ft_memset(s_graph->links, 0, s_graph->nodes_length);
	init_links(input, s_graph);
}
