#ifndef LEM_IN_V2_LIST_FD_H
# define LEM_IN_V2_LIST_FD_H
# define BUFF_SIZE 270

# include <stdlib.h>

typedef struct			s_list_fd
{
	struct s_list_fd	*next;
	struct s_list_fd	*prev;
	char				buff[BUFF_SIZE + 1];
	size_t				last;
	size_t				len;
	int					fd;
}						t_list_fd;

t_list_fd				*list_fd_create_node(int fd);

void					list_fd_pushback(t_list_fd **list, t_list_fd *elem);

void					list_fd_pop(t_list_fd **list, int fd);

t_list_fd				*list_fd_get_elem(t_list_fd **list, int fd);

#endif
