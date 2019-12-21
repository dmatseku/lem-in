#include "../../list_string/list_string.h"
#include "../../other/other.h"
#include "../structs/s_node.h"

t_list_string	*skip_comments(t_list_string *lst)
{
	while (lst && lst->str[0] == '#')
	{
		if (lst->str[1] == '#' && (!ft_strcmp(lst->str, "##start")
								|| !ft_strcmp(lst->str, "##end")))
			return (0);
		lst = lst->next;
	}
	return (lst);
}

t_list_string *skip_comments_and_commands(t_list_string *lst)
{
    while (lst && lst->str[0] == '#')
        lst = lst->next;
    return (lst);
}

t_list_string *skip_comments_check_commands(t_list_string *lst,
												states *start_end)
{
	*start_end = OTHER;
	while (lst && lst->str[0] == '#')
	{
		if (lst->str[1] == '#')
		{
			if (!ft_strcmp(lst->str, "##start"))
			{
				*start_end = START;
				return (lst->next);
			}
			else if (!ft_strcmp(lst->str, "##end"))
			{
				*start_end = END;
				return (lst->next);
			}
		}
		lst = lst->next;
	}
	return (lst);
}

