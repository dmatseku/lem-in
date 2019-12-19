#include "list_fd.h"

void	list_fd_pushback(list_fd **list, list_fd *elem)
{
	list_fd *tmp;

	if (!*list)
	{
		*list = elem;
		return;
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
	tmp->next->prev = tmp;
}
