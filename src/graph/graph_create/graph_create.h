#ifndef LEM_IN_V2_GRAPH_CREATE_H
#define LEM_IN_V2_GRAPH_CREATE_H

#include "../../list_string/list_string.h"
#include "../structs/s_node.h"
#include "../structs/s_graph.h"

extern t_list_string	*input_data;

t_list_string			*set_ants(t_list_string *input, t_graph *s_graph);

t_list_string 			*set_nodes(t_list_string *input, t_graph *s_graph);

void					set_links(t_list_string *input, t_graph *s_graph);

t_list_string			*skip_comments(t_list_string *lst);

t_list_string			*skip_comments_and_commands(t_list_string *lst);

t_list_string			*skip_comments_check_commands(t_list_string *lst,
													states *start_end);

int						validate_ant(char const * str);

int						validate_room(char const * str);

int						validate_link(char const * str);

#endif
