#include "list_fd.h"
#include "../../other/other.h"

t_list_fd		*list_fd_get_elem(t_list_fd **list, int fd)
{
	t_list_fd	*iter;
	t_list_fd	*new;

	iter = *list;
	while (iter && iter->fd != fd)
		iter = iter->next;
	if (iter)
		return (iter);
	new = list_fd_create_node(fd);
	if (!new)
		exit_error("Malloc error");
	list_fd_pushback(list, new);
	return (new);
}
