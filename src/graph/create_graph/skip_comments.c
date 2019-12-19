#include "../../list_string/list_string.h"
#include "../../other/other.h"

list_string	*skip_comments(list_string *lst)
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

