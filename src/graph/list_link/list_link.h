#ifndef LEM_IN_V2_LIST_LINK_H
#define LEM_IN_V2_LIST_LINK_H

typedef struct s_link	t_link;

typedef struct			s_list_link
{
	t_link				*link;
	struct s_list_link	*next;
}						t_list_link;

t_list_link				*list_link_create_node(t_link *ptr);

void					list_link_pushback(t_list_link **list, t_link *ptr);

#endif
