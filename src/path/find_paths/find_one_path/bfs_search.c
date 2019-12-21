#include <stdlib.h>
#include "../../../graph/graph.h"
#include "../../../graph/list_node/list_node.h"
#include "find_one_path.h"

void	check_every_link(t_list_node **next_list, t_node *node)
{
	t_list_link	*current_link;
	t_node		*parent;
	t_node		*child;
	t_direction	direction;

	current_link = node->links;
	while (current_link)
	{
		direction = (current_link->link->left_node == node ? RIGHT : LEFT);
		parent = node;
		child = (current_link->link->left_node);
		if (current_link->link->left_node == node)
			child = current_link->link->right_node;
		if ((current_link->link->dir == direction
				|| current_link->link->dir == TWO)
			&& set_the_cost_for_the_child(parent, child,
												current_link->link->weight))
		{
			list_node_pushback(next_list, child);
		}
		current_link = current_link->next;
	}
}

void	bfs_search(t_graph *graph)
{
	t_list_node	*current_list;
	t_list_node *next_list;
	t_list_node *current_node;

	list_node_pushback(&current_list, graph->start);
	next_list = current_list;
	graph->start->cost = 0;
	graph->start->is_cost_set = true;
	while (next_list)
	{
		next_list = 0;
		while (current_list)
		{
			current_node = current_list;
			current_list = current_list->next;
			free(current_node);
		}
		current_list = next_list;
	}
}
