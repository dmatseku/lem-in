#include <stdlib.h>
#include "list_string.h"

void	list_string_delete(t_list_string *lst)
{
	t_list_string *del;

	while (lst)
	{
		del = lst;
		lst = lst->next;
		free(del->str);
		free(del);
	}
}
