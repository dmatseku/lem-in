#include "list_fd.h"
#include "../../../../other/other.h"

list_fd			*list_fd_create_node(int fd)
{
	list_fd *res;

	res = (list_fd*)malloc(sizeof(list_fd));
	if (!res)
		return (0);
	ft_memset(res, 0, sizeof(list_fd));
	res->fd = fd;
	res->last = BUFF_SIZE;
	return (res);
}
