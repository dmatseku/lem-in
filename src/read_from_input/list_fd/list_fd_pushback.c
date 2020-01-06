#include "list_fd.h"

void	list_fd_pushback(t_list_fd **list, t_list_fd *elem)
{
	t_list_fd *tmp;

	if (!*list)
	{
		*list = elem;
		return ;
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
	tmp->next->prev = tmp;
}
