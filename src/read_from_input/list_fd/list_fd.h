#ifndef LEM_IN_V2_LIST_FD_H
#define LEM_IN_V2_LIST_FD_H
#define BUFF_SIZE 270

#include <stdlib.h>

typedef struct	list_fd list_fd;

struct			list_fd
{
	list_fd		*next;
	list_fd		*prev;
	char		buff[BUFF_SIZE + 1];
	size_t		last;
	size_t		len;
	int			fd;
};

list_fd			*list_fd_create_node(int fd);

void			list_fd_pushback(list_fd **list, list_fd *elem);

void			list_fd_pop(list_fd **list, int fd);

list_fd			*list_fd_get_elem(list_fd **list, int fd);

#endif
