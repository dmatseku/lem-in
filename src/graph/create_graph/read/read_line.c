#include "read.h"
#include "../../../other/other.h"
#include "list_fd/list_fd.h"
#include <unistd.h>

static size_t	str_len(const char *str, size_t i, size_t len)
{
	size_t res;

	res = i;
	while (res < len && str[res] != '\n')
		res++;
	return (res - i);
}

static void		realoc_str(char **str, char *tmp, size_t size, size_t size_all)
{
	char	*prev;
	size_t	i;

	prev = *str;
	if (!(*str = (char*)malloc(sizeof(char) * ((size_all) + size + 1))))
		exit(0);
	i = 0;
	while (i < size_all)
	{
		(*str)[i] = prev[i];
		i++;
	}
	if (prev)
		free(prev);
	(*str)[i] = 0;
	ft_strncat(*str, tmp, size);
}

static void		next_step(list_fd *elem, char **str)
{
	size_t	size;
	size_t	size_all;

	size_all = 0;
	while (1)
	{
		size = str_len(elem->buff, elem->last, elem->len);
		realoc_str(str, elem->buff + elem->last, size, size_all);
		size_all += size;
		elem->last += size;
		if (elem->last < elem->len)
			break;
		ft_memset(elem->buff, 0, BUFF_SIZE);
		elem->len = read(elem->fd, elem->buff, BUFF_SIZE);
		elem->last = 0;
		if (elem->len <= 0)
			break;
	}
}

static int		create_line(list_fd *elem, char **str)
{
	if (elem->last < elem->len)
		elem->last++;
	if (elem->last == elem->len)
	{
		ft_memset(elem->buff, 0, BUFF_SIZE);
		if ((elem->len = read(elem->fd, elem->buff, BUFF_SIZE)) <= 0)
			return (elem->len);
		elem->last = 0;
	}
	next_step(elem, str);
	return (1);
}

int				read_line(char **str, int fd)
{
	static list_fd	*fds = 0;
	list_fd			*elem;
	int				res;

	if (fd < 0)
		return (-1);
	elem = list_fd_get_elem(&fds, fd);
	*str = 0;
	res = create_line(elem, str);
	if (!(*str))
	{
		list_fd_pop(&fds, fd);
		return (0);
	}
	if (res < 0)
	{
		if (*str)
			free(str);
		*str = 0;
		return (-1);
	}
	return (1);
}
