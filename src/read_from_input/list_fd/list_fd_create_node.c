#include "list_fd.h"
#include "../../other/other.h"

t_list_fd			*list_fd_create_node(int fd)
{
	t_list_fd *res;

	res = (t_list_fd*)malloc(sizeof(t_list_fd));
	if (!res)
		return (0);
	ft_memset(res, 0, sizeof(t_list_fd));
	res->fd = fd;
	res->last = BUFF_SIZE;
	return (res);
}
