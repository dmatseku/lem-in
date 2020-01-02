#include "list_node.h"
#include "../../other/other.h"

void			list_node_pushback(t_list_node **list, t_node *ptr)
{
	t_list_node *tmp;

	if (!ft_strcmp(ptr->name, "Res5"))
	{}
	if (!*list)
	{
		*list = list_node_create_node(ptr);
		if (!*list)
			exit_error("Malloc error");
		return;
	}
	tmp = *list;
	if (tmp->node == ptr)
		return ;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->node == ptr)
			return ;
	}
	tmp->next = list_node_create_node(ptr);
	if (!tmp->next)
		exit_error("Malloc error");
}
