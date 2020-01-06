#include <stdlib.h>
#include "../../../graph/graph.h"
#include "../../../graph/list_node/list_node.h"
#include "../../path.h"
#include "find_one_path.h"
#include <stdio.h>

void	check_every_link(t_list_node **list, t_node *node,
												t_node_data *nodes_data)
{
	t_list_link	*current_link;
	t_node		*child;
	t_direction	direction;

	if (node->state == END)
		return ;
	current_link = node->links;
	while (current_link)
	{
		direction = (current_link->link->left_node == node ? RIGHT : LEFT);
		child = (current_link->link->left_node);
		if (current_link->link->left_node == node)
			child = current_link->link->right_node;
		if ((current_link->link->dir == direction
				|| current_link->link->dir == TWO)
			&& set_cost_for_child(node, child, current_link->link->weight,
																nodes_data))
		{
			list_node_pushback(list, child);
		}
		current_link = current_link->next;
	}
}

void	bf_search(t_graph *graph, t_node_data *nodes_data)
{
	t_list_node	*list;
	t_list_node *current_node;

	list = 0;
	list_node_pushback(&list, graph->start);
	while (list)
	{
		current_node = list;
		list = list->next;
		check_every_link(&list, current_node->node, nodes_data);
		free(current_node);
	}
}
