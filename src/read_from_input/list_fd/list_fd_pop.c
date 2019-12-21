#include "list_fd.h"

void		list_fd_pop(list_fd **list, int fd)
{
	list_fd *iter;

	iter = *list;
	if (iter->fd == fd)
	{
		if (iter->next)
			iter->next->prev = 0;
		*list = iter->next;
		free(iter);
		return;
	}
	while (iter && iter->fd != fd)
		iter = iter->next;
	if (iter)
	{
		if (iter->prev)
			iter->prev->next = iter->next;
		if (iter->next)
			iter->next->prev = iter->prev;
		free(iter);
	}
}
