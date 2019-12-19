#include "list_fd.h"
#include "../../../../other/other.h"

list_fd		*list_fd_get_elem(list_fd **list, int fd)
{
	list_fd	*iter;
	list_fd *new;

	iter = *list;
	while (iter->fd != fd)
		iter = iter->next;
	if (iter)
		return (iter);
	new = list_fd_create_node(fd);
	if (!new)
		exit_error("Malloc error");
	list_fd_pushback(list, new);
	return (new);
}
