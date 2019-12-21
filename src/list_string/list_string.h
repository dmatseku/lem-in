#ifndef LEM_IN_V2_LIST_STRING_H
#define LEM_IN_V2_LIST_STRING_H

typedef struct		s_list_string t_list_string;

struct				s_list_string
{
	char			*str;
	t_list_string	*next;
};

void				list_string_print(t_list_string *lst);

void				list_string_delete(t_list_string *lst);

t_list_string		*list_string_create_node(char *str);

void				list_string_pushback(t_list_string **list, char *str);

#endif
