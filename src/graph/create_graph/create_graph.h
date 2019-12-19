#ifndef LEM_IN_V2_CREATE_GRAPH_H
#define LEM_IN_V2_CREATE_GRAPH_H

#include "../../list_string/list_string.h"
#include "../structs/s_graph.h"

extern list_string	*input_data;

list_string			*set_ants(list_string *input, graph *s_graph);

list_string			*skip_comments(list_string *lst);

int					validate_ant(char const * str);

int					validate_room(char const * str);

int					validate_link(char const * str);

#endif
