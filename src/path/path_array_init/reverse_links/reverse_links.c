#include "../../path.h"

static t_link	*find_need_link(t_list_link *list,
								t_node *first, t_node *second)
{
	while (list)
	{
		if ((list->link->left_node == first && list->link->right_node == second)
		|| (list->link->left_node == second && list->link->right_node == first))
			return (list->link);
		list = list->next;
	}
	return (0);
}

static void		reverse_links_of_one_path(t_path *path, t_graph *graph,
											t_node_data *nodes_data)
{
	uint32_t	i;
	t_link		*current_link;

	i = 1;
	while (i < path->length)
	{
		current_link = find_need_link(graph->nodes[path->path[i]].links,
				graph->nodes + path->path[i - 1], graph->nodes + path->path[i]);
		current_link->dir = RIGHT;
		if (current_link->left_node == graph->nodes + path->path[i - 1])
			current_link->dir = LEFT;
		current_link->weight = -current_link->weight;
		nodes_data[path->path[i]].output = graph->nodes + path->path[i - 1];
		nodes_data[path->path[i - 1]].input = graph->nodes + path->path[i];
		i++;
	}
}

void			reverse_links(t_path_array *paths_array, t_graph *graph,
												t_node_data *nodes_data)
{
	uint32_t i;

	i = 0;
	while (i < paths_array->path_count)
	{
		reverse_links_of_one_path(paths_array->paths + i, graph, nodes_data);
		i++;
	}
}
