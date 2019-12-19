#ifndef LEM_IN_V2_LIST_STRING_H
#define LEM_IN_V2_LIST_STRING_H

typedef struct	list_string list_string;

struct			list_string
{
	char		*str;
	list_string	*next;
};

list_string		*list_string_create_node(char *str);

void			list_string_pushback(list_string **list, char *str);

#endif
