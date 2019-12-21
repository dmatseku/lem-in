#include <stdlib.h>
#include "../structs/s_node.h"
#include "../structs/s_graph.h"

static void	free_names(t_node *nodes, uint32_t nodes_length)
{
	t_list_link *lst;
	t_list_link *del;

	while (nodes_length--)
	{
		free(nodes[nodes_length].name);
		lst = nodes[nodes_length].links;
		while (lst)
		{
			del = lst;
			lst = lst->next;
			free(del);
		}
	}
}

void		graph_delete(t_graph *del_gr)
{
	free_names(del_gr->nodes, del_gr->nodes_length);
	free(del_gr->nodes);
	free(del_gr->links);
	free(del_gr);
}
