#ifndef LEM_IN_V2_LIST_LINK_H
#define LEM_IN_V2_LIST_LINK_H

#include "../structs/s_link.h"

typedef struct	list_link list_link;

struct			list_link
{
	s_link		*link_ptr;
	list_link	*next;
};

list_link		*list_link_create_node(s_link *ptr);

void			list_link_pushback(list_link **list, s_link *ptr);

#endif
